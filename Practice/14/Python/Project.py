import math
n = int(input('Введите целое число: '))
if n == 0 or n == 1:
    print(0)
res = 1 + math.log2(n)
print(int(res))