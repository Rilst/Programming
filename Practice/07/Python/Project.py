print("Выберите способ ввода параметров треугольника :", "1. Длины сторон", "2. Координаты вершин", sep='\n')
SorK = int(input())
if SorK == 1:
    print("Введите длинны сторон: ");
    a = float(input())
    b = float(input())
    c = float(input())
    p = (a + b + c) / 2
    S = (p * ((p - a) * (p - b) * (p - c)))
    if S < 0:
        print("Ошибка в веденных значениях")
    else: 
        print("S = " , pow(S, 0.5), sep='')
elif SorK == 2:
    print("Введите координаты вершин треугольника: ")
    A = [float(i) for i in input().split()]
    B = [float(i) for i in input().split()]
    C = [float(i) for i in input().split()]
    print()
    S = 0.5 * abs(((B[0] - A[0]) * (C[1] - A[1])) - ((C[0] - A[0]) * (B[1] - A[1])))
    print("S = ",S , sep='')	
else:
    print("Неверно выбран способ ввода")
