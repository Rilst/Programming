print("Введите время 1: ", end='')
h1, m1 = map(str, input().split(':'))
print("Введите время 2: ", end='')
h2, m2 = map(str, input().split(':'))

if int(h1) >= 0 and int(h2) >= 0 and int(m1) >= 0 and int(m2) >= 0 and int(m1) <= 59 and int(m2) <= 59:
    p1 = (int(h1) * 60) + int(m1)
    p2 = (int(h2) * 60) + int(m2)
    if abs(p1 - p2) <= 15:
        print("Встреча состоится")
    else:
        print("Встреча не состоится")

else:
    print("Неверный ввод")