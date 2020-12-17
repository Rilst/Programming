#include <iostream>
#include <httplib.h>
#include <json.hpp>
#include <string>
#include <iomanip>
#include <fstream>

using namespace httplib;
using json = nlohmann::json;


json Create(std::string str, json state, bool session, json buttons) {
    json Responce;
    Responce["response"]["text"] = str;
    if (state["Silence"] == false)
        Responce["response"]["tts"] = str;
    Responce["response"]["buttons"] = buttons;
    Responce["response"]["end_session"] = session;
    Responce["version"] = "1.0";
    Responce["session_state"] = state;
   
    return Responce;
}

std::vector<std::string> GetCommand(json token) {
    std::vector<std::string> Res;
    for (auto i : token) {
        Res.push_back(i);
    }
    return Res;
}

std::string replace(std::string str, std::string source, std::string get) {
    int start = str.find(source);
    return str.replace(start, source.length(), get);
}

json GetMain(json req) {
    json State;
    State["Silence"] = false;
    State["Check"] = json::array();
    State["Mode"] = "Main";

    std::string STR = u8"Здравствуйте! Я помогу вам с покупками.";

    json Btns = json::array();
    Btns[0]["title"] = u8"Молчать";
    Btns[1]["title"] = u8"Помощь";
    Btns[1]["payload"]["Mode"] = "Help";

    json ActiveBtns = json::array();
    ActiveBtns[0]["title"] = u8"Добавить в корзину";
    ActiveBtns[0]["payload"]["Help"] = "Add";
    ActiveBtns[1]["title"] = u8"Очистить корзину";
    ActiveBtns[1]["payload"]["Help"] = "Clear";
    ActiveBtns[2]["title"] = u8"Удалить из корзины";
    ActiveBtns[2]["payload"]["Help"] = "Del";
    ActiveBtns[3]["title"] = u8"Что в корзине";
    ActiveBtns[3]["payload"]["Help"] = "What";
    ActiveBtns[4]["title"] = u8"Сумма";
    ActiveBtns[4]["payload"]["Help"] = "Sum";
    ActiveBtns[5]["title"] = u8"Покупка завершена";
    ActiveBtns[5]["payload"]["Help"] = "End";
    ActiveBtns[6]["title"] = u8"Выйти из помощи";
    ActiveBtns[6]["payload"]["Help"] = "EndHelp";



    if (req["session"]["new"] == true) {
        return Create(STR, State, false, Btns);
    }


    State["Silence"] = req["state"]["session"]["Silence"];
    State["Check"] = req["state"]["session"]["Check"];
    State["Mode"] = req["state"]["session"]["Mode"];

    if (State["Silence"] == false) Btns[0]["title"] = u8"Молчать";
    else if (State["Silence"] == true) Btns[0]["title"] = u8"Говорить";

    if (req["session"]["new"] == false) {
            std::vector<std::string> BUF1 = GetCommand(req["request"]["nlu"]["tokens"]);
            if (BUF1[0] == u8"помощь" && BUF1.size() == 1) State["Mode"] = "Help";

            if (req["request"]["payload"]["Mode"] == "Help" || State["Mode"] == "Help") {
                
                State["Mode"] = "Help";
                STR = u8"Корзина. Поможет организовать покупки. \nО чём рассказать подробнее?";

                if (BUF1[0] == u8"помощь" && BUF1.size() == 1) STR = u8"Корзина. Поможет организовать покупки. \nО чём рассказать подробнее?";

                else if (req["request"]["payload"]["Help"] == "Add") {
                    STR = u8"Команда добавить в корзину, добавляет указанный вами товар к вам в корзину. \nО чём рассказать еще?";
                }
                else if (req["request"]["payload"]["Help"] == "Clear") {
                    STR = u8"Команда очистить корзину, удаляет все товары из корзины. \nО чём рассказать еще?";
                }
                else if (req["request"]["payload"]["Help"] == "Del") {
                    STR = u8"Команда Удалить из корзины, удаляет указанный вами товар из корзины. \nО чём рассказать еще?";
                }
                else if (req["request"]["payload"]["Help"] == "What") {
                    STR = u8"Команда что в корзине, выводит все товары имеюзиеся в корзине. \nО чём рассказать еще?";
                }
                else if (req["request"]["payload"]["Help"] == "Sum") {
                    STR = u8"Команда сумма, выводит суммарную стоимость всех товаров. \nО чём рассказать еще?";
                }
                else if (req["request"]["payload"]["Help"] == "End") {
                    STR = u8"Команда покупка завершена, завершает покупку. \nО чём рассказать еще?";
                }
                else if (req["request"]["payload"]["Help"] == "EndHelp") {
                    STR = u8"Обращайся ещё!";
                    State["Mode"] = "Main";
                    return Create(STR, State, false, Btns);
                }
                else if (req["request"]["payload"]["Mode"] != "Help") STR = u8"Неизвестная команда";
                return Create(STR, State, false, ActiveBtns);
            }

            else if (req["request"]["payload"]["Mode"] == "Main" || req["state"]["session"]["Mode"] == "Main") {
                
                State["Mode"] = "Main";
                std::vector<std::string> BUF = GetCommand(req["request"]["nlu"]["tokens"]);

                if (BUF[0] == u8"добавить" && BUF[1] == u8"в" && BUF[2] == u8"корзину") {
                    int Start = req["request"]["nlu"]["entities"][0]["tokens"]["start"];
                    std::vector<std::string> RESULT = {};
                    std::string RESSTR = "";
                    for (int i = Start - 1; i > 0; --i) {
                        if (BUF[i] != u8"корзину") {
                            RESULT.insert(RESULT.begin(), BUF[i]);
                        }
                        else break;
                    }
                    for (auto i : RESULT) {
                        RESSTR += i + u8" ";
                    }
                    State["Check"].push_back({ {"item", RESSTR}, {"price", req["request"]["nlu"]["entities"][0]["value"] } });
                    STR = u8"ОК";
                }
                else if (BUF[0] == u8"удалить" && BUF[1] == u8"из" && BUF[2] == u8"корзины") {
                    bool OK = false;
                    for (int i = 0; i < State["Check"].size(); i++) {
                        if (State["Check"][i]["item"] == BUF[3]) {
                            State["Check"].erase(i);
                            OK = true;
                        }
                    }
                    if (OK == true) STR = u8"ОК";
                    else STR = u8"Такого предмета нет в корзине!";
                }
                else if (BUF[0] == u8"очистить" && BUF[1] == u8"корзину") {
                    State["Check"].clear();
                    STR = u8"Корзина пуста!";
                }
                else if (BUF[0] == u8"что" && BUF[1] == u8"в" && BUF[2] == u8"корзине") {
                    if (State["Check"].size() <= 0) {
                        STR = u8"Корзина пуста!";
                    }
                    else if (State["Check"].size() > 0) {
                        std::stringstream str;
                        for (int i = 0; i < State["Check"].size(); i++){
                            str << std::string(State["Check"][i]["item"]) << u8" " << std::string(State["Check"][i]["price"]) << u8" рублей" << "\n";
                        }
                        STR = str.str();
                    }
                }
                else if (BUF.size() == 1 && BUF[0] == u8"сумма") {
                    int sum = 0;
                    std::string num;
                    for (int i = 0; i < State["Check"].size(); i++) {
                        num = State["Check"][i]["price"];
                        sum += atoi(num.c_str());
                    }
                    STR = u8"Сумма всех товаров в корзине: " + std::to_string(sum) + u8" рублей";
                }
                else if (BUF.size() == 2 && BUF[0] == u8"покупка" && BUF[1] == u8"завершена") {

                    STR = u8"Заходите ещё";
                    if (State["Check"].size() > 0) {
                        std::ifstream jsnout("webhooks.json");

                        json Check;

                        Check["check"] = State["Check"];
                        if (req["session"]["user"]["user_id"] == nullptr) {
                            Check["user_id"] = "anonymous";
                            //Check.push_back("{\"user_id\": \"anonymous\"}"_json);
                        }
                        else if (req["session"]["user"]["user_id"] != nullptr) {
                            Check["user_id"] = req["session"]["user"]["user_id"];
                        }

                        json JArr;
                        JArr["WebHooks"] = json::array();

                        if (jsnout) {
                            json j = json::parse(jsnout);
                            for (int i = 0; i < j["WebHooks"].size(); i++) {
                                JArr["WebHooks"].push_back(j["WebHooks"][i]);
                            }
                            jsnout.close();
                        }


                        for (int i = 0; i < JArr["WebHooks"].size(); i++) {
                            std::string addr = JArr["WebHooks"][i];
                            Client cli(addr.c_str());
                            std::stringstream ss;
                            std::stringstream ss2;
                            ss << std::setw(2) << Check;
                            std::string strstate = ss.str();
                            auto res = cli.Post("/", strstate, "application/json");
                        }
                    }
                    return Create(STR, State, true, nullptr);
                }
                else if (BUF.size() == 1 && BUF[0] == u8"молчать") {
                    State["Silence"] = true;
                    Btns[0]["title"] = u8"Говорить";
                    STR = u8"Молчу, молчу";
                }
                else if (BUF.size() == 1 && BUF[0] == u8"говорить") {
                    State["Silence"] = false;
                    Btns[0]["title"] = u8"Молчать";
                    STR = u8"Хорошо";
                }
                else STR = u8"Неизвестная команда";



                return Create(STR, State, false, Btns);
            }
        }
}

void Get_Session(const Request& req, Response& res) {
    json REQ = json::parse(req.body);
    std::stringstream str;
    str << std::setw(2) << GetMain(REQ) << std::endl;
    res.set_content(str.str(), "text/json; charset=UTF-8");
}

void Get_Template(const Request& req, Response& res) {
    std::ifstream ifstr("temp.html");
    std::string temp;
    std::getline(ifstr, temp, '\0');
    ifstr.close();


    std::ifstream iftempl("template.html");
    std::string templated;
    std::getline(iftempl, templated, '\0');
    iftempl.close();

    std::string data = "";

    std::ifstream jsnout("webhooks.json");
    
    json JArr;
    JArr["WebHooks"] = json::array();

    if (jsnout) {
        json j = json::parse(jsnout);
        for (int i = 0; i < j["WebHooks"].size(); i++) {
            JArr["WebHooks"].push_back(j["WebHooks"][i]);
        }
        jsnout.close();
    }
   
    for (int i = 0; i < JArr["WebHooks"].size(); i++) {
        std::string tempM = temp;
        tempM.replace(tempM.find("Webhook URL"), std::size("Webhook URL") - 1, JArr["WebHooks"][i]);
        tempM.replace(tempM.find("Webhook URL"), std::size("Webhook URL") - 1, JArr["WebHooks"][i]);
        data += tempM + "\n";
    }
    std::string tempP = templated;
    tempP.replace(tempP.find("{webhooks_list}"), std::size("{webhooks_list}"), data);

    if (req.method == "POST") {
        if (req.has_param("del")) {
            std::string value = req.get_param_value("del");
            for (int i = 0; i < JArr["WebHooks"].size(); i++) {
                if (JArr["WebHooks"][i] == value) {
                    JArr["WebHooks"].erase(JArr["WebHooks"].begin() + i);
                }
            }
            std::stringstream sd;
            sd << std::setw(2) << JArr;

            std::ofstream kj("webhooks.json");
            kj << sd.str() << std::endl;
            kj.close();
        }
        if (req.has_param("set")) {
            std::string value = req.get_param_value("set");
            JArr["WebHooks"].push_back(value);
            std::stringstream sd;
            sd << std::setw(2) << JArr;

            std::ofstream kj("webhooks.json");
            kj << sd.str() << std::endl;
            kj.close();
        }
        res.set_redirect("#");
    }

    res.set_content(tempP, "text/html");
}

int main() {
    Server svr;                            
    svr.Post("/", Get_Session);      
    svr.Post("/webhooks", Get_Template);
    svr.Get("/webhooks", Get_Template);
    std::cout << "Start server... OK\n";
    svr.listen("localhost", 3000);         
}