print("Введите число: ")
a = int(input())
print("Введите необходимую степень числа: ")
b = int(input())
c = a;
i = 1
while i < b:
    c = c * a
    i += 1
print(c)