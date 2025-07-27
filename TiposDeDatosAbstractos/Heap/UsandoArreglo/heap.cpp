#include "heap.h"


Heap::Heap(){
    heap = new int[100];
    ultimaPos = 0;
}

Heap::~Heap(){
    delete [] heap;
}


void Heap::agregarHeap(unsigned int num){
    //Parent = 	(i - 1) / 2
    //Left node = 2 * i + 1
    //rigth node = 	2 * i + 2
    heap[ultimaPos] = num;

    
    
}
