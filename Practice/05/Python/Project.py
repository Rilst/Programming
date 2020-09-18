x0, v0, t = map(float,input('Введите значения через пробел: ').split())
a=9.8

x = x0 + v0 * t - ((a * t * t) / 2)

print(x)