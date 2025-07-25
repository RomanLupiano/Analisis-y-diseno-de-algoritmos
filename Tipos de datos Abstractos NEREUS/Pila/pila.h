template <typename T>
class Pila {
    private:
        struct Nodo
        {
            T elem;
            Nodo * sig;
        };

        Nodo * primero;
        Nodo * crearNodo(const T & elemento);
    

    public:
        Pila(); //Constructor
        ~Pila(); //Destructor
        void agregar(const T & elemento);
        bool eliminar();
        const T & tope() const;
        bool vaciaPila() const;
};

/*
CLASS Pila [Elemento]
BASIC CONSTRUCTORS initPila, agregar
EFFECTIVE
TYPE Pila
OPERATIONS
    initPila: -> Pila;
    agregar: Pila * Elemento -> Pila;
    esVacia: Pila -> Boolean;
    tope: Pila(p) -> Elemento
        pre: not esVacia(p);
    eliminar: Pila(p) -> Pila
        pre: not esVacia(p);
AXIOMS p: Pila; e = Elemento;
    esVacia(initPila()) = True;
    esVacia(agregar(p, e)) = false;
    tope(agregar(p, e)) = e;
    eliminar(agregar(p, e)) = p;

END-CLASS
*/