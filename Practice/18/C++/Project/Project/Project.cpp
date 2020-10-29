#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main()
{
	setlocale(LC_ALL, "RU");

	vector<string> znania = { "hallo", "klempner", "das", "ist", "fantastisch", "fluggegecheimen" };
	string jija, in;
	char check;
	int num[256] = {}, num2[256] = {}; // Размер массива нужно менять если общее кол-во букв в словах знаний больше 256 и так же размер стоп слова больше 256 букв
	double res = 1;

	for (int i = 0; i < int(znania.size()); i++) {		// Кидаем все слова в одну кучу
		jija += znania[i];
	}

	for (int i = 0; i < int(jija.length()); i++) {		// Считаем сколько раз встречается каждая буква
		check = jija[i];
		for (int j = 0; j < int(jija.length()); j++) {
			if (check == jija[j]) num[i]++;
		}
	}

	cout << "Введите стоп-слово: ";
	cin >> in;

	for (int i = 0; i < int(in.length()); i++) {		// Сверяем буквы введенного слова с кол-вом появлений этой буквы в знаниях
		check = in[i];
		for (int j = 0; j < int(jija.length()); j++) {
			if (check == jija[j]) num2[i] = num[j];
		}
	}

	for (int i = 0; i < int(in.length()); i++) {
		res *= double(num2[i]) / jija.length();			// Находим шанс прознести каждую букву стоп слова и перемножаем их
	}

	cout.precision(16); // Делаем вывод 16 знаков после запятой
	cout << res << endl;	// Выводим результат

	system("pause");
}
