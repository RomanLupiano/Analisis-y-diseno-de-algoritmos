class Heap {
    private:
        static const unsigned int MAX = 100;
        int * heap;
        unsigned int cantidad;

    public:
        Heap();                             //O(1)
        ~Heap();                            //O(1) 
        void agregarHeap(unsigned int num); //O(log n)
        bool vacioHeap() const;             //O(1)
        unsigned int raizHeap() const;      //O(1)
        void eliminarHeap();                //O(log n)


        void imprimirHeap() const; //Extra  //O(n)
};

/*
OPERATIONS
    inicHeap: -> Heap;
    AgregarHeap: Heap * Natural -> Heap;
    vacioHeap: Heap -> Boolean;
    raizHeap: Heap(h) -> Natural
        pre: not vacioHeap(h);
    eliminarHeap: -> Heap(h) -> Heap
        pre: not vacioHeap(h)
AXIOMS h: Heap; e: Natural;
    vacioHeap(inicHeap()) = True;
    vacioHeap(AgregarHeap(h, e)) = false;
    
    vacioHeap(h) => raizHeap(AgregarHeap(h, e)) = e;
    (not vacioHeap(h) and e < raizHeap(h)) => raizHeap(agregarHeap(h,e)) = e;
    (not vacioHeap(h) and e >= raizHeap(h)) => raizHeap(agregarHeap(h,e)) = raizHeap(h); 

    vacioHeap(h) => eliminarHeap(AgregarHeap(h, e)) = inicHeap();
    (not vacioHeap(h) and e < raizHeap(h)) => eliminarHeap(agregarHeap(h,e)) = h;
    (not vacioHeap(h) and e >= raizHeap(h)) => eliminarHeap(agregarHeap(h,e)) = agregarHeap(eliminarHeap(h),e);

END-CLASS
*/