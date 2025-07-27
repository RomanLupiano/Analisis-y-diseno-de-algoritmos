#include "heap.h"

Heap::Heap(){
    primero = 0; //NULL
}

void Heap::vaciarMemoria(Heap::Nodo * nodo){
    if (nodo == 0) 
        return;

    vaciarMemoria(nodo->izq);
    vaciarMemoria(nodo->der);
    delete nodo;
}

Heap::~Heap(){
    vaciarMemoria(primero);
}

Heap::Nodo * Heap::crearNodo(unsigned int num){
    Nodo * nuevo = new Nodo;
    nuevo->num = num;
    nuevo->izq = 0;
    nuevo->der = 0;

    return nuevo;
}


void Heap::agregarHeap(unsigned int num){
    if (primero == 0){
        primero = crearNodo(num);
    } else {
        
    }
    
}
