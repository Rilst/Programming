print("Введите 5 целых чисел через пробел: ", end='') 
s, l1, r1, l2, r2 = map(int, input().split())

if s - l1 < l2:
    print("-1")
elif s - l1 > l2 and s - l1 <= r2:
    print(l1, " ", s - l1, sep='')
elif s - r1 > r2:
    print("-1")
elif s - r1 <= r2: 
    print(s - r2, " ", r2, sep='')
else:
    print("-1")
