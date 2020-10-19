#include <iostream>

int main() {
	setlocale(LC_ALL, "RU");
	int s;
	int l1, l2, r1, r2;

	std::cout << "¬ведите 5 целых чисел через пробел: "; std::cin >> s >> l1 >> r1 >> l2 >> r2;

	if (s - l1 < l2) {
		std::cout << "-1" << "\n";
	}
	else if (s - l1 > l2 && s - l1 <= r2 ) {
		std::cout << l1 << " " << s - l1 << "\n";
	}
	else if (s - r1 > r2) {
		std::cout << "-1" << "\n";
	}
	else if (s - r1 <= r2) {
		std::cout << s - r2 << " " << r2 << "\n";
	}
	else std::cout << "-1\n";

	system("pause");
}
