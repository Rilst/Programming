#include <iostream>

int main()
{
    setlocale(LC_ALL, "RU");
    int n, res;

    std::cout << "Введите целое число: ";
    std::cin >> n;
    
    if (n == 0 || n == 1) std::cout << 0 << std::endl;
    res = 1 + log2(n);
    std::cout << res << std::endl;

    system("pause");
}
