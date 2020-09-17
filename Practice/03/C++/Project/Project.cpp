#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int A1;
    int A2;
    double B1;
    double B2;
    std::cout << "Введите значение переменной Int(1), больше 0: "; std::cin >> A1;
    std::cout << "Введите значение переменной Double(1), больше 0: "; std::cin >> B1;
    std::cout << "Введите значение переменной Int(2), больше 0: "; std::cin >> A2;
    std::cout << "Введите значение переменной Double(2), больше 0: "; std::cin >> B2;
    std::cout << "Результат сложения Int(1) + Int(2): "<< A1 + A2 << endl;
    std::cout << "Результат разности Int(1) - Int(2): " << A1 - A2 << endl;
    std::cout << "Результат умножения Int(1) * Int(2): " << A1 * A2 << endl;
    std::cout << "Результат деления Int(1) / Int(2): " << A1 / A2 << endl;
    std::cout << "=================================================" << endl;
    std::cout << "Результат сложения Int(1) + Double(1): " << A1 + B1 << endl;
    std::cout << "Результат разности Int(1) - Double(1): " << A1 - B1 << endl;
    std::cout << "Результат умножения Int(1) * Double(1): " << A1 * B1 << endl;
    std::cout << "Результат деления Int(1) / Double(1): " << A1 / B1 << endl;
    std::cout << "=================================================" << endl;
    std::cout << "Результат сложения Double(1) + Int(1): " << B1 + A1 << endl;
    std::cout << "Результат разности Double(1) - Int(1): " << B1 - A1 << endl;
    std::cout << "Результат умножения Double(1) * Int(1): " << B1 * A1 << endl;
    std::cout << "Результат деления Double(1) / Int(1): " << B1 / A1 << endl;
    std::cout << "=================================================" << endl;
    std::cout << "Результат сложения Double(1) + Double(2): " << B1 + B2 << endl;
    std::cout << "Результат разности Double(1) - Double(2): " << B1 - B2 << endl;
    std::cout << "Результат умножения Double(1) * Double(2): " << B1 * B2 << endl;
    std::cout << "Результат деления Double(1) / Double(2): " << B1 / B2 << endl;
    std::cout << "=================================================" << endl;
    
    system("pause");
}
