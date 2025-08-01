#include "heap.h"
#include <cassert>
#include <iostream>


Heap::Heap(){
    heap = new int[MAX];
    cantidad = 0;
}

Heap::~Heap(){
    delete [] heap;
}

bool Heap::vacioHeap() const {
    return cantidad == 0;
}

void Heap::agregarHeap(unsigned int num){
    //Parent = 	(i - 1) / 2
    //Left node = 2 * i + 1
    //rigth node = 	2 * i + 2

    // 1. Insertar al final
    heap[cantidad] = num;
    int i = cantidad;
    cantidad++;

    bool posCorrecta = false;
    while (i > 0 && !posCorrecta)
    {
        int padre = (i - 1) / 2;
        if (heap[i] < heap[padre]){     //Si el nodo insertado es menor al padre
            int temp = heap[i];         //Los intercambio
            heap[i] = heap[padre];
            heap[padre] = temp;

            i = padre;                  //Evaluo lo mismo con la nueva posición
        } else {
            posCorrecta = true;        
        }
    }    
}

unsigned int Heap::raizHeap() const {
    assert(!vacioHeap());
    return heap[0];
}

void Heap::eliminarHeap(){
    assert(!vacioHeap());
    heap[0] = heap[cantidad-1];
    cantidad--;

    unsigned int i = 0;
    while (true) {
        unsigned int hijoIzq = 2 * i + 1;
        unsigned int hijoDer = 2 * i + 2;
        unsigned int menor = i;

        // Comparar con hijo izquierdo
        if (hijoIzq < cantidad && heap[hijoIzq] < heap[menor]) {
            menor = hijoIzq;
        }

        // Comparar con hijo derecho
        if (hijoDer < cantidad && heap[hijoDer] < heap[menor]) {
            menor = hijoDer;
        }

        // Si ya está en la posición correcta, salimos
        if (menor == i) {
            break;
        }

        // Intercambiar con el hijo menor
        int temp = heap[i];
        heap[i] = heap[menor];
        heap[menor] = temp;

        // Avanzar al hijo menor
        i = menor;
    }

    
}

void Heap::imprimirHeap() const
{
    std::cout << "Heap contiene " << cantidad << " elementos:\n";
    for (unsigned int i = 0; i < cantidad; i++) {
        std::cout << heap[i] << " ";
    }
    std::cout << std::endl;
}
