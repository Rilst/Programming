#include <iostream>

int main()
{
    setlocale(LC_ALL, "RU");

    int h1, m1, h2, m2, p1, p2;
    char Symbol1, Symbol2;

    std::cout << "Введите время 1: ";
    std::cin >> h1 >> Symbol1 >> m1;
    std::cout << "Введите время 2: ";
    std::cin >> h2 >> Symbol2 >> m2;

    if (Symbol1 == ':' && Symbol2 == ':' && h1 >= 0 && h2 >= 0 && m1 >= 0 && m2 >= 0) {

        p1 = (h1 * 60) + m1;
        p2 = (h2 * 60) + m2;

        if (abs(p1 - p2) <= 15) std::cout << "Встреча состоится\n";
        else std::cout << "Встреча не состоится\n";
    }
    else std::cout << "Неверный ввод";
    
    system("pause");
}
