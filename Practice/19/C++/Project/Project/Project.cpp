#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
	int n, d;
	string k;
	string k2, k3;
	vector<string> mass(256);
	char symbols;

	cin >> n;
	cin >> k;
	k2 = k;
	d = k.length();
	if (n < 1 && n > 8 && n > int(k.length())) {
		cout << "Неправильный ввод данных\n";
		system("pause");
		return 0;
	}
	else {
		if (int(k.length()) < n) {
			for (int i = 0; i < d; i++) {
				sort(k2.begin(), k2.end());
				do
				{	
					k2.erase(n - int(k.length()));
					k += k2;
					sort(k.begin(), k.end());
					do
					{
						cout << k << '\n';
					} while (next_permutation(k.begin(), k.end()));
				} while (next_permutation(k2.begin(), k2.end()));
			}
		}
		else {
			sort(k.begin(), k.end());
			do
			{
				cout << k << '\n';
			} while (next_permutation(k.begin(), k.end()));
		}
		for (int j = 0; j < 20; j++) {
			std::cout << mass[j] << endl;
		}

	}



}