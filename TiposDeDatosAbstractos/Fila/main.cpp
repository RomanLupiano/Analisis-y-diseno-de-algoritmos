#include <iostream>
#include "fila.h"

using namespace std;

int main(){
    Fila<int> fila;
    fila.agregar(1);
    fila.agregar(2);
    fila.agregar(3);
    cout << fila.verPrimero() << endl;
    fila.eliminar();
    cout << fila.verPrimero() << endl;
}