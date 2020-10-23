a = int(input('Введите целое число больше 1: '))
if a == 1 or a == 0:
    print("Неверно введенно число")
elif a == 2:
    print("Простое")
else:
    i = 2
    c = 0
    while i < a:
        if (a % i == 0):
            c = 1
            i = a
        i += 1;
    if c == 1: 
        print("Составное")
    else:
        print("Простое")