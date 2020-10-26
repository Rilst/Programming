#include <iostream>
#include <cstring>

int main()
{
    setlocale(LC_ALL, "RU");
    int n, d = 4, s = 0, check = 0;
    char bilet[10] = {""};
    char buf[5] = { "" };
    
    std::cout << "Введите количество билетов: ";
    std::cin >> n;
    std::cout << "Введите номера билетов: ";

    for (int i = 0; i < n; i++) {
        std::cin >> bilet;
        if (strlen(bilet) == 9) {
            while (d <= 8) {
                buf[s] = bilet[d];
                s++;
                d++;
            }

            if ((bilet[0] == 'a') && (atoi(buf) == 55661)) {
                std::cout << bilet << "\n";
                check = 1;
            }
        }
        else {
            std::cout << "Неверно введен билет №" << i+1 << "!\n";
        }
    }
    if (check == 0) std::cout << -1 << '\n';
    system("pause");
    return 0;
}
