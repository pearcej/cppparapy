Bucles While 
============

Como señalamos anteriormente, los algoritmos requieren dos estructuras de control importantes: 
iteración y selección. Ambos son compatibles con Python en varias formas. El programador puede 
elegir la declaración que sea más útil según la circunstancia.

Para repetir un bloque de código, C++ proporciona construcciones estándar ``while`` y ``for``. 
La construcción ``while`` repite un cuerpo de código siempre y cuando una condición sea verdadera. Por ejemplo,

::

    int contador = 1;
    while (contador <= 5) {          /*Uso de un método interactivo hasta que
                                     el bucle termina  */
        cout << "Hola, mundo" << endl;
        contador = contador + 1;
    }

    Console output:
    Hola, mundo
    Hola, mundo
    Hola, mundo
    Hola, mundo
    Hola, mundo


Imprime la frase “Hola, mundo” cinco veces. La condición en la sentencia
``while`` es evaluada al comienzo de cada repetición. Si la condición 
es verdad ``true``, se ejecutará el cuerpo.

La declaración while es una estructura iterativa de propósito muy general 
que usaremos en varios algoritmos diferentes. En muchos casos, una condición 
compuesta controlará la iteración. Un fragmento como:
::

    while ((contador <= 10) && (!done)) {
    ...



haría que el cuerpo de la declaración se ejecutara solo en el caso de que ambas partes de la condición
se cumplan debido al operador and  (``&&``). El valor de la variable ``contador`` tendría que ser menor o igual
a 10 y el valor de la variable ``done``  tendría que ser ``falso`` (``no falso`` es ``verdadero``)  para que ``true and true``  resulten en ``verdadero``.

Estos son algunos de los operadores lógicos que son útiles para declaraciones booleanas de verdadero o 
falso en C++.

::

    y           - &&

    o          - ||

    no igual a  - !=

    no         - !

    más que  - >

    menos que   - <

    mayor que 
    o igual a  - >=

    menos que
    o igual a - <=


Estos son los mismos que vimos en capítulos anteriores.


::

    #include <iostream>
    using namespace std;

    int main(){
        int contador = 0;
        while (contador <= 1) {
            cout << "Hola, mundo!" << endl;
        }
    };


.. mchoice:: mc_whileloop
  :answer_a: "0" es escrito 1 vez.
  :answer_b: "Hola mundo!" es escrito 1 vez.
  :answer_c: "Hola mundo!" is written infinitely many times.
  :answer_d: Ninguno de los anteriores.
  :correct: c
  :feedback_a: Revise la línea que imprime.
  :feedback_b: Revisa el bucle while 
  :feedback_c: Correcto! porque contador es nunca mayor que uno hace que el buble while se infinito.
  :feedback_d: No del todo, revisa nuevamente.

  Usando el código anterior, seleccione la respuesta que debería aparecer.
