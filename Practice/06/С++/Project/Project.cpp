#include <iostream>

int main()
{
    setlocale(LC_ALL, "RU");

    double a;
    double b;
    double c;
    double D;
    double x;
    double x1;
    double x2;

    std::cout << "Введите 3 любых вещественных числа для нахождения корней уравнения: \n";
    std::cin >> a >> b >> c;

    D = (pow(b, 2)) - 4 * a * c;

    if (D < 0) {
        std::cout << "Дискриминант меньше 0 - корней нет\n";

        system("pause");
    }
    else {
        if (a == 0) {

            if (b == 0 && c == 0 ) std::cout << "Решением уравнения может быть любое число\n";
            else if (b == 0 && c != 0) std::cout << "Уравнение не имеет решения\n";
            else if (b != 0 && c == 0) std::cout << "x = 0\n";
       
            else {
                x = -c / b;
                std::cout << "x = " << x << std::endl;
            }
        }

        else {
            x1 = (-b - sqrt(D)) / (2 * a);
            x2 = (-b + sqrt(D)) / (2 * a);
            if (c == 0 && b != 0)
            {
                x = -(b / a);
                if (x < 0) {
                    std::cout << "Корней нет" << std::endl;
                }
                else {
                    std::cout << "x1 = 0" << std::endl;
                    std::cout << "x2 = " << x << std::endl;
                }


            }
            else {
                if (x1 == x2) {
                    x = x1;
                    if (x == 0) std::cout << "Решением уравнения может быть любое число\n";
                    else std::cout << "x = " << x << std::endl;
                }
                else std::cout << "x1 = " << x1 << "\nx2 = " << x2 << std::endl;
            }
        }
        system("pause");
          }
    }