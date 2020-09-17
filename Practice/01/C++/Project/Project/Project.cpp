#include <iostream>

using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int A;
    A = 2 + 2 * 2;
    std::cout << "Результат выражения 2+2*2 = " << A << endl;
    cin.get();
}
