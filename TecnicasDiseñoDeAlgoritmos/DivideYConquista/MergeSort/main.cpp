#include <iostream>

using namespace std;

void merge(int arr [], int inicio, int medio, int fin){
    if (inicio >= fin) return;

    int arrTemp [(fin - inicio + 1)];

    int cursorArr = 0;
    int cursorIzq = inicio;
    int cursorDer = medio+1;

    while (cursorIzq <= medio && cursorDer <= fin)
    {
        if (arr[cursorIzq] < arr[cursorDer])
        {
            arrTemp[cursorArr] = arr[cursorIzq];
            cursorIzq++;
        } else {
            arrTemp[cursorArr] = arr[cursorDer];
            cursorDer++;
        }
        cursorArr++;
    }

    while (cursorIzq <= medio)
    {
        arrTemp[cursorArr] = arr[cursorIzq];
        cursorArr++;
        cursorIzq++;
    }

    while (cursorDer <= fin)
    {
        arrTemp[cursorArr] = arr[cursorDer];
        cursorArr++;
        cursorDer++;
    }

    for (int i = inicio; i <= fin; i++){
        arr[i] = arrTemp[i - inicio];
    }
    
}


void mergeSort(int arr[], int inicio, int fin){
    if (inicio < fin)
    {
        int medio = (inicio + fin) / 2;
        mergeSort(arr, inicio, medio);
        mergeSort(arr, medio+1, fin);
        merge(arr, inicio, medio, fin);
    }
}


int main(){
    int arr[] = {4, 3, 1, 5, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    return 0;
}