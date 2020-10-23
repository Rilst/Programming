#include <iostream>

int main()
{
    setlocale(LC_ALL, "RU");
    int a;
    int i;
    int b;
    std::cout << "Введите целое число для нахождения его факториала\n";
    std::cin >> a;
    b = 1;
        if (a < 0) std::cout << "У отрицательного числа нет факториала!\n";
        else if (a == 1 || a == 0) std::cout << 1 << std::endl;
        else {
            for (i = 1; i <= a; i++) {
                b = b * i;
            }
            std::cout << b;
       }
}
