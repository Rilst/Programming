#include <iostream>
#include <Factorial.h>
#include <Combination.h>
#include <Tailor.h>
#include <iomanip>

#define PI 3.14159265358979323846


int main()
{
    std::cout << "n\t" << "n!\n";
    for (int i = 1; i <= 10; i++) {
        std::cout << i << "\t" << FactorialTree(i) << "\n";
    }

    std::cout << "\nx\t" << "sin(x)\n";
    for (double i = 0; i <= (PI/4); i += (PI/180)) {
        std::cout << std::setprecision(4) << Tailor(i, 5) << "\t" << sin(i) << "\n";
    }

    std::cout << "\nk\t" << "C(k, 10)\n";
    for (double i = 1; i <= 10; i++) {
        std::cout << i << "\t" << Combinations(i, 10) << "\n";
    }

    system("pause");
}
