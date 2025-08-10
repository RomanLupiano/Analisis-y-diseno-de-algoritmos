#include <iostream>
using namespace std;

/* Sea T un arreglo ordenado de n enteros diferentes, alguno de los cuales pueden ser negativos.
Escriba un algoritmo en C++ que encuentre el índice i tal que 0 ≤ i < n y T[i] = i, siempre y cuando
exista tal índice. La complejidad temporal de la solución propuesta debe pertenecer a O(log n).*/

int busqueda(int arr [], int inicio, int fin){
    if (inicio > fin) return -1;
    
    int medio = (fin + inicio) / 2;
    if (arr[medio] == medio) 
        return medio;
    
    if (arr[medio] > medio)
    {
        return busqueda(arr, inicio, medio-1);
    }

    return busqueda(arr, medio+1, fin);
}


int main(){
    int arr [] = {0, 2, 4, 8, 10}; //{0, 2, 3, 5, 100, 120, 200, 300, 2500};
    int size = sizeof(arr)/sizeof(arr[0]);

    int indice = busqueda(arr, 0, size-1);

    if (indice >= 0)
    {
        cout << "indice encontrado: " << indice << " | valor del arreglo en ese indice: " << arr[indice];
    } else {
        cout << "No se encontró tal indice";
    }
    

    return 0;
}




