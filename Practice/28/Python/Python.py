def print_factorization(n: int):
    Res = []
    K = []
    D = 0
    i = 2
    while i <= n:
        if (n % i) == 0:
            D += 1
            if (n / i) != 1:
                K.append(i);
                if D > 0:
                    n = n / i
                    i = 2
                    D = 0
                    continue;
            else: K.append(i)
        i += 1
    buf = {i: K.count(i) for i in K}
    r = 0
    for i in buf:
        if len(buf) > 1:
            if buf[i] != 1:
                if r >= 1:
                    print("*", i, "^", buf[i], sep='', end='')
                else:
                    print(i, "^", buf[i], sep='', end='')
                    r += 1
            elif list(buf)[0] == i:
                print(i, end='', sep = '')
                r += 1
            else:
                print("*", i, end='', sep = '')
        else:
            if buf[i] != 1:
                print(i, "^", buf[i], sep='', end='')
            else:
                print(i, end='')



inp = int(input('Введите целое число больше 1: '))
print_factorization(inp)