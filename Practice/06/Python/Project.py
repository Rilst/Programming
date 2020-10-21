print("Введите 3 любых вещественных числа для нахождения корней уравнения: ")
a = float(input())
b = float(input())
c = float(input())
D = (pow(b, 2)) - 4 * a * c
if D < 0:
    print("Дискриминант меньше 0 - корней нет")
else:
    if a == 0:
        if b == 0 and c == 0:
            print("Решением уравнения может быть любое число")
        elif b == 0 and c != 0:
            print("Уравнение не имеет решения")
        elif b != 0 and c == 0:
            print("x = 0")
        else:
            x = -c / b
            print("x = ", x, sep='')
    else:
        x1 = (-b + sqrt(D)) / (2 * a)
        x2 = (-b - sqrt(D)) / (2 * a)
        if c == 0 and b != 0:
            x = -(b / a)
            print("x1 = 0")
            print("x2 = ", x , sep='')
        else:
            if x1 == x2:
                x = x1
                if x == 0: print("Решением уравнения может быть любое число")
                else: print("x = ", x , sep='')
            else: print("x1 = ", x1 , "\nx2 = " , x2 ,sep='')