#ifndef LISTA_H
#define LISTA_H

class Lista {
    private:
        struct Nodo {
            int elemento;
            Nodo * sig;
        };
        Nodo * primero;
        Nodo * crearNodo(int num, Nodo * sig);          //O(1)
        unsigned int cantidad;

    public:
        Lista();                            //O(1)
        ~Lista();                           //O(n)
        void agregar(unsigned int pos, int elem);    //O(n)
        unsigned int longitud() const;     //O(1)
        int recuperar(unsigned int pos) const;        //O(n)
        bool eliminar(unsigned int pos);        //O(n)


        void mostrarLista() const;          //O(n)
};

#endif

/*
OPERATIONS
    inicLista: -> Lista; -                                          --> Lista();
    agregarLista: Lista(l) * Natural(i) * Elemento -> Lista         --> 
        pre: (i >= 1) and (i <= longLista(l)+1);
    longLista: Lista -> Natural;
    recuperarLista: Lista(l) * Natural(i) -> Elemento
        pre: (i >= 1) and (i <= longLista(l));
    eliminarLista: Lista(l) * Natural(i) -> Lista
        pre: (i >= 1) and (i <= longLista(l));

AXIOMS l:Lista, i, j:natural, e:Elemento;
    longLista(inicLista()) = 0;
    longLista(agregarLista(l, i, e)) = longLista(l) + 1;

    (i == j) => eliminarLista(agregarLista(l, i, e), j) = l;
    (i < j) => eliminarLista(agregarLista(l, i, e), j) = agregarLista(eliminarLista(l, j-1), i, e);
    (i > j) => eliminarLista(agregarLista(l, i, e), j) = agregarLista(eliminarLista(l, j), i-1, e);

    (i == j) => recuperarLista(agregarLista(l, i, e), j) = e;
    (i < j) => recuperarLista(agregarLista(l, i, e), j) = recuperarLista(l, j-1);
    (i > j) => recuperarLista(agregarLista(l, i, e), j) = recuperarLista(l, j);

END-CLASS
*/