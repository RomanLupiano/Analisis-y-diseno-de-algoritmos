#include <iostream>
using namespace std;

/* Sean X e Y dos vectores de tamaño n, ordenados de forma creciente, implementar un algoritmo en C++ para 
calcular la mediana de los 2n elementos que contienen X e Y. Calcule la complejidad temporal de la solución propuesta.

Recordemos que la mediana de un vector es aquel elemento que, una vez ordenado el vector, deja la mitad de los elementos a cada uno de sus lados.*/












int mediana(int x[], int y[], int n){
    int medianaX = x[n/2];
    int medianaY = y[n/2];
     
    if (medianaX == medianaY) return medianaX

    if (medianaX < medianaY)
    {
        /* code */
    }
    
    
}




int main(){
    int X[] = {1, 5, 7, 10, 12};
    int Y[] = {2, 4, 8, 9, 15};
    int Z[] = {1, 2, 4, 5, 7, 8, 9, 10, 12,15};
    int n = 5;

    int res = mediana(X, Y, n);

    return 0;
}