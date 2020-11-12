#pragma once

long int ProdTree(int one, int two)
{
    if (one > two) return 1;
    if (one == two) return one;
    if (two - one == 1) return one * two;
    int N = (one + two) / 2;
    return ProdTree(one, N) * ProdTree(N + 1, two);
}
long int FactorialTree(int n)
{
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (n == 1 || n == 2) return n;
    return ProdTree(2, n);
}                                                       // ¬ысчитываем факториал с помощью метода дерева ибо так быстрее чем итерационным методом