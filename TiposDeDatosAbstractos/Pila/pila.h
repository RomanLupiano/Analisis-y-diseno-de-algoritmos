template <typename T>
class Pila {
    private:
        struct Nodo
        {
            T elem;
            Nodo * sig;
        };

        Nodo * primero;
        Nodo * crearNodo(const T & elemento); //O(1);
    

    public:
        Pila(); //Constructor               O(1)
        ~Pila(); //Destructor               O(n) (Porque recorre todos los elementos (n) para eliminarlos)
        void agregar(const T & elemento); //O(1);
        bool eliminar();                  //O(1);
        const T & tope() const;           //O(1);
        bool vaciaPila() const;           //O(1);
};