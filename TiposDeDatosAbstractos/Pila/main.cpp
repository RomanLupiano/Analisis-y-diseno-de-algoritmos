#include <iostream>
#include "pila.h"

using namespace std;

int main(){
    Pila<int> pila;
    pila.agregar(10);
    cout << pila.tope();
    return 0;
}