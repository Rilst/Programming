#include <iostream>

using namespace std;
int main()
{
    setlocale(LC_ALL, "RU");
    double X0;
    double V0;
    double t;
    double X;
    const double a = 9.8;

    std::cout << "Введите значения для X0, V0 , t: "; std::cin >> X0 >> V0 >> t;

    X = X0 + V0 * t - ((a * t * t) / 2);

    std::cout << "Результат вычислений: " << X << endl;

    system("pause");
}