blacknum = [ 2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35 ]
rednum = [ 1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36 ]
allnum = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36]
bignum = [0] * 37
wtfnum = [0] * 37
max1 = 0
p = 1
red = 0
black = 0
i = 1
while i >= 0:
    in1 = int(input('Введите выпавшее число: '))
    i = in1
    if (in1 > 36) or (in1 < -36):
        print("Неправильный ввод")
        exit()
    elif i >= 0:
        #i = in1
        d = 0
        while d <= 36:
            if allnum[d] == in1:
                bignum[d] += 1
                wtfnum[d] = allnum[d]
            d += 1
        d = 0
        while d <= 36:
            if bignum[d] > max1:
                max1 = bignum[d]
            d += 1
        d = 0
        while d <= 36:
            if bignum[d] == max1:
                print(allnum[d], " ", sep='', end='')
            d += 1
        print()
        if p % 12 == 0:
            d = 0
            while d <= 36:
                wtfnum[d] = -1
                d += 1
            red = 0
            black = 0
        d = 0
        while d <= 36:
            if allnum[d] == in1:
                wtfnum[d] = allnum[d]
            d += 1
        d = 0
        while d <= 36:
            if allnum[d] != wtfnum[d]: 
                print(allnum[d], " ", sep='', end='')
            d += 1
        print()
        d = 0
        while d <= 17:
            if in1 == rednum[d]:
                red += 1
            elif in1 == blacknum[d]:
                black += 1
            d += 1
        print(red, black)
        p += 1
    else:
        exit()
       