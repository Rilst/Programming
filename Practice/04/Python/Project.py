a=input('Введите переменную A: ')
b=input('Введите переменную B: ')
c=b
b=a
a=c
print("Результат обмена значений с доп. переменной А=", a , "; B=", b , ";")
a, b = b, a
print("Результат обмена значений без доп. переменной А=", a , "; B=", b , ";")
