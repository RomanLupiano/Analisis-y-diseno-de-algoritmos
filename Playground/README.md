# Práctica de Programación

## 1. Hola Mundo

Escribir un programa que imprima el mensaje:

```
Hola mundo
```

## 2. Multiplicación de dos números

Escribir un programa que:

- Lea dos números ingresados por teclado (separados por un espacio).
- Los multiplique.
- Imprima el resultado por pantalla.


## 3. Concatenación de cadenas

Escribir un programa que:

- Lea dos cadenas de caracteres ingresadas por teclado (separadas por un espacio).
- Las concatene.
- Imprima el resultado por pantalla.


## 4. Raíces de una ecuación de segundo grado

Dada la ecuación:

```
ax² + bx + c = 0
```

Calcular el discriminante:

```
discr = b² - 4ac
```

Dependiendo de su valor:

- Si `discr > 0`:  
  Las raíces son reales y distintas:  
  ```
  x1 = (-b + √discr) / (2a)
  x2 = (-b - √discr) / (2a)
  ```

- Si `discr == 0`:  
  Las raíces son reales e iguales:  
  ```
  x1 = x2 = -b / (2a)
  ```

- Si `discr < 0`:  
  Las raíces son complejas conjugadas:  
  ```
  xr = -b / (2a)
  xi = √(-discr) / (2a)
  ```

**Objetivo**: codificar un programa que calcule las raíces ingresando `a`, `b` y `c`.


## 5. Rentabilidad de un fondo de inversión

Un banco ofrece un 35% anual con pagos mensuales (interés compuesto mensual).  
Cada mes se capitaliza el monto acumulado.

Escribir un programa que:

- Reciba un monto y un plazo en días.
- Calcule la rentabilidad esperada.

📌 *Ejemplo*:  
Inversión: `$10.000`  
Plazo: `60 días`  
Rentabilidad aproximada: `$591`


## 6. Reemplazo de caracteres desde argumentos

Escribir un programa que:

- Lea un mensaje desde el teclado.
- Reemplace un carácter por otro según los argumentos pasados a `main`.

📌 *Ejemplo de ejecución*:

```
<proyecto.exe> A B
```

Esto reemplaza cada ocurrencia de `A` por `B`.

Se debe:

- Validar que se pasen los argumentos correctamente.
- Notificar si faltan.

## 7. Elemento mayoría en un arreglo

Escribir una función que:

- Reciba un arreglo de `N` números naturales.
- Determine si existe un **elemento mayoría** (aparece más de `N/2` veces).
- Retorne si existe, y cuántas veces aparece.


## 8. Invertir un arreglo

Escribir un programa que:

- Lea desde entrada estándar:
  - Una línea con la cantidad de elementos.
  - Una línea con los valores separados por espacio.
- Imprima los valores en orden **inverso**.

📌 *Ejemplo*:

**Entrada:**
```
5
10 2 3 1 7
```

**Salida:**
```
7 1 3 2 10
```


## 9. Verificar primos en un arreglo

Escribir:

1. Una función que determine si un número entero es **primo**.
2. Un programa que verifique si **cada número** en un arreglo es primo o no.