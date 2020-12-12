#include <iostream>
#include <httplib.h>
#include <json.hpp>
#include <string>

using namespace httplib;
using json = nlohmann::json;

void Get_Session(const Request& req, Response& res) {
    std::string str = u8R"(
    {
      "response": {
        "text": "Здравствуйте! Я помогу вам с покупками.",
        "tts": "Здравствуйте! Я помогу вам с покупками.",
        "buttons": [
            {
                "title": "Молчать",
                "payload": {"Silence": "True"},
                "hide": true
            }
        ],
        "end_session": false
      },
      "version": "1.0"
    })";
    res.set_content(str, "text/json; charset=UTF-8");
    std::cout << res.body;
}

int main() {
    Server svr;                            // Создаём сервер (пока-что не запущен)
    svr.Post("/", Get_Session);           // Вызвать функцию gen_response на post запрос
    std::cout << "Start server... OK\n"; // cout использовать нельзя
    svr.listen("localhost", 3000);         // Запускаем сервер на localhost и порту 1234
}