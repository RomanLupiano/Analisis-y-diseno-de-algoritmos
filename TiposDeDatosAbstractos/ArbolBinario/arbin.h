template <typename T>
class Arbin {
    private:
        struct Nodo {
            T elem;
            Nodo * izq; 
            Nodo * der;
        };
        Nodo * primero;
        unsigned int cantidad;

    public:
        Arbin();                                            //O(1)
        ~Arbin();                                           //O(n)
        bool vacioArbin() const;                            //O(1) 
        const T & raiz() const;                             //O(1)
        const Arbin<T> * subIzquierdo() const;              //O(1)
        const Arbin<T> * subDerecho() const;                //O(1)
        bool existeElemento(const T& elem) const;           //O(n)
        int altura() const;                                 //O(n)
        unsigned int cantidadNodos() const;                 //O(1)
        bool esHoja() const;                                //O(1)
        bool operator== (const Arbin<T> & otroArbol) const; //O(n)
        Arbin<T> & operator= (const Arbin<T> & otroArbol);  //O(n)

        void preorden() const;
        void inorden() const;
        void postorden() const;

        int sumaNodos() const;
        void imprimirImpares() const;
        int mayor() const;
        int maximaDiferencia() const;
        int [] ramaMasLiviana() const;
};