#include <iostream>
using namespace std;

/* Escriba un algoritmo en C++ que dado un arreglo de enteros encuentre el sub-arreglo de suma
máxima.
a) Resolver por divide y conquista. Determinar la complejidad temporal.
b) Analice la complejidad temporal cuando todos los números del arreglo son positivos. ¿Es necesario aplicar la técnica?
RTA: si todos los números son positivos ningún día resta y entonces el arreglo entero es la súma máxima que estamos buscando.
En la página https://mitpress.mit.edu/9780262046305/introduction-to-algorithms/ en el apartado de resources, se puede descargar
Materials Removed from 3e, en la carpeta descargada se "The maximum-subarray problem.pdf" que explica este ejercicio.
*/

struct subArreglo{
    int inicio;
    int fin;
    int suma;
};

subArreglo maximoSubArreglo(int arr [], int inicio, int fin, int suma){
    if (inicio == fin)
    {
        subArreglo ret;
        ret.inicio = inicio;
        ret.fin = fin;
        ret.suma = suma;
        return ret;
    }

    int mitad = (fin + inicio) / 2;
    
    // Subproblema- Parte1
    subArreglo izq = maximoSubarreglo(Arr, inicio, mitad);
    
    // Subproblema-Parte 2
    subArreglo der = maximoSubarreglo(Arr, mitad+1, fin);

    //Solución media
    subArreglo mitad = maximoSubArregloMitad(Arr, inicio, mitad, fin);
    
    //Combinar soluciones
    if ((sumaIzq > sumaDer) and (sumaIzq > sumaMedia)) {

    }
    if ((sumaDer >= sumaIzq) and (sumaDer >= sumaMedia)) {

    } else {

    }
    
}





int main(){
    int arr [] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int size = sizeof(arr)/sizeof(arr[0]);
    int inicio = 0;
    int fin = size - 1;
    int inicioSol = 0;
    int finSol = 0;
    int sumaSol = 0;

    subArreglo solucion = maximoSubArreglo(arr, inicio, fin, sumaSol);

    cout << "Suma: " << solucion.suma << " con inicio en " << solucion.inicio << " y fin en " << solucion.fin << "."

    return 0;
}