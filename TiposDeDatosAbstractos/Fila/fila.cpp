#include "fila.h"
#include <cassert>

template <typename T>
Fila<T>::Fila(){
    primero = 0;
    ultimo = 0;
}

template <typename T>
Fila<T>::~Fila(){
    ultimo = 0;
    while (primero != 0)
    {
        Fila<T>::Nodo * eliminar = primero;
        primero = primero->sig;
        delete eliminar;
    }   
}

template<typename T>
typename Fila<T>::Nodo * Fila<T>::crearNodo(const T & elem){
    Nodo * nuevo = new Nodo;
    nuevo->elem = elem;
    nuevo->sig = 0;
    return nuevo;
}

template <typename T>
void Fila<T>::agregar(const T & elem){
    Nodo * nuevo = crearNodo(elem);
    if (ultimo == 0) {
        ultimo = nuevo;
        primero = nuevo;
    } else {
        ultimo->sig = nuevo;
        ultimo = nuevo;
    }
}


template <typename T>
bool Fila<T>::esVacia() const{
    return (primero == 0);
}

template <typename T>
const T & Fila<T>::verPrimero() const{
    assert(!esVacia());
    return primero->elem;
}

template <typename T>
void Fila<T>::eliminar(){
    assert(!esVacia());
    Nodo * eliminar = primero;
    if (primero == ultimo){
        ultimo = 0;
    }
    primero = primero->sig;
    delete eliminar;
}


template class Fila<int>;
template class Fila<float>;
template class Fila<char>;