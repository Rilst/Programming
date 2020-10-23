print("Введите целое число для нахождения его факториала")
a = int(input())
b = 1;
if a < 0:
    print("У отрицательного числа нет факториала!")
elif a == 1 or a == 0:
    print(1)
else:
    i = 1
    while i <= a:
        b = b * i
        i += 1
print(b)