Bucles For 
=========

Aunque ``while`` es muy útil en muchas situaciones, 
se puede usar otra estructura iterativa, la declaración ``for``, para iterar fácilmente a 
través de un rango de valores. Una declaración ``for`` nos permite escribir un bucle que se 
ejecuta un número específico de veces.

.. activecode:: ForLoopIterations
   :language: cpp
   :sourcefile: ForLoopIterations.cpp

   #include <iostream>
   using namespace std;

   int main() {
      for (int i = 0; i < 10; i++){
            cout << i << "hola mundo" << endl;
       }
    }



En el ejemplo de arriba, la sentencia **hello world** es ejecutada 10 veces. 

Un uso común de ``for`` es implementar **ciertas** repeticiones en un rango de valores.

.. activecode:: rangeForLoop1
   :language: cpp

   #include <iostream>
   using namespace std;

    // eleva al cuadrado los números en el rango 5
    // por ejemplo: 0*0, 1*1, 2*2 ...
    int main() {
        for (int i=0; i<5; i++) {
            cout << i*i << " ";
        }

        return 0;
    }



El código usará ``cout`` cinco veces. El valor de la variable ``i`` comienza en 0 y sigue en la secuencia
completa de los valores 0,1,2,3,4. Luego este valir es elevado al cuadrado e impreso. 

Compruébalo tu mismo 
==============

::

    #include <iostream>
    using namespace std;

    int main() {

        for (int contador=0; contador<4; contador++) {
            cout << contador * 2 << " ";
        }

        return 0;
    }

.. mchoice:: mc_forloop
  :answer_a: 0 2 4 6
  :answer_b: 0 0 0 0
  :answer_c: Error de tiempo de ejecución
  :answer_d: 0 1 2 3
  :answer_e: todos los anteriores
  :correct: a
  :feedback_a: Buen trabajo!
  :feedback_b: No del todo, revise la operación que ocurre en la línea que imprime.
  :feedback_c: No del todo, revise el bucle for.
  :feedback_d: No del todo, revise la operación que ocurre en la línea que imprime.

  Usando el código anterior, seleccione la respuesta que debería aparecer.
