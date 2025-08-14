# 1. Problema de la Mochila

Se tienen \(n\) objetos y una mochila. Para \(i = 1, 2, \dots, n\), el objeto \(i\) tiene un peso positivo \(p_i\) y un valor positivo \(v_i\). La mochila puede llevar un peso que no sobrepase \(P\). El objetivo es llenar la mochila de tal manera que se maximice el valor de los objetos transportados, respetando la limitación de capacidad impuesta.

Los objetos pueden ser fraccionados: si una fracción \(x_i\) (\(0 \leq x_i \leq 1\)) del objeto \(i\) es ubicada en la mochila, contribuye en \(x_i p_i\) al peso total de la mochila y en \(x_i v_i\) al valor de la carga.

Formalmente, el problema puede ser establecido como:

\[
\text{maximizar} \quad \sum_{i=1}^{n} x_i v_i,
\quad \text{con la restricción} \quad \sum_{i=1}^{n} x_i p_i \leq P
\]

donde \(v_i > 0\), \(p_i > 0\) y \(0 \leq x_i \leq 1\) para \(1 \leq i \leq n\).

---

**Ejemplo:**  
Para la instancia \(n = 3\) y \(P = 20\):

\[
(v_1, v_2, v_3) = (25, 24, 15)
\]  
\[
(p_1, p_2, p_3) = (18, 15, 10)
\]
