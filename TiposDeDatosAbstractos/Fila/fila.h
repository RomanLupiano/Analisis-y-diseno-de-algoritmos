template <typename T>
class Fila {
    private:
        struct Nodo
        {
            T elem;
            Nodo * sig;
        };
        Nodo * primero; //Sirve para eliminar/ver el primer elemento
        Nodo * ultimo;  //Sirve para insertar
        Nodo * crearNodo(const T & elem);       //O(1)
        

    public:
        Fila();         //O(1)
        ~Fila();        //O(n)
        void agregar(const T & elem);   //O(1)
        bool esVacia() const;           //O(1)
        const T & verPrimero() const;   //O(1)
        void eliminar();                //O(1)
};

/*
OPERATIONS
    inicFila: -> Fila;                      //Constructora
    agregar: Fila * Elemento -> Fila;       //Constructora
    esVacia: Fila -> Boolean;               //Observadora
    eliminar: Fila(f) -> Fila               //Modificadora
        pre: not esVacia(f);
    verPrimero: Fila(f) -> Elemento         //Observadora
        pre: not esVacia(f);
AXIOMS f: Fila; e: Elemento;
    esVacia(inicFila()) = True;
    esVacia(agregar(f, e)) = False;
    esVacia(f) => eliminar(agregar(f, e)) = f;
    not esVacia(f) => eliminar(agregar(f, e)) = agregar(eliminar(f), e);
    esVacia(f) => verPrimero(agregar(f, e)) = e;
    not esVacia(f) =>  verPrimero(agregar(f, e)) = verPrimero(f);
END-CLASS
*/