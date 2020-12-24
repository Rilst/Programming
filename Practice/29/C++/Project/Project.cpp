#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <random>
#include <ctime>

using namespace std;

struct Student
{
    string name;
    int group;
    map<std::string, int> exams;
};

std::ostream& operator<<(std::ostream& out, vector<Student> studs)
{
    string outs = "+------------+-------+------+------+------+------+\n";
    map<std::string, int>::iterator EX;

    out << outs;
    out << "| Name       | Group | Math | Phys | Hist | Prog |\n";
    for (int i = 0; i < (int)studs.size(); i++) {
        out << outs;
        out << "|" << std::setw(12) << studs.at(i).name << "|" << std::setw(7) << studs.at(i).group << "|";
        for (EX = studs.at(i).exams.begin(); EX != studs.at(i).exams.end(); EX++)
        {
            out << std::setw(6) << EX->second << "|";
        }
        out << "\n";
    }
    out << outs;
    return out;
}

bool operator<(Student stud1, Student stud2)
{
    if (stud1.name < stud2.name) {
        return true;
    }
    else {
        return false;
    }
}

bool operator>(Student stud1, Student stud2)
{
    if (stud1.name > stud2.name) {
        return true;
    }
    else {
        return false;
    }
}


template <typename T>
std::vector<T> BozoSort(std::vector<T> Num, bool small = true) {
    while (true)
    {
        int n1 = 0 + rand() % int(Num.size());
        int n2 = 0 + rand() % int(Num.size());
        if (n1 != n2) std::swap(Num[n1], Num[n2]);
        else continue;
       // std::cout << Num;
        if (small == true) {
            int res = 0;
            for (int i = 0; i < (int(Num.size()) - 1); i++) {
                if (Num[i] < Num[i + 1]) res++;
                else break;
                if (res == int(Num.size() - 1)) {
                    return Num;
                }
            }
        }
        else {
            int res = 0;
            for (int i = 0; i < (int(Num.size()) - 1); i++) {
                if (Num[i] > Num[i + 1]) res++;
                else break;
                if (res == int(Num.size() - 1)) {
                    return Num;
                }
            }
        }
    }
}

int main()
{
    string stringExam[] = { "mathematics", "physics", "history", "programming" };
    string stringNames[] = { "Ivanov P", "Petrov D", "Sidorov F" , "Smirnov A", "Jukov D", "Volkov M", "Dmitrov K", "Putin V", "Savelev M", "Koshelev V" };

    Student S;
    vector<Student> studs;

    for (int i = 0; i < 10; i++) studs.push_back(S);

    srand(time(NULL));

    for (int i = 0; i < (int)studs.size(); i++)
    {
        studs.at(i).name = stringNames[i];
        studs.at(i).group = 1 + rand() % 9;
        for (int j = 0; j < 4; j++) {
            studs.at(i).exams[stringExam[j]] = 2 + rand() % 4;
        }
    }

    vector<Student> bufST;
    int added = -1;
    for (int i = 0; i < (int)studs.size(); i++) {
        for (int j = 0; j < 4; j++) {
            if (studs.at(i).exams[stringExam[j]] == 2) {
                if (added != i)
                    bufST.push_back(studs.at(i));
                added = i;
            }
        }
    }

    if (bufST.size() == 0) cout << "Not found\n";
    else {
        int irand = rand() % bufST.size();
        vector<Student> ST = BozoSort(bufST);
        cout << studs;
        cout << "\n";
        cout << ST;
        cout << "\n";
        cout << "Expulsion\n\n";
        bufST = {};
        bufST.push_back(ST.at(irand));
        cout << bufST;
    }
    
}