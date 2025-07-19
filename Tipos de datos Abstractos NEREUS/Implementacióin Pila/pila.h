template <typename T>
class Pila {

    struct Nodo
    {
        T elem;
        Nodo * anterior;
    };

    Nodo * primero;
    

    public:
        Pila(); //Constructor
        ~Pila(); //Destructor
        void agregarPila(const T & elemento);
        bool eliminarPila();
        const T & tope() const;
        bool vaciaPila() const;
};