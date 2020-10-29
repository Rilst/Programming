znania = [ 'hallo', 'klempner', 'das', 'ist', 'fantastisch', 'fluggegecheimen' ]
jija = str('')
num = [0] * 256
num2 = [0] * 256
res = 1
i = 0
for i in range(len(znania)):		
    jija += znania[i]
i = 0
j = 0
for i in range(len(jija)):	# Считаем сколько раз встречается каждая буква
    check = jija[i]
    for j in range(len(jija)):
        if check == jija[j]:
            num[i] += 1
in1 = str(input('Введите стоп-слово: '))
i = 0
j = 0
for i in range(len(in1)):		# Сверяем буквы введенного слова с кол-вом появлений этой буквы в знаниях
    check = in1[i];
    for j in range(len(jija)):
        if check == jija[j]:
            num2[i] = num[j]
i = 0
for i in range(len(in1)):
    res *= num2[i] / len(jija)		# Находим шанс прознести каждую букву стоп слова и перемножаем их
print(res)	# Выводим результат