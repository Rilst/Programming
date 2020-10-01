#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    int A;
    int B;
    int C;
    std::cout << "Введите значение переменной A: "; std::cin >> A;
    std::cout << "Введите значение переменной B: "; std::cin >> B; std::cout << endl;

        C = A;
        A = B;
        B = C;

        std::cout << "Результат первого обмена значений, с помощью доп. переменной: A = " << A << "; B = " << B << endl;

        B = B + A;
        A = B - A;
        B = B - A;

        std::cout << "Результат второго обмена значений, без помощи доп. переменной: A = " << A << "; B = " << B << endl;
   
     system("pause");
}
