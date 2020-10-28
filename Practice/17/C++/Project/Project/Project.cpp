#include <iostream>

int main()
{
	setlocale(LC_ALL, "RU");
	int blacknum[18] = { 2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35 };
	int rednum[18] = { 1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36 };
	int allnum[37] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36};
	int bignum[37] = {}, wtfnum[37];
	int in, max = 0, p = 1, red = 0, black = 0;
	
	for (int i = 1; i >= 0;) {
		std::cout << "Введите выпавшее число: ";
		std::cin >> in;
		
		if (in > 36 || in < -36) {
			std::cout << "Неправильный ввод\n";
			system("pause");
			return 0;
		}
		else {
			i = in; // Выключение ПО если отрицательное

			//v = in;														/* Поиск в чаще всего выпавших номеров*/
			//if (v == 0) v = 37;
			//bignum[v-1] += 1;
			for (int d = 0; d <= 36; d++) {
				if (allnum[d] == in) {
					bignum[d] += 1;
					wtfnum[d] = allnum[d];
				}
			}
			for (int d = 0; d <= 36; d++) {
				if (bignum[d] > max) max = bignum[d];
				//if (bignum[d] == max) std::cout << allnum[d] << " ";
			}
			int d = 0;
			while (d <= 36) {
				if (bignum[d] == max) {
					std::cout << allnum[d] << " ";
				}
				d++;
			}
			std::cout << "\n";											/* Конец поиска чаще всего выпавших номеров*/

			
			if (p % 12 == 0) {											/*Проверка на число k*/
				for (int d = 0; d <= 36; d++) {
					wtfnum[d] = -1;
				}
				red = 0;
				black = 0;
			}


			for (int d = 0; d <= 36; d++) {								/*Начало вывода не выпавших чисел за 12 игр*/
				if (allnum[d] == in) {
					wtfnum[d] = allnum[d];
				}
			}
			for (int d = 0; d <= 36; d++) {
				if (allnum[d] != wtfnum[d]) std::cout << allnum[d] << " ";
			}
			std::cout << "\n";											/*Конец вывода не выпавших чисел за 12 игр*/


			for (int d = 0; d <= 17; d++) {								/*Начало вывода красных и черных чисел за 12 игр*/
				if (in == rednum[d]) red++;
				else if (in == blacknum[d]) black++;
			}
			std::cout << red << " " << black << "\n";					/*Конец вывода красных и черных чисел за 12 игр*/

			p++; // одинокая p
		}
	}
}