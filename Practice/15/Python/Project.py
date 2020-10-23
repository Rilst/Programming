import random
print("Вы играте в игру *Угадай число*. Компьютер загадал случайное число от 0 до 100, попробуйте его угадать. У вас 5 попыток!")
i = 1
n = random.randint(0, 100)
print(n)
while i < 8:
    if i <= 5:
        d = int(input())
        if d == n:
            print("Поздравляю! Вы угадали\nХотите начать сначала? (1 - ДА)")
            d = n
            i = int(input())
            if i != 1:
                input('Нажмите клавишу Enter чтобы завершить игру')
                exit()
            else:
                i = 0
                n = random.randint(0, 100)
        if d != n and i == 5:
            i = 6
        elif d > n and i >= 1:
                print("Загаданное число меньше")
        elif i >= 1:
                print("Загаданное число больше")
    else:
        print("Вы проиграли. Загаданное число: ", n, "\n", "Хотите начать сначала? (1 - ДА)", sep='')
        i = int(input())
        if i != 1:
            input('Нажмите клавишу Enter чтобы завершить игру')
            exit()
        else:
            i = 0
            n = random.randint(0, 100)
    i += 1
