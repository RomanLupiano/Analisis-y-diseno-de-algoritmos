#include <iostream>
using namespace std;

/* Escriba un algoritmo en C++ que dado un arreglo de enteros encuentre el sub-arreglo de suma
máxima.

a) Resolver por divide y conquista. Determinar la complejidad temporal.
RTA: maximoSubArregloMitad recorre desde la mitad hacia la izquierda y desde la mitad+1 hacia la derecha, sumando los elementos y guardando el máximo parcial.
En el peor caso visita todos los elementos del subarreglo que recibe, pertenece a O(n).
maximoSubArreglo divide el arreglo en dos mitades, resuelve cada mitad recursivamente y luego combina con maximoSubArregloMitad.
Esto nos da la recurrencia: 2T(n/2)+c*n que termina perteneciendo a O(n log n).

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

subArreglo maximoSubArregloMitad(int arr [], int inicio, int mitad, int fin){ 
    int sumaIzq = -9999;
    int suma = 0;
    int indiceIzq = 0;
    for (int i = mitad; i >= inicio; i--)
    {
        suma += arr[i];
        if (suma > sumaIzq)
        {
            sumaIzq = suma;
            indiceIzq = i;
        }
    }

    int sumaDer = -9999;
    suma = 0;
    int indiceDer = 0;

    for (int j = mitad + 1; j <= fin; j++){
        suma += arr[j];
        if (suma > sumaDer)
        {
            sumaDer = suma;
            indiceDer = j;
        }
    }
    
    subArreglo ret;
    ret.inicio = indiceIzq;
    ret.fin = indiceDer;
    ret.suma = sumaIzq+sumaDer;
    return ret;
}

subArreglo maximoSubArreglo(int arr [], int inicio, int fin){
    if (inicio == fin)
    {
        subArreglo ret;
        ret.inicio = inicio;
        ret.fin = fin;
        ret.suma = arr[inicio];
        return ret;
    }

    int mitad = (fin + inicio) / 2;
    
    // Subproblema- Parte1
    subArreglo izq = maximoSubArreglo(arr, inicio, mitad);
    
    // Subproblema-Parte 2
    subArreglo der = maximoSubArreglo(arr, mitad+1, fin);

    //Solución media
    subArreglo mit = maximoSubArregloMitad(arr, inicio, mitad, fin);
    
    //Combinar soluciones
    if ((izq.suma >= der.suma) && (izq.suma >= mit.suma))
        return izq;
    if ((der.suma >= izq.suma) && (der.suma >= mit.suma))
        return der; 
    
    return mit;
    
}



int main(){
    int arr [] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int size = sizeof(arr)/sizeof(arr[0]);
    int inicio = 0;
    int fin = size - 1;

    subArreglo solucion = maximoSubArreglo(arr, inicio, fin);

    cout << "Suma: " << solucion.suma << " con inicio en " << solucion.inicio << " y fin en " << solucion.fin << ".";

    return 0;
}