#include <iostream>

int main()
{
    setlocale(LC_ALL, "RU");

    float a;
    int c = 0;
    int i;

    std::cout << "Введите целое число больше 1: ";
    std::cin >> a;
    if ((int)a == a) {
        if (a == 1 || a == 0) std::cout << "Неверно введенно число\n";
        else if (a == 2) std::cout << "Простое\n";
        else {
            for (i = 2; i < a; i++)
            {
                if ((int)a % i == 0) { c = 1; i = a; };
            }

            if (c == 1) std::cout << "Составное\n";
            else std::cout << "Простое\n";
        }
    }
    else std::cout << "Необходимо вводить целое число!\n";
}