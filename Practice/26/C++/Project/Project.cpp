#include <iostream>
#include <vector>
#include <string>

template <typename T>
std::vector<T> BozoSort(std::vector<T> Num, bool small = true) {
    while (true)
    {
        int n1 = 0 + rand() % int(Num.size());
        int n2 = 0 + rand() % int(Num.size());
        if (n1 != n2) std::swap(Num[n1], Num[n2]);
        else continue;
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
template <typename T>
std::vector<T> BozoSort(std::vector<std::vector<T>> Num, bool small = true) {

    std::vector<T> buf;

    for (int i = 0; i < int(Num.size()); i++) {
        for (int j = 0; j < int(Num.size()); j++) {
            buf.push_back(Num[i][j]);
        }
    }
    if (small == true) {
        buf = BozoSort(buf, true);
    }
    else {
        buf = BozoSort(buf, false);
    }
    return buf;
}
template <typename T>
std::vector<T> BozoSort(T a, T b, T c, bool small = true) {
    std::vector<T> buf;
    buf.push_back(a);
    buf.push_back(b);
    buf.push_back(c);

    if (small == true) buf = BozoSort(buf, true);
    else buf = BozoSort(buf, false);

    return buf;
}
template <typename T>
void VectorPrnt(std::vector<T> Num) {
    for (auto i = Num.begin(); i < Num.end(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << "\n";
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<double> Num(n);
    std::vector<double> Res;
    for (int i = 0; i < n; i++) {
        std::cin >> Num[i];
    }

    std::vector<std::vector<double>> ARR;
    std::vector<double> buf;
    if (n % (int)sqrt(n) == 0) {
        for (int i = 0; i < n; i++) {
            buf.push_back(Num[i]);
            if (((i + 1) % int(sqrt(n))) == 0) {
                ARR.push_back(buf);
                buf.resize(0);
            }
        }
    }

    VectorPrnt(BozoSort(Num, true));
    VectorPrnt(BozoSort(Num, false));

    VectorPrnt(BozoSort(ARR));
    VectorPrnt(BozoSort(ARR, false));

    VectorPrnt(BozoSort(Num[0], Num[1], Num[2]));
    VectorPrnt(BozoSort(Num[0], Num[1], Num[2], false));


    int n1;
    std::cin >> n1;
    std::vector<std::string> Num1(n1);
    std::vector<std::string> Res1;
    for (int i = 0; i < n1; i++) {
        std::cin >> Num1[i];
    }

    std::vector<std::vector<std::string>> ARR1;
    std::vector<std::string> buf1;
    if (n % (int)sqrt(n1) == 0) {
        for (int i = 0; i < n1; i++) {
            buf1.push_back(Num1[i]);
            if (((i + 1) % int(sqrt(n1))) == 0) {
                ARR1.push_back(buf1);
                buf1.resize(0);
            }
        }
    }

    VectorPrnt(BozoSort(Num1, true));
    VectorPrnt(BozoSort(Num1, false));

    VectorPrnt(BozoSort(ARR1));
    VectorPrnt(BozoSort(ARR1, false));

    VectorPrnt(BozoSort(Num1[0], Num1[1], Num1[2]));
    VectorPrnt(BozoSort(Num1[0], Num1[1], Num1[2], false));

}