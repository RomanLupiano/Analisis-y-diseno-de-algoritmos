#include <iostream>
#include "heap.h"

using namespace std;

int main() {
    Heap h;
    h.agregarHeap(10);
    h.agregarHeap(5);
    h.agregarHeap(15);
    h.agregarHeap(3);
    
    h.imprimirHeap();  // Salida: Heap contiene 4 elementos: 3 5 15 10 
}

