#include <iostream>
#include <cassert>

#include "Lista.h"

Lista::Lista()
{
    primero = NULL;
    cantidad = 0;
}

Lista::~Lista()
{
    Nodo * cursor = primero;
    Nodo * eliminar = primero;
    while (cursor != NULL)
    {
        cursor = cursor->sig;
        delete eliminar;
        eliminar = cursor;
    } 
}

void Lista::agregar(unsigned int pos, int elem)
{
    assert(pos>=1 and pos<=longitud()+1); //Para validar pos

    if (pos == 1){
        primero = crearNodo(elem, primero);
    } else {
        Nodo * cursor = primero;
        for (unsigned int i = 1; i < pos - 1; i++){
            cursor = cursor->sig;
        }
        cursor->sig = crearNodo(elem, cursor->sig);  
    }

    cantidad++;
}


Lista::Nodo * Lista::crearNodo(int num, Nodo * sig)
{
    Nodo * nuevo = new Nodo();
    nuevo->elemento = num;
    nuevo->sig = sig;
    return nuevo;
}

unsigned int Lista::longitud() const {
    return cantidad;
}

int Lista::recuperar(unsigned int pos) const {
    assert(pos>=1 and pos<=longitud()); //Para validar pos, y si la lista esta vacia entonces pos<=0 y pos>=1 y se activa el assert

    if (pos == 1){
        return primero->elemento;
    }

    Nodo * cursor = primero;
    for (unsigned int i = 1; i < pos; i++){
        cursor = cursor->sig;
    }

    return cursor->elemento;
}

bool Lista::eliminar(unsigned int pos){
    assert(pos>=1 and pos<=longitud()); //Para validar pos

    if (primero == NULL){
        return false;           //Lista vacia
    }

    cantidad--;                 //A partir de este punto se elimina si o si de la lista.

    Nodo * eliminar = primero;
    if (pos == 1){              //Eliminar el primer elemento
        primero = primero->sig;
        delete eliminar;
        return true;
    }

    Nodo * cursor = primero;

    for (unsigned int i = 1; i < pos -1; i++){  //No me preocupo por los NULL porque pos ya esta validado al inicio del metodo.
        cursor = cursor->sig;
    }

    eliminar = cursor->sig;
    cursor->sig = cursor->sig->sig;   
    delete eliminar;
    return true;
}

void Lista::invertir(){
    primero = inversion(primero);
}

Lista::Nodo * inversion(Lista::Nodo * nodo){
    if (nodo == 0 || nodo->sig == 0) return nodo;
    Nodo temp = inversion(nodo->sig);
    nodo->sig->sig = nodo;
    nodo->sig = 0;
    return temp;   
}