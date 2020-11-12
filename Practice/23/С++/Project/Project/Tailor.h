#ifndef Tailor2

#define Tailor2

#include <Factorial.h>
#include <iostream>

double Tailor(double x, int k) {
	double res = 0;
	for (int i = 0; i < k; i++) {
		res += pow(-1, i) * (pow(x, (2 * i + 1)) / FactorialTree(2 * i + 1));
	}
	return res;
}
#endif // Tailor