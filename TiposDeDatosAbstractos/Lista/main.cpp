#include <iostream>
#include "Lista.h"

using namespace std;

int main(){
    Lista lista;
    lista.agregar(1, 10);
    cout << lista.recuperar(1) << endl;
    return 0;
}