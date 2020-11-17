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
   json raw = json::parse(GetWeather());
   int BufTime = 0;
   int BufTime2 = 0;
   json RES;

   ifstream File("widget_template.html"); // Шаблон виджета
   string str;
   getline(File, str, '\0');

   Server Weather;
   Weather.Get("/raw", [&](const httplib::Request&, httplib::Response& res) { // При открытие /raw
       json time = json::parse(GetTime());
       if (int(time["unixtime"]) < BufTime);    // Чтобы не проходить каждый раз 48 раз по циклу
       else {
           for (int i = 0; i < raw["hourly"].size(); i++) {
               if (int(time["unixtime"]) < int(raw["hourly"][i]["dt"])) {
                   RES.push_back({ {"Temperature", raw["hourly"][i]["temp"]},  {"Weather", raw["hourly"][i]["weather"][0]["description"] } }); // кидаем json
                   BufTime = raw["hourly"][i]["dt"];
                   break;
               }
               else {
                   raw = json::parse(GetWeather());     // Если в кэше устарело
                   i = 0;
               }
           }
       }
        res.set_content(RES.dump(), "text/json");
        });
   Weather.Get("/", [&](const httplib::Request&, httplib::Response& res) {
       json time = json::parse(GetTime());
       if (int(time["unixtime"]) < BufTime2);
       else {
           for (int i = 0; i < raw["hourly"].size(); i++) {
               if (int(time["unixtime"]) < int(raw["hourly"][i]["dt"])) {

                   str.replace(str.find("{hourly[i].temp}"), size("{hourly[i].temp}")-1, to_string(int(round(raw["hourly"][i]["temp"].get<float>()))));
                   str.replace(str.find("{hourly[i].temp}", size("{hourly[i].temp}")), size("{hourly[i].temp}") - 1, to_string(int(round(raw["hourly"][i]["temp"].get<float>()))));
                   str.replace(str.find("{hourly[i].weather[0].description}"), size("{hourly[i].weather[0].description}") - 1, raw["hourly"][i]["weather"][0]["description"].get<string>());
                   str.replace(str.find("{hourly[i].weather[0].icon}"), size("{hourly[i].weather[0].icon}") - 1, raw["hourly"][i]["weather"][0]["icon"].get<string>());
                  
                   BufTime2 = raw["hourly"][i]["dt"];
                   break;
               }
               else {
                   raw = json::parse(GetWeather());
                   i = 0;
               }
           }
       }
       res.set_content(str, "text/html");
       });
   std::cout << "Start server... OK\n";
   Weather.listen("localhost", 3000);

}
