class Heap {
    private:
        int * heap;
        unsigned int cantidad;

    public:
        Heap();
        ~Heap();
        void agregarHeap(unsigned int num);
        bool vacioHeap() const;
        unsigned int raizHeap() const;
        void eliminarHeap();
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