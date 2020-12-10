#include <iostream>
#include <vector>
#include <random>

std::vector<int> BozoSort(std::vector<int> Num, bool small = true);
std::vector<int> BozoSort(std::vector<std::vector<int>> Num, bool small = true);
std::vector<int> BozoSort(int a, int b, int c, bool small = true);
void VectorPrnt(std::vector<int> Num);

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> Num(n);
    std::vector<int> Res;
    for (int i = 0; i < n; i++) {
        std::cin >> Num[i];
    }

    std::vector<std::vector<int>> ARR;
    std::vector<int> buf;
    if (n % (int)sqrt(n) == 0) {
        for (int i = 0; i < n; i++) {
            buf.push_back(Num[i]);
            if (((i + 1) % int(sqrt(n))) == 0) {
                ARR.push_back(buf);
                buf.resize(0);
            }
        }
    }

    VectorPrnt(BozoSort(Num));
    VectorPrnt(BozoSort(Num, false));

    VectorPrnt(BozoSort(ARR));
    VectorPrnt(BozoSort(ARR, false));

    VectorPrnt(BozoSort(Num[0], Num[1], Num[2]));
    VectorPrnt(BozoSort(Num[0], Num[1], Num[2], false));
}

void VectorPrnt(std::vector<int> Num) {
    for (auto i = Num.begin(); i < Num.end(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << "\n";
}

std::vector<int> BozoSort(std::vector<int> Num, bool small) {
    while (true)
    {
        int n1 = 0 + rand() % int(Num.size());
        int n2 = 0 + rand() % int(Num.size());
        if (n1 != n2) std::swap(Num[n1], Num[n2]);
        else continue;
        if (small == true) {
            int res = 0;
            for (int i = 0; i < (int(Num.size())-1); i++) {
                if (Num[i] < Num[i + 1]) res++;
                else break;
                if (res == int(Num.size()-1)) {
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

std::vector<int> BozoSort(std::vector<std::vector<int>> Num, bool small) {

    std::vector<int> buf;
    
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

std::vector<int> BozoSort(int a, int b, int c, bool small) {
    std::vector<int> buf;
    buf.push_back(a);
    buf.push_back(b);
    buf.push_back(c);

    if (small == true) buf = BozoSort(buf, true);
    else buf = BozoSort(buf, false);

    return buf;
}