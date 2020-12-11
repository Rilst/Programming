def BublSort(Array):
    for i in range(len(Array)-1):
        for j in range(len(Array)-i-1):
            if Array[j] < Array[j+1]:
                buf = Array[j]
                Array[j] = Array[j+1]
                Array[j+1] = buf
    return Array
def ArrPrint(Arr):
    for x in Arr: print(x, end = ' ')
    print()    
def TopFive(Array):
    Buf = []
    D = 0
    i = 0
    for i in range(len(Array)):
        if len(Buf) == 5:
            j = 0
            for j in range(len(Buf)):
                if (Buf[j] > Array[i]):
                    k = j
                    D = 1
                    break;
            if D == 1:
                Buf[k] = Array[i]
                D = 0
        else:
            Buf.append(Array[i])
        Buf = BublSort(Buf)
        ArrPrint(Buf)       

b = input()
c = input()
d = c.split()
D = [int(x) for x in d]
if int(b) == len(D):
    TopFive(D)
else:
    exit()