#include <iostream>
#include <cstdlib>
#include <random>

int main()
{
    srand(13);
    setlocale(LC_ALL, "RU");
    int n = 1 + rand() % 101;
    int d;

    std::cout << "Вы играте в игру *Угадай число*. Компьютер загадал случайное число от 0 до 100, попробуйте его угадать. У вас 5 попыток!\n";

    for (int i = 1; i < 8; i++) {
        if (i <= 5) {
            std::cin >> d;
            if (d == n) {
                std::cout << "Поздравляю! Вы угадали\n Хотите начать сначала? (1 - ДА)\n";
                std::cin >> i;
                if (i != 1) {
                    system("pause");
                    return 0;
                }
                else {
                    i = 0;
                    n = 1 + rand() % 101;
                }
            }
            if (d != n && i == 5) i = 6;
            else {
                if (d > n) std::cout << "Загаданное число меньше\n";
                else std::cout << "Загаданное число больше\n";
            }
        }
        else {
            std::cout << "Вы проиграли. Загаданное число: " << n << "\n" << "Хотите начать сначала? (1 - ДА)\n";
            std::cin >> i;
            if (i != 1) {
                system("pause");
                return 0;
            }
            else {
                i = 0;
                n = 1 + rand() % 101;
            }
        }

    }
}