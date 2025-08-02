#include "arbin.h"
#include <cassert>

template <typename T>
Arbin<T>::Arbin(){
    primero = 0;
    cantidad = 0;
}

template <typename T>
Arbin<T>::~Arbin(){
    primero = 0;
    cantidad = 0;
}

template <typename T>
bool Arbin<T>::vacioArbin() const
{
    return (primero != 0);
}

template <typename T>
const T & Arbin<T>::raiz() const
{
    assert(!vacioArbin());
    return primero->elem;
}

template <typename T>
const Arbin<T> * Arbin<T>::subIzquierdo() const 
{
    assert(!vacioArbin());
    return primero->izq;
}

template <typename T>
const Arbin<T> * Arbin<T>::subDerecho() const 
{
    assert(!vacioArbin());
    return primero->der;
}

template <typename T>
bool Arbin<T>::esHoja() const 
{
    if (primero->izq != 0 && primero->der != 0)
    {
        return true;
    }
    return false;
}

int alturaRec(Arbin<T>::Nodo * nodo){
    if (nodo == 0)
    {
        return -1;
    }
    
    int altIzq = alturaRec(nodo->izq);
    int altDer = alturaRec(nodo->der);

    if (altIzq > altDer)
    {
        return 1 + altIzq;
    }
    
    return 1 + altDer;
}

template <typename T>
int Arbin<T>::altura() const {
    return alturaRec(primero);
}


template <typename T>
bool Arbin<T>::existeElementoRec(Arbin<T>::Nodo * nodo, const T &elem) const
{
    if (nodo == 0)
    {
        return false;
    }
    
    return (nodo->elem == elem) || existeElementoRec(nodo->izq, elem) || existeElementoRec(nodo->der, elem);
}

template <typename T>
bool Arbin<T>::existeElemento(const T &elem) const
{
    return existeElementoRec(primero, elem);
}

template <typename T>
unsigned int Arbin<T>::cantidadNodos() const {
    return cantidad;
}

template <typename T>
bool Arbin<T>::igualdadRec(const Nodo * a, const Nodo * b) const
{
    if (a == 0 && b != 0) return false;
    if (a != 0 && b == 0) return false;
    if (a == 0 && b == 0) return true;

    return (a->elem == b->elem) && igualdadRec(a->izq, b->izq) && igualdadRec(a->der, b->der);
}

template <typename T>
bool Arbin<T>::operator==(const Arbin<T> &otroArbol) const
{
    return igualdadRec(primero, otroArbol.primero);
}


template <typename T>
void Arbin<T>::preordenRec(Arbin<T>::Nodo * nodo) const
{
    if (nodo != 0) {
        cout << nodo->elem << endl;
        preordenRec(nodo->izq);
        preordenRec(nodo->der);
    }
}

template <typename T>
void Arbin<T>::preorden() const
{
    preordenRec(primero);
}

template <typename T>
void Arbin<T>::inordenRec(Arbin<T>::Nodo * nodo) const
{
    if (nodo != 0) {
        inordenRec(nodo->izq);
        cout << nodo->elem << endl;
        inordenRec(nodo->der);
    }
}

template <typename T>
void Arbin<T>::inorden() const
{
    inordenRec(primero);
}

template <typename T>
void Arbin<T>::postordenRec(Arbin<T>::Nodo * nodo) const
{
    if (nodo != 0) {
        postordenRec(nodo->izq);
        postordenRec(nodo->der);
        cout << nodo->elem << endl;
    }
}

template <typename T>
void Arbin<T>::postorden() const
{
    postordenRec(primero);
}

template <typename T>
int Arbin<T>::sumaNodosRec(const Arbin<T>::Nodo * nodo) const
{
    if (nodo == 0) return 0;
    
    return nodo->elem + sumaNodosRec(nodo->izq) + sumaNodosRec(nodo->der);
}

//Devolver la suma de todos los valores almacenados en el árbol.
template <typename T>
int Arbin<T>::sumaNodos() const
{
    return sumaNodosRec(primero);
}



/*Imprimir todos los valores almacenados en los nodos que corresponden a
niveles impares. El nivel de un nodo es la longitud del camino desde la raíz hasta
dicho nodo */
template <typename T>
void Arbin<T>::imprimirImparesRec(const Nodo * nodo, int nivel) const
{
    if (nodo != 0)
    {
        imprimirImparesRec(nodo->izq, nivel+1);
        if (nivel % 2 != 0) cout << nodo->elem << endl;
        imprimirImparesRec(nodo->der, nivel+1);
    }
    
}
template <typename T>
void Arbin<T>::imprimirImpares() const
{
    imprimirImparesRec(primero, 0);
}


//Devolver el mayor y el menor número almacenado en el árbol.
template <typename T>
int Arbin<T>::mayorRec(const Nodo * nodo) const
{
    if (nodo != 0)
    {
        int izqMay = mayorRec(nodo->izq);
        int derMay = mayorRec(nodo->der);
        if (derMay > izqMay)
        {
            if (derMay > nodo->elem)
            {
                return derMay;
            }
            return nodo->elem;
        }

        if (izqMay > nodo->elem)
        {
            return izqMay;
        }
        return nodo->elem;
    }
    return -1;
}

template <typename T>
int Arbin<T>::mayor() const
{
    return mayorRec(primero);
}


//Encontrar la máxima diferencia (en valor absoluto) entre dos hojas adyacentes.
template <typename T>
void Arbin<T>::maximaDiferenciaRec(const Nodo * nodo, T & hojaAnterior, bool & tieneAnterior,  int& maxDif) const
{
    if (nodo == 0) return;
    
    maximaDiferenciaRec(nodo->izq, hojaAnterior, tieneAnterior, maxDif);
    
    if (nodo->izq == 0 && nodo->der == 0){
        if (tieneAnterior){
            int dif;
            if (nodo->elem > hojaAnterior)
            {
                dif = nodo->elem - hojaAnterior;
            } else {
                dif = hojaAnterior - nodo->elem;
            }
            if (dif > maxDif) maxDif = dif;
        }
        hojaAnterior = nodo->elem;
        tieneAnterior = true;
    }
    
    maximaDiferenciaRec(nodo->der, hojaAnterior, tieneAnterior, maxDif);
}
template <typename T>
int Arbin<T>::maximaDiferencia() const
{
    if (primero == 0) return 0;

    T hojaAnterior = T();
    bool tieneAnterior = false;
    int maxDif = 0;

    maximaDiferenciaRec(primero, hojaAnterior, tieneAnterior, maxDif);

    return maxDif;
}

/*Almacenar en un arreglo la rama más liviana, es
decir aquella rama que contiene valores cuya suma es
menor a los de cualquier otra rama en el árbol.*/
template <typename T>
void Arbin<T>::ramaMasLivianaRec(const Nodo * nodo, int ramaActual [], int cursor, int sumaActual, int mejorRama [], int & mejorlargo, int& minSuma) const
{
    if (nodo == 0) return;

    ramaActual[cursor] = nodo->elem;
    cursor++;
    sumaActual += nodo->elem;

    if (nodo->izq == 0 && nodo->der == 0) {
        if (sumaActual < minSuma) {
            minSuma = sumaActual;
            mejorLargo = cursor;
            for (int i = 0; i < cursor; ++i) {
                mejorRama[i] = ramaActual[i];
            }
        }
    }

    ramaMasLivianaRec(nodo->izq, ramaActual, cursor, sumaActual, mejorRama, mejorLargo, minSuma);
    ramaMasLivianaRec(nodo->der, ramaActual, cursor, sumaActual, mejorRama, mejorLargo, minSuma);

}

template <typename T>
int[] Arbin<T>::ramaMasLiviana() const
{   
    int [cantidad] arr;
    ramaMasLivianaRec();
    return 0; 
}

template <typename T>
void Arbin<T>::ramaMasLiviana() const {
    if (primero == 0) return;

    T ramaActual[cantidad];
    T mejorRama[cantidad];
    int mejorLargo = 0;
    int minSuma = 1000000;

    ramaMasLivianaRec(primero, ramaActual, 0, 0, mejorRama, mejorLargo, minSuma);

    // Mostrar la mejor rama
    for (int i = 0; i < mejorLargo; ++i) {
        std::cout << mejorRama[i] << " ";
    }
    std::cout << std::endl;
}


template class Arbin<int>;
template class Arbin<float>;
template class Arbin<char>;