#include <iostream>

int main()
{
    setlocale(LC_ALL, "RU");
    double a;
    char b;
    double c;
    std::cout << "Введите арифметическое выражение : ";
    if (std::cin >> a >> b >> c) {
        if (b == '+' || b == '-' || b == '*' || b == '/')
        {
            if (b == '*')   std::cout << a * c << "\n";
            if (b == '+')   std::cout << a + c << "\n";
            if (b == '-')   std::cout << a - c << "\n";
            if (b == '/') {
                if (c == 0) std::cout << "Деление на 0 невозможно\n";
                else std::cout << a / c << "\n";
            }

        }
        else std::cout << "Неверно указан знак операции\n";
        system("pause");
    }
    else {
        std::cout << "Неверно указанны числовые значения\n";
        system("pause");
    }
    
    





}


