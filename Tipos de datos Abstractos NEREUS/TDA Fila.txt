CLASS Fila [Elemento]  
BASIC CONSTRUCTORS inicFila, agregarFila;  
EFFECTIVE  
TYPE Fila  
OPERATIONS   
    inicFila: -> Fila;  
    agregarFila: Fila * Elemento -> Fila;  
    vaciaFila: Fila -> Boolean;  
    recuperarFila: Fila (f) -> Elemento  
        pre: not vaciaFila(f);  
    eliminarFila: Fila (f) -> Fila  
        pre: not vaciaFIla(f);  
  
AXIOMS f: Fila, e: Elemento;  
    vaciaFila(inicFila()) = True;  
    vaciaFila(agregarFila(f, e)) = false;  
    vaciaFila(f) => recuperarFila(agregarFila(f, e)) = e;  
    not vaciaFila(f) => recuperarFila(agregarFila(f, e)) = recuperarFila(f);  
    vaciaFila(f) => eliminarFila(agregarFila(f, e)) = inicFila();  
    not vaciaFila(f) => eliminarFila(agregarFila(f, e)) = agregarFila(eliminarFila(f), e)  
  
END-CLASS  
