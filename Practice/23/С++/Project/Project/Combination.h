#ifndef Comb

#define Comb

#include <Factorial.h>

int Combinations(int k, int n) {
	return FactorialTree(n) / (FactorialTree(k) * FactorialTree(n - k));
}
#endif