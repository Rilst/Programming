#include <iostream>
#include <map>
#include <vector>

void print_factorization(unsigned int n);

int main()
{
    setlocale(LC_ALL, "RU");

    int N;
    std::cout << "Введите целое число больше 1: ";
    std::cin >> N;
    print_factorization(N);
}

void print_factorization(unsigned int n) {
    std::map <int, int> Res;
    std::vector<int> K;
    int D = 0;
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0) {
            D++;
            if (n / i != 1) {
                K.push_back(i);
                if (D > 0) {
                    n = n / i;
                    i = 1;
                    D = 0;
                    continue;
                }
            }
            else K.push_back(i);
        }
    }
    
    for (auto i : K) Res[i]++;

    int r = 0;
    for (auto i : Res) {
        if (int(Res.size()) > 1) {
            if (i.second != 1) std::cout << i.first << "^" << i.second;
            if (r == 0) {
                std::cout << i.first;
                r++;
                continue;
            }
            if(r > 0) std::cout << "*" << i.first;
        }
        else {
            if (i.second != 1) std::cout << i.first << "^" << i.second;
            else std::cout << i.first;
        }

    }
}