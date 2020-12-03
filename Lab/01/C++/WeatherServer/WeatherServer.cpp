#include <iostream>
#include <json.hpp>
#include <httplib.h>
#include <iomanip>
#include <string>
#include <fstream>

using namespace httplib;
using namespace nlohmann;
using namespace std;

string GetWeather() {
    Client Web("http://api.openweathermap.org");
    auto res = Web.Get("/data/2.5/onecall?lat=44.95212&lon=34.10242&units=metric&exclude=minutely,daily,alerts,current&lang=ru&appid=f9644bd2dc049e034c102c9b65ccff2b");
    if (res) {
        if (res->status == 200) {
            return res->body;
        }
        else {
            return 0;
        }
    }
    else {
        return 0;
    }
}
string GetTime() {
    Client Web("http://worldtimeapi.org");
    auto res = Web.Get("/api/timezone/Europe/Simferopol");
    if (res) {
        if (res->status == 200) {
            return (res->body);
        }
        else {
            return 0;
        }
    }
    else {
        return 0;
    }
}

int main()
{
    json raw = json::parse(GetWeather()); // Получаем json погоды
    int BufTime = 0;
    int BufTime2 = 0;
    json RES;

    ifstream File("widget_template.html"); // Шаблон виджета
    string str;
    getline(File, str, '\0'); // Читаем шаблон в строку

    Server Weather;  // стартуем сервер
    Weather.Get("/raw", [&](const httplib::Request&, httplib::Response& res) { // При открытие /raw
        json time = json::parse(GetTime()); // Получаем json времени
        if (int(time["unixtime"]) < BufTime);    // Чтобы не проходить каждый раз по циклу
        else {
            for (int i = 0; i < raw["hourly"].size(); i++) {
                if (int(time["unixtime"]) < int(raw["hourly"][i]["dt"])) { // Сравниваем время
                    RES.push_back({ {"Temperature", raw["hourly"][i]["temp"]},  {"Weather", raw["hourly"][i]["weather"][0]["description"] } }); // создаем конечный json
                    BufTime = raw["hourly"][i]["dt"]; // кэшируем отдельно время
                    break;
                }
                else {
                    raw = json::parse(GetWeather());     // Если в кэше устарело
                    i = 0;
                }
            }
        }
        res.set_content(RES.dump(), "text/json");   // отдаем итоговый json
        });
    Weather.Get("/", [&](const httplib::Request&, httplib::Response& res) { // При открытие корня
        json time = json::parse(GetTime());// Получаем json времени
        if (int(time["unixtime"]) < BufTime2); // Чтобы не проходить каждый раз по циклу
        else {
            for (int i = 0; i < raw["hourly"].size(); i++) {
                if (int(time["unixtime"]) < int(raw["hourly"][i]["dt"])) { // Сравниваем время

                    str.replace(str.find("{hourly[i].temp}"), size("{hourly[i].temp}") - 1, to_string(int(round(raw["hourly"][i]["temp"].get<float>())))); // Находим в строке первую встречу с временем, заменяем на элемент из json
                    str.replace(str.find("{hourly[i].temp}", size("{hourly[i].temp}")), size("{hourly[i].temp}") - 1, to_string(int(round(raw["hourly"][i]["temp"].get<float>())))); // Находим в строке вторую встречу с временем, заменяем на элемент из json
                    str.replace(str.find("{hourly[i].weather[0].description}"), size("{hourly[i].weather[0].description}") - 1, raw["hourly"][i]["weather"][0]["description"].get<string>()); // Аналогично предыдущему
                    str.replace(str.find("{hourly[i].weather[0].icon}"), size("{hourly[i].weather[0].icon}") - 1, raw["hourly"][i]["weather"][0]["icon"].get<string>()); // Аналогично предыдущему

                    BufTime2 = raw["hourly"][i]["dt"]; // кэшируем время
                    break;
                }
                else {
                    raw = json::parse(GetWeather()); // если устарел кэш
                    i = 0;
                }
            }
        }
        res.set_content(str, "text/html"); // отдаем измененный шаблон
        });
    std::cout << "Start server... OK\n";
    Weather.listen("localhost", 3000); // слушаем локалку на 3000 порте

}