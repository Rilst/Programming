#include <iostream>

int main()
{
	setlocale(LC_ALL, "RU");

	int SorK;
	double a;
	double b;
	double c;
	double p;
	double S;
	double A[2];
	double B[2];
	double C[2];
	
	std::cout << "Выберите способ ввода параметров треугольника :\n" << "1. Длины сторон\n" << "2. Координаты вершин\n";

	if (std::cin >> SorK && SorK == 1) {
		std::cout << "Введите длинны сторон: \n";
		if (std::cin >> a >> b >> c) {
			p = (a + b + c) / 2; //16
			S = (p * ((p - a) * (p - b) * (p - c)));
			if (S < 0) std::cout << "Ошибка в веденных значениях\n";
			else std::cout << "S = " << sqrt(S) << "\n";
		}
		else std::cout << "Ошибка в веденных значениях\n";
	}
	else if (SorK == 2) {
		std::cout << "Введите координаты вершин треугольника: \n";
		if (std::cin >> A[0] >> A[1] >> B[0] >> B[1] >> C[0] >> C[1]) {
			S = 0.5 * ((A[0] - C[0]) * (B[1] - C[1])) - ((B[0] - C[0]) * (B[1] - C[1]));
			if (S < 0) std::cout << "Ошибка в веденных значениях\n";
			else std::cout << "S = " << S << "\n";
		}
		else std::cout << "Ошибка в веденных значениях\n";
	}
	else std::cout << "Неверно выбран способ ввода\n";

	system("pause");

}