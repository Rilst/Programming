def create(size: int, first=0, step=0):
    arr = list()
    for i in range(first, (size*step), step):
        arr.append(i)
    return arr
    
def Print(arr: list):
    print(arr)

def sort(arr: list):
    for i in range(1, len(arr)):
        temp = arr[i]
        j = i - 1
        while (j >= 0 and temp < arr[j]):
            arr[j + 1] = arr[j]
            j = j - 1
        arr[j + 1] = temp

size = int(input('Введите размер: '))
first = int(input('Введите первый элемент арифметической прогрессии: '))
step = int(input('Введите шаг арифметической прогрессии: '))

if 1 < size and size <= 10000 and first >= -10000 and first <= 10000 and step >= -10000 and step <= 10000:
    Array = create(size, first, step)
    sort(Array)
    Print(Array)
else: print("Ошибка ввода")