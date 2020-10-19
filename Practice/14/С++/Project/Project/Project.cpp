#include <iostream>

int main()
{
    setlocale(LC_ALL, "RU");
    int n, i, res;

    std::cout << "Введите целое число: ";
    std::cin >> n;
    
    if (n == 0 || n == 1) std::cout << 0 << std::endl;
    else {
        res = 0;
        for (i = 0; i <= n; i++) {
            if (sqrt(i) == (int)sqrt(i)) res += 1;
        }

        std::cout << res << std::endl;
    }
    system("pause");
}
