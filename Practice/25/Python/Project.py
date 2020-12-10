import random
import math

def ArrPrint(Arr):
    for x in Arr: print(x, end = ' ')
    print()
    
def swap(v, x, y):
    t = v[x]
    v[x] = v[y]
    v[y] = t
    
def isSorted(LST, small):
    if small == True:
        for i in range(1, len(LST)):
            if(LST[i - 1] > LST[i]):
                return False
        return True
    else:
        for i in range(1, len(LST)):
            if(LST[i - 1] < LST[i]):
                return False
        return True
        
def BozoSort(a, b = None , c = None, small = True):
    def Bozo(num, small):
        while True:
                n1 = random.randint(0, (len(num)-1))
                n2 = random.randint(0, (len(num)-1))
                if (n1 != n2):
                    swap(num, n1, n2)
                else:
                    continue;
                if isSorted(num, small):
                    return num
    if b == None:
        if isinstance(a[0], int):
            return Bozo(a, small)
        elif isinstance(a[0], list):
            i = 0
            j = 0
            buf = []
            while i < len(a):
                buf.extend(a[i])
                i += 1;
            buf = Bozo(buf, small)
            return buf
    else:
        buf = []
        buf.append(a)
        buf.append(b)
        buf.append(c)
        buf = Bozo(buf, small)
        return buf;

b = input()
c = input()
d = c.split()
D = [int(x) for x in d]
if int(b) == len(D):
    D1 = D
    ARR = []
    buf = []
    for i in D:
        buf.append(i)
        if math.sqrt(int(b)) == len(buf):
            ARR.append(buf)
            buf = []
            
    ArrPrint(BozoSort(D))
    ArrPrint(BozoSort(D, None, None,False))
    ArrPrint(BozoSort(ARR))
    ArrPrint(BozoSort(ARR, None, None, False))
    ArrPrint(BozoSort(D1[0], D1[1], D1[2]))
    ArrPrint(BozoSort(D1[0], D1[1], D1[2], False))
else:
    exit()