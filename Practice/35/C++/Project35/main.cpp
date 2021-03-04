#include <iostream>

using namespace std;

struct IntArray {
  int *data;
  int size;
};

void create(IntArray* arr, int size);
void create(IntArray& arr, int size);

int get(IntArray* arr, int index);
int get(IntArray& arr, int index);

void set(IntArray* arr, int index, int value);
void set(IntArray& arr, int index, int value);

void print(IntArray* arr);
void print(IntArray& arr);

void resize(IntArray* arr, int newSize);
void resize(IntArray& arr, int newSize);

void destroy(IntArray* arr);
void destroy(IntArray& arr);

int main()
{
    IntArray Massiv;
    create(Massiv, 30);
    for (int i = 0; i < Massiv.size; i++){
        set(Massiv, i, i+1);
    }
    print(Massiv);
    resize(Massiv, 50);
    print(Massiv);
    resize(&Massiv, 10);
    print(&Massiv);
    destroy(Massiv);
}

void create(IntArray* arr, int size){
    arr->data = new int[size];
    arr->size = size;
}
void create(IntArray& arr, int size){
    arr.data = new int[size];
    arr.size = size;
}
int get(IntArray* arr, int index){
    if (index < arr->size){
        return arr->data[index];
    }
    else{
        cout << "Error! Out of range!";
        exit(1);
    }
}
int get(IntArray& arr, int index){
    if (index < arr.size){
        return arr.data[index];
    }
    else{
        cout << "Error! Out of range!";
        exit(1);
    }
}
void set(IntArray* arr, int index, int value){
    if (index < arr->size){
        arr->data[index] = value;
    }
    else{
        cout << "Error! Out of range!";
        exit(1);
    }
}
void set(IntArray& arr, int index, int value){
    if (index < arr.size){
        arr.data[index] = value;
    }
    else{
        cout << "Error! Out of range!";
        exit(1);
    }
}
void print(IntArray* arr){
    cout << "[";
    for (int i = 0; i < (arr->size)-1; i++){
        cout << arr->data[i] << ", ";
    }
    cout << arr->data[(arr->size)-1] << "]\n";
}
void print(IntArray& arr){
    cout << "[";
    for (int i = 0; i < (arr.size)-1; i++){
        cout << arr.data[i] << ", ";
    }
    cout << arr.data[(arr.size)-1] << "]\n";
}
void resize(IntArray* arr, int newSize){
    int* newarr = new int[newSize];

    if (newSize < arr->size){
        for (int i = 0; i < newSize; i++){
            newarr[i] = arr->data[i];
        }
    }
    else if (newSize >= arr->size){
        for (int i = 0; i < newSize; i++){
            if(i < (arr->size)) newarr[i] = arr->data[i];
            else newarr[i] = 0;
        }
    }

    delete[] arr->data;

    arr->data = newarr;
    arr->size = newSize;
}
void resize(IntArray& arr, int newSize){
    int* newarr = new int[newSize];

    if (newSize < arr.size){
        for (int i = 0; i < newSize; i++){
            newarr[i] = arr.data[i];
        }
    }
    else if (newSize >= arr.size){
        for (int i = 0; i < newSize; i++){
            if(i < (arr.size)) newarr[i] = arr.data[i];
            else newarr[i] = 0;
        }
    }

    delete[] arr.data;

    arr.data = newarr;
    arr.size = newSize;
}
void destroy(IntArray* arr){
        if (arr->data != nullptr){
            delete[] arr->data;
            arr->data = nullptr;
            arr->size = 0;
        }
}
void destroy(IntArray& arr){
        if (arr.data != nullptr){
            delete[] arr.data;
            arr.data = nullptr;
            arr.size = 0;
        }
}
