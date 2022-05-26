Condicionales 
============

Las declaraciones condicionales son muy similares en Python y C++.

El Sencillo if
---------
En Python, declaramos una condicional if de la siguiente manera:

::

    if condición:
        sentencia1
        sentencia2
        ...

En C++ este mismo patrón se escribe como:

::

    if (condición) {
        sentencia1
        sentencia2
        ...
    }

Una vez más, puede ver que en C++ las llaves definen un bloque 
en lugar de una sangría. En C++, los paréntesis alrededor de la 
condición son necesarios porque ``if`` es técnicamente una función 
que se evalúa como ``verdadero`` o ``falso``.

if else
-------
La declaración de if-else en Python se ve así:

::

    if condición:
        sentencia1
        sentencia2
        ...
    else:
        sentencia1
        sentencia2
        ...

En C++ esto es escrito así:

::

    if (condición) {
        declaración1
        declaración2
        ...
    } 
    else {
        declaración1
        declaración2
        ...
    }

elif
------------------

C++ no tiene un patrón elif como en Python. En C++ puede obtener la funcionalidad de 
una declaración elif anidando if y else. Aquí hay un ejemplo simple tanto en Python como en C++.


.. activecode:: pyelif
    :language: python

    #muestra las declaraciones if,elif, y else en Python
    def main():
        nota = 85

        if (nota < 60):
            print('F')
        elif (nota < 70):
            print('D')
        elif nota < 80:
            print('C')
        elif nota < 90:
            print('B')
        else:
            print('A')

    main()


En C++ tenemos un par de formas de escribir esto.

.. activecode:: cppelif
   :language: cpp
   :sourcefile: elseif.cpp

    // Muestra cómo usar declaraciones condicionales.
    #include <iostream>
    using namespace std;

    int main() {

        int nota = 85;

        if (nota < 60) {
          cout<<'F'<< endl;
        } 
        else {      /* sentencias if, elif, y else pueden ser usadas dentro de ellas 
                        para permitir sub opciones */
            if (nota < 70) {
                cout<<'D'<< endl;
            } 
            else {
                if (nota < 80) {
                    cout<<'C'<< endl;
                } 
                else {
                    if (nota < 90) {
                        cout<<'B'<< endl;
                    } 
                    else {
                        cout<<'A'<< endl;
                    }
                }
            }
        }
        return 0;
    }


Podemos enfocarnos más en cómo luce la sentencia elif en C++ aprovechando la regla de C++ de que no es necesario
encerrar una única sentencia entre llaves. Dado que if es la única sentencia utilizada en cada una, podemos
resolver esto de la siguiente manera.

.. activecode:: cppelif2
   :language: cpp
   :sourcefile: elseif2.cpp

    // Muestra como poner juntas las sentencias condicionales,
    // especificamente como poner "else if" después de una sentencia "if".
    #include <iostream>
    using namespace std;

    int main() {

        int nota = 85;

        if (nota < 60) {
            cout<<'F'<<endl;
        } 
        else if (nota < 70) {
            cout<<'D'<<endl;
        } 
        else if (nota < 80) {
            cout<<'C'<<endl;
        } 
        else if (nota < 90) {
            cout<<'B'<<endl;
        } 
        else  cout<<'A'<<endl;

        return 0;
    }

Compruébalo tú mismo
~~~~~~~~~~~~~~

.. mchoice:: mc_cpp_elsecond
   :answer_a: Verdadero
   :answer_b: Falso
   :correct: b
   :feedback_a: No realmente, intente modificar el código anterior para probarlo.
   :feedback_b: Buen trabajo!

   T/F: Es necesario tener una sentencia else después de una sentencia if. (Ayuda: Puede probarlo con el código de arriba.)

switch
------

C++ también admite una declaración de ``switch`` es como una 
declaración elif de Python bajo ciertas condiciones porque la declaración 
toma casos y verifica la validez del caso dependiendo del código. Utiliza casos en lugar 
de condiciones y el caso debe basarse en números enteros o en un tipo de datos 
definido por el usuario denominado constante enumerada.

Para escribir el programa para calcular notas usando la declaración switch
usaríamos lo siguiente:

.. activecode:: cppswitch
   :language: cpp
   :sourcefile: switchup.cpp

    // Muestra como usar la sentencia Switch.

    #include <iostream>
    using namespace std;

    int main() {

        int nota = 85;

        int tempnota = nota/10;
        switch(tempnota) {  /* los casos switch permiten for different options based on
                            the value of temp nota similar to if statements*/

        los casos permiten diferentes opciones basadas en el valor del grado temporal similar a las declaraciones if
        case 10:
        case 9:
            cout << "The nota is A" << endl;
            break;
        case 8:
            cout << "The nota is B" << endl;
            break;
        case 7:
            cout << "The nota is C" << endl;
            break;
        case 6:
            cout << "The nota is D" << endl;
            break;
        default:
            cout << "The nota is F" << endl;
        }

        return 0;
    }


Honestamente, la declaración ``switch`` no se usa muy frecuentemente. No es tan poderoso 
como el modelo ``else if`` porque la variable switch solo se puede comparar para la 
igualdad con un número entero o algo llamado constante enumerada. También, 
es muy fácil olvidarse de poner la sentencia ``break``. Note arriba cómo los casos 10 y 
9 están codificados juntos. Si se omite la instrucción break, la siguiente alternativa 
se ejecutará automáticamente. Por ejemplo, si la calificación fue 95 y se omitió el ``break`` 
de la alternativa ``case 9:`` entonces el programa imprimiría ambos (A y B). Por lo tanto, es 
posible que desee evitarlo y usar if...

Compruébalo tú mismo
~~~~~~~~~~~~~~

.. mchoice:: mc_cpp_ifcond
   :answer_a: { }
   :answer_b: [ ]
   :answer_c: ( )
   :answer_d: Se puede utilizar cualquier juego de llaves.
   :answer_e: ninguna de las anteriores.
   :correct: c
   :feedback_a: No. Intente nuevamente.
   :feedback_b: No. Intente nuevamente.
   :feedback_c: Correcto!
   :feedback_d: No. Intente nuevamente.
   :feedback_e: Uno de los anteriores es correcto.

   Al indicar la condición para una sentencia if de C++, ¿qué símbolos se utilizan?

.. mchoice:: mc_cpp_switch
  :answer_a: Terminando las sentencias con ;
  :answer_b: Usando una sentencia break 
  :answer_c: Encerrando cada caso con { }
  :answer_d: Establecer un caso predeterminado
  :correct: b
  :feedback_a: No. Esto es siempre necesario.
  :feedback_b: Buen trabajo!
  :feedback_c: No. Intente nuevamente.
  :feedback_d: No. Es una buena idea, pero no ayudará.

  Cuando usa una sentencia switch, ¿qué impide que todos los casos pasen como correctos?


.. mchoice:: mc_cpp_and
  :answer_a: ||
  :answer_b: and
  :answer_c: !
  :answer_d: &&
  :correct: d
  :feedback_a: No, esto significa "or".
  :feedback_b: No, esto es en Python.
  :feedback_c: No, esto significa "not"
  :feedback_d: Muy bien!

  ¿Qué símbolo se usa para indicar "and" en C++ como en una condición compuesta?
