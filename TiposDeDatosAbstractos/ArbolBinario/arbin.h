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
        void crearArbin(const Arbin<T> & der, T & elem);    //O(1)
        bool vacioArbin() const;                            //O(1) 
        const T & raiz() const;                             //O(1)
        const Arbin<T> * subIzquierdo() const;              //O(1)
        const Arbin<T> * subDerecho() const;                //O(1)
        bool existeElemento(const T& elem) const;                 //O(n)
        int altura() const;                                 //O(n)
        unsigned int cantidadNodos() const;                 //O(1)
        bool esHoja() const;                                //O(1)
        bool operator== (const Arbin<T> & otroArbol) const; //O(n)
};

/*
OPERATIONS
    inicArbin: -> Arbin;
    crearArbin: Arbin * Arbin * Elemento -> Arbin;
    vacioArbin: Arbin -> Boolean;
    raiz: Arbin(t) -> Elemento
        pre: not vacioArbin(t);
    subIzquierdo: Arbin (t)-> Arbin
        pre: not vacioArbin(t);
    subDerecho: Arbin (t) -> Arbin
        pre: not vacioArbin(t);
    existeElemento: Arbin(t) * Elemento -> Boolean
        pre: not vacioArbin(t);
    altura: Arbin -> Integer;
    cantidadNodos: Arbin -> Natural;
    esHoja: Arbin(t) -> Boolean
        pre: not vacioArbin(t);
    _==_: Arbin * Arbin -> Boolean;
AXIOMS t1,t2: Arbin; e, e1: Elemento;
    vacioArbin (inicArbin ()) = True;
    vacioArbin (crearArbin(t1,t2,e)) = False;
    raiz(crearArbin(t1,t2,e)) = e;
    subIzquierdo(crearArbin(t1,t2,e)) = t1;
    subDerecho(crearArbin(t1,t2,e)) = t2;
    
    existeElemento(inicArbin (), e1) = False;
    existeElemento(crearArbin(t1,t2,e), e1) = (e==e1) or existeElemento(t1, e1) or existeElemento(t2, e1);

    altura(inicArbin ()) = -1;
    (altura(t1) >= altura(t2)) => altura(crearArbin(t1,t2,e)) = 1 + altura(t1);
    (altura(t1) < altura(t2)) => altura(crearArbin(t1,t2,e)) = 1 + altura(t2);

    cantidadNodos(inicArbin ()) = 0;
    cantidadNodos(crearArbin(t1,t2,e)) = 1 + cantidadNodos(t1) + cantidadNodos(t2);

    (vacioArbin(t1) and vacioArbin(t2)) => esHoja(crearArbin(t1,t2,e)) = True;
    not (vacioArbin(t1) and vacioArbin(t2)) => esHoja(crearArbin(t1,t2,e)) = False;

    (e==e1) => crearArbin(t1,t2,e) == crearArbin(t3,t4,e1) = (t1==t3) and (t2==t4);
    not (e==e1) => crearArbin(t1,t2,e) == crearArbin(t3,t4,e1) = false;
    inicArbin() == inicArbin() = True;
END-CLASS
*/