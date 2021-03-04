#include <iostream>

using namespace std;

void create(int** Array ,int size, int first = 0, int step = 0);
void destroy(int** Arr);
void sort(int* Arr,int size);
int* print(int* Arr,int size);

int main()
{
    setlocale(LC_ALL, "RU");
    int size, first, step;

    cout << "Введите длинну массива: ";
    cin >> size;
    cout << "Введите начальный член массива: ";
    cin >> first;
    cout << "Введите шаг арифметической прогрессии: ";
    cin >> step;
    if (size > 0 && size <= 10000 && first >= -10000 && first <= 10000 && step >= -10000 && step <= 10000){
        int* Arr;

        create(&Arr, size, first, step);
        sort(Arr, size);
        print(Arr, size);
        destroy(&Arr);
    }
    else cout << "Не правильный ввод!\n";

}

void create(int** Array ,int size, int first, int step){
    *Array = new int[size];
    for (int i = 0; i < size; i++){
        (*Array)[i] = first;
        first += step;
    }
}
void destroy(int** Arr){
    if (*Arr != nullptr){
        delete[] *Arr;
        *Arr = nullptr;
    }
}
void sort(int* Arr,int size){
    for(int i=1; i<size; i++){
        for(int j=i; j>0; j--){
            if(Arr[j-1]>Arr[j]){
                swap(Arr[j-1], Arr[j]);
            }
        }
    }
}
int* print(int* Arr,int size){
    cout << "[";
    for (int i = 0; i < size-1; i++){
        cout << Arr[i] << ", ";
    }
    cout << Arr[size-1] << "]\n";
    return Arr;
}
