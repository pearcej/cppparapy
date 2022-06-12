..  Copyright (C)  Jan Pearce and Brad Miller
   This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Cadenas
^^^^^^^
Las **cadenas** o strings son colecciones secuenciales de cero o más caracteres, como letras, 
números y otros símbolos. En realidad, hay dos tipos de cadenas en C++. 
La *cadena de C++* o simplemente la *cadena* de la biblioteca ``<string>`` es el 
tipo más moderno y es muy similar a la clase de cadena de Python. 
La cadena C de estilo antiguo que es esencialmente un array de tipo char. 
El tipo ``char`` en sí es distinto de ambos tipos de cadenas.

::

    char cppchar = 'a';   // los valores char usan simples comillas 
    string cppstring = "Hola Mundo!";  // las cadenas de C++ usan comillas doble.
    char cstring[] = {"Hola Mundo!"};    // C-string o un array char array usa comillas doble.



En versiones anteriores de C++, debe usar un array ``char`` para trabajar con nombres de archivo. En el 
C++ moderno (desde C++11 en adelante), puede usar una cadena de C++ para todo.
Dado que las cadenas de C++ son mucho más agradables y similares a las cadenas de Python, no recomendaría usar cadenas de C.

.. mchoice:: cstringquestion1_1
    :answer_a: Un array o arreglo de caracteres que termina con un carácter nulo de terminación. es decir, \0
    :answer_b: Una estructura de datos secuenciales que consta de cero o más caracteres.
    :answer_c: Una estructura de datos que consta de una colección ordenada de elementos de datos de tipo idéntico en la que cada elemento puede identificarse mediante un índice de el array.
    :answer_d: contenedor de secuencias que almacena datos de un solo tipo que se almacenan en una matriz asignada dinámicamente que puede cambiar de tamaño.
    :correct: a
    :feedback_a: Correcto! una c-string es diferente de una cadena.
    :feedback_b: Estas cerca, pero esa es la definición de una cadena, no de una c-string
    :feedback_c: Incorrecto, eso no es una cadena o una c-string
    :feedback_d: No, eso es un vector.

    ¿Cuál es la definición correcta de c-strings?

Dado que las cadenas son secuencias, todas las operaciones de secuencia típicas funcionan como se espera.
En adición, la biblioteca de cadenas ofrece una gran cantidad de
métodos, algunos de los más útiles se muestran en la :ref:`Tabla 4<tab_stringmethods>`.

.. _tab_stringmethods:

.. table:: **Tabla 4: Métodos de Cadena Proporcionados en C++**

    ===================  ==============================  =========================================================
        **Nombre**                    **Uso**                                           **Explicación**
    ===================  ==============================  =========================================================
                ``[ ]``                  ``astring[i]``                valor de acceso del carácter en el índice i
                  ``=``            ``astring[i]=value``               cambiar el valor del carácter en el índice i
                  ``+``          ``string1 + astring2``                                         concatenar cadenas
             ``append``      ``astring.append(string)``                   Agrega una cadena al final de una cadena
          ``push_back``     ``astring.push_back(char)``                   Agrega un carácter al final de la cadena
           ``pop_back``          ``astring.pop_back()``          Elimina el último carácter del final de la cadena
             ``insert``   ``astring.insert(i, string)``                 Inserta una cadena en un índice específico
              ``erase``         ``astring.erase(i, j)``                      Borra un elemento de un índice a otro
               ``find``          ``astring.find(item)``    Devuelve el índice de la primera aparición del elemento
               ``size``              ``astring.size()``                            Devuelve el tamaño de la cadena
    ===================  ==============================  =========================================================



Emparejar Definiciones
========
.. dragndrop:: matching_strings
   :feedback: Los comentarios muestran coincidencias incorrectas.
   :match_1: [ ]||| Accede al valor de un elemento.
   :match_2: =||| Asigna valor a un elemento. 
   :match_3: push_back||| Adjunta un carácter al final de la cadena.
   :match_4: pop_back||| Elimina el último carácter del final de la cadena. 
   :match_5: insert||| Inyecta una cadena en un índice específico.
   :match_6: erase||| Elimina un elemento de un índice a otro.
   :match_7: size||| Retorna la capacidad de la cadena.
   :match_8: +||| conecta cadenas.
   :match_9: append||| Adjunta una cadena al final de la cadena.
   :match_10: find||| Devuelve el índice de la primera aparición de elemento.

    Relaciona las operaciones de String con su correspondiente explicación.

.. tabbed:: intro_string

  .. tab:: C++

    .. activecode:: introstring_cpp
        :caption: Strings en C++
        :language: cpp

        // Esta función concatena la cadena Hola Mundo
        // Luego dice dónde comienza Mundo en la cadena concatenada.
        #include <iostream>
        #include <string>
        using namespace std;

        int main(){

            string mystring1 = "Hola";
            string mystring2 = "Mundo!";
            string mystring3;

            mystring3 = mystring1 + " " + mystring2;
            cout << mystring3 << endl;

            cout << mystring2 << " comienza en";
            cout << mystring3.find(mystring2) << endl;

            return 0;
        }

  .. tab:: Python

    .. activecode:: introstring_py
        :caption: Cadenas o Strings en Python 

        """Esto hace lo mismo que la función de C++"""
        def main():
            mystring1 = "Hola"
            mystring2 = "Mundo!"

            mystring3 = mystring1 + " " + mystring2
            print(mystring3)

            print(mystring2, end=" ")
            print("comienza en", end=" ")
            print(str(mystring3.find(mystring2)))

        main()


Comprueba tu comprensión completando la siguiente pregunta.

.. dragndrop:: string_types
   :feedback: Los comentarios muestran coincidencias incorrectas.
   :match_1: char|||'a'
   :match_2: char array|||{'a'}
   :match_3: string|||"a"


   Arrastre cada tipo de datos a su correspondiente sintaxis de inicialización de C++.
