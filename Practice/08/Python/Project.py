print("Введите арифметическое выражение: ", end = '')
a, b, c = map(str, input().split()); 
if b == '+' or b == '-' or b == '*' or b == '/':
    if b == '*':   
        print(float(a) * float(c))
    if b == '+':
        print(float(a) + float(c))
    if b == '-':
        print(float(a) - float(c))
    if b == '/':
        if c == '0': 
            print("Деление на 0 невозможно")
        else: 
            print(float(a) / float(c))
else:
    print("Неверно указан знак операции")