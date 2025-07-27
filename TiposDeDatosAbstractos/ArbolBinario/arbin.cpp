#include "arbin.h"

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
void crearArbol(const Arbin<T> &, T elem);


template class Arbin<int>;
template class Arbin<float>;
template class Arbin<char>;