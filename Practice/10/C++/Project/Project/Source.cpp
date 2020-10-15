#include <iostream>

int main() {
	setlocale(LC_ALL, "RU");
	int s;
	int l1, l2, r1, r2;

	std::cout << "Введите 5 целых чисел через пробел: "; std::cin >> s >> l1 >> r1 >> l2 >> r2;
	
	if (l1 > r1 || l2 > r2)
	{
		std::cout << "Неправильный ввод\n";
		system("pause");
		return 0;
	}

	if (l1 + l2 == s) {
		std::cout << l1 << " " << l2 << "\n";
	}
	else if (l1 + r2 == s) {
		std::cout << l1 << " " << r2 << "\n";
	}
	else if (l2 + r1 == s) {
		std::cout << l2 << " " << r1 << "\n";
	}
	else if (r1 + r2 == s) {
		std::cout << r1 << " " << r2 << "\n";
	}
	else std::cout << "-1\n";

	system("pause");
}
