#include <iostream>

using namespace std;


int particion(int arr[], int inicio, int fin){
    int p = arr[inicio];
    int i = inicio+1;
    int j = fin;

    while (i < j)
    {
        while (i <= fin && arr[i] <= p) i++;
        while (j >= inicio && arr[j] > p) j--;

        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    arr[inicio] = arr[j];
    arr[j] = p;
    return j;
    
}


void quickSort(int arr[], int inicio, int fin){
    if (inicio >= fin) return;

    int p = particion(arr, inicio, fin);
    quickSort(arr, inicio, p-1);
    quickSort(arr, p+1, fin);
}

int main(){
    int arr[] = {4, 3, 1, 5, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    return 0;
}