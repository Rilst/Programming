#include <iostream>
#include <json.hpp>
#include <fstream>
#include <string>
#include <map>

using json = nlohmann::json;
int main()
{
    std::ifstream File("in.json");
    nlohmann::json Jstr;
    nlohmann::json Jstr2;
    File >> Jstr;

    std::map<int, int> Buf;
    int UserID;
    bool TaskComp;
  
    for (int i = 0; i < Jstr.size(); i++) {

        UserID = Jstr[i]["userId"];
        int bufId = UserID;

        TaskComp = Jstr[i]["completed"];

        if (TaskComp == true) {
           Buf[UserID] += 1;
        }
    }

    for (auto[userId, complete]: Buf) {
        Jstr2.push_back({ {"userId", userId},  {"task_completed", complete } });

    }

    std::ofstream OutFile("out.json");
    OutFile << Jstr2 << std::endl;
}