n = int(input('Введите количество билетов: '))
print("Введите номера билетов:" , end=' ')
i = 0
check = 0
bilet = input().split()
while(i < n):
    if len(bilet[i]) == 9:
        if (bilet[i][0] == 'a') and bilet[i][4:] == "55661":
            print(bilet[i])
            check = 1
    else:
        print("Неверно введен билет №", i+1, "!", sep = '')
    i += 1
if check == 0:
    print(-1)