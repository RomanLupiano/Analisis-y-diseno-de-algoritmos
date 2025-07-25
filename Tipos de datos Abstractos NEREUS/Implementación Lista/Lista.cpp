#include <iostream>
#include "Lista.h"

Lista::Lista()
{
    primero = NULL;
}

Lista::~Lista()
{
    Nodo * cursor = primero;
    Nodo * eliminar = primero;
    while (cursor != NULL)
    {
        cursor = primero->sig;
        delete eliminar;
        eliminar = cursor;
    } 
}

void Lista::agregarNodo(int num)
{
    if (primero == NULL || num < primero->elemento){
        primero = crearNodo(num, primero);
    } else {
        Nodo * cursor = primero;
        while (cursor->sig != NULL and cursor->elemento < num)
        {
            cursor->sig;
        }
        cursor->sig = crearNodo(num, cursor->sig);  
    }
}


Nodo *Lista::crearNodo(int num, int sig)
{
    Nodo * nuevo = new Nodo();
    nuevo->elemento = num;
    nuevo->sig = sig;
    return nuevo;
}


int main (){
    Lista lista = new Lista();
    Lista lis();

    return 0;
}