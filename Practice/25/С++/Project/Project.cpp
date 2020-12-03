#include <iostream>
#include <vector>
#include <random>

std::vector<int> BozoSort(std::vector<int> Num, bool big = true);

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> Num(n);
    std::vector<int> Res;
    for (int i = 0; i < n; i++) {
        std::cin >> Num[i];
    }
    Res = BozoSort(Num);
    for (int i = 0; i < Res.size(); i++) {
        std::cout << Res[i] << " ";
    }
}

std::vector<int> BozoSort(std::vector<int> Num, bool big) {
    int b = 0;
    int n = rand() % Num.size();
    int tempN, temp;
    while (true)
    {
        if (big == true) {
            for (int i = 0; i < int(Num.size() - 1); i++) {
                if (Num[i] > Num[i + 1]) b += 1;
            }
            tempN = n;
            temp = Num[n];
            n = rand() % Num.size();
            Num[tempN] = Num[n];
            Num[n] = temp;

            if (b == Num.size()) {
                return Num;
            }
        }
    }
}