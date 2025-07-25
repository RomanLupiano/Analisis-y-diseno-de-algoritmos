class Lista {
    private:
        struct Nodo {
            int elemento;
            Nodo * sig;
        };
        Nodo * primero;
        Nodo * crearNodo(int num);

    public:
        Lista();
        ~Lista();
        void agregarNodo(int num);
        void mostrarLista() const;
        unsigned int longLista() const;
        Nodo * recuperarLista(int num);
        bool eliminarLista(int num);
};


/*
OPERATIONS
    inicLista: -> Lista; -                                          --> Lista();
    agregarLista: Lista(l) * Natural(i) * Elemento -> Lista         --> 
        pre: (i >= 1) and (i <= longLista(l)+1);
    longLista: Lista -> Natural;
    recuperarLista: Lista(l) * Natural(i) -> Lista
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