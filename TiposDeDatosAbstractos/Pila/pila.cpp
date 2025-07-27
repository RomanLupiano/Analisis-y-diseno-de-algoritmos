#include "pila.h"
#include <string>
#include <cassert>

template <typename T>
Pila<T>::Pila(){
    primero = NULL;
}

template <typename T>
Pila<T>::~Pila(){
    while (primero != NULL)
    {
        Nodo * cursor = primero->sig;
        delete primero;
        primero = cursor;
    }
}

template <typename T>
typename Pila<T>::Nodo * Pila<T>::crearNodo(const T & elemento){
    Nodo * nuevo = new Nodo;
    nuevo->elem = elemento;
    nuevo->sig = NULL;
    return nuevo;
}

template<typename T>
void Pila<T>::agregar(const T & elemento){
    Nodo * nuevo = crearNodo(elemento);
    primero = nuevo;

}

template<typename T>
bool Pila<T>::eliminar(){
    if (!vaciaPila()){
        Nodo * eliminar = primero;
        primero = primero->sig;
        delete eliminar;
        return true;
    }

    return false;
}

template<typename T>
bool Pila<T>::vaciaPila() const {
    return primero == NULL;
}

template<typename T>
const T & Pila<T>::tope() const{
    assert(!vaciaPila());
    return primero->elem;
}


template class Pila<int>;
template class Pila<float>;
template class Pila<std::string>;