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

json GetMain(json req) {
    json State;
    State["Silence"] = false;
    State["Check"] = json::array();
    State["Mode"] = "Main";

    std::string STR = u8"Здравствуйте! Я помогу вам с покупками.";

    json Btns;
    if (req["state"]["session"]["Silence"] == false) {
        Btns[0]["title"] = u8"Молчать";
        Btns[0]["payload"]["Silence"] = true;
    }
    else if (req["state"]["session"]["Silence"] == true) {
        Btns[0]["title"] = u8"Говорить";
        Btns[0]["payload"]["Silence"] = false;
    }

    Btns[1]["title"] = u8"Помощь";
    Btns[1]["payload"]["Mode"] = "Help";

    json ActiveBtns;
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

   /* State["Silence"] = req["state"]["session"]["Silence"];
    State["Check"] = req["state"]["session"]["Check"];
    State["Mode"] = req["state"]["session"]["Mode"];*/

    if (req["state"]["session"]["Silence"] == true || req["request"]["payload"]["Silence"] == true) {
        State["Silence"] = true;
        STR = u8"Молчу, молчу";
        return Create(STR, State, false, Btns);
    }
    else if (req["state"]["session"]["Silence"] == false || req["request"]["payload"]["Silence"] == false) {
        State["Silence"] = false;
        STR = u8"Хорошо";
        return Create(STR, State, false, Btns);
    }

    if (req["session"]["new"] == false) {
            if (req["request"]["payload"]["Mode"] == "Help" || req["state"]["session"]["Mode"] == "Help") {
                State["Mode"] = "Help";

                STR = u8"Корзина. Поможет организовать покупки. \nО чём рассказать подробнее?";

                if (req["request"]["payload"]["Help"] == "Add") {
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
                return Create(STR, State, false, ActiveBtns);
            }

            else if (req["request"]["payload"]["Mode"] == "Main" || req["state"]["session"]["Mode"] == "Main") {
                
                State["Mode"] = "Main";
                std::vector<std::string> BUF = GetCommand(req["request"]["nlu"]["tokens"]);

                if (BUF[0] == u8"добавить" && BUF[1] == u8"в" && BUF[2] == u8"корзину") {
                    State["Check"].push_back({ {"item", BUF[3]}, {"price", BUF[4] } });
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
                    if (State["Check"].empty() == true) {
                        STR = u8"Корзина пуста!";
                    }
                    else if (State["Check"].empty() == false) {
                        std::stringstream str;
                        for (int i = 0; i < State["Check"].size(); i++) {
                            str << State["Check"][i]["item"] << " " << State["Check"][i]["price"] << " рублей" << "\n";
                        }
                        STR = str.str();
                    }
                }
                else if (BUF.size() == 1 && BUF[0] == u8"сумма") {
                    int sum = 0;
                    for (int i = 0; i < State["Check"].size(); i++) {
                        sum += int(State["Check"][i]["price"]);
                    }
                    STR = "Сумма всех товаров в корзине: " + sum;
                }
               /* else if (BUF.size() == 2 && BUF[0] == u8"покупка" && BUF[1] == u8"завершена") {

                }*/
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


int main() {
    Server svr;                            
    svr.Post("/", Get_Session);           
    std::cout << "Start server... OK\n";
    svr.listen("localhost", 3000);         
}