#include <iostream>
using namespace std;
/* Escriba un algoritmo en C++ que dado un arreglo de enteros encuentre los enteros máximo y mínimo:
a) Resolver a partir de un algoritmo iterativo
b) Resolver aplicando la técnica divide y conquista
c) Realice un análisis comparativo de eficiencia de las soluciones provistas en a) y b)*/


//a) Complejidad O(n) con 2n comparaciones
void recorridoIterativo(int arr [], int tam, int & min, int & max){
    for (int i = 0; i < tam; i++)
    {
        if (arr[i] < arr[min])
        {
            min = i;
        }
        if (arr[max] < arr[i])
        {
            max = i;
        }
    }
}

//b) Complejidad O(n)
void recorridoDyQ(int arr [], int inicio, int fin, int & min, int & max){
    if (inicio == fin) {
        if (arr[inicio] < arr[min])
            min = inicio;
        
        if (arr[inicio] > arr[max])
            max = inicio;
        
        return;
    }

    int medio = (fin + inicio) / 2;
    recorridoDyQ(arr, inicio, medio, min, max);
    recorridoDyQ(arr, medio+1, fin, min, max);
}



int main(){
    int arr [] = {5, 2, 8, 1, 9, 4, 7, 3, 6};
    int tam = 9;
    int min = 0;
    int max = 0;

    //recorridoIterativo(arr, tam, min, max);
    recorridoDyQ(arr, 0, 8, min, max);

    cout << "Min encontrado: " << min << " en arr: " << arr[min] << " | Max encontrado: " << max << " en arr: " << arr[max];
    return 0;
}