#include <iostream>

int main()
{
    setlocale(LC_ALL, "RU");
    double a;
    int b;
    int i;
    double c;

    std::cout << "Введите число: \n";
    std::cin >> a;
    std::cout << "Введите необходимую степень числа: \n";
    std::cin >> b;
        c = a;
        for (i = 1; i < b; i++)
        {
            c = c * a;
        }
        std::cout << c;
}