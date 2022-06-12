..  Copyright (C)  Jan Pearce
   This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.

Tablas Hash 
^^^^^^^^^^^
Si ha utilizado un diccionario de Python, entonces ha utilizado una *tabla hash*.
Una **tabla hash** es una colección de pares asociados de
elementos donde cada par consta de una *llave* y un *valor*.
Las tablas hash a menudo se denominan con el término más general *mapa*
porque la función hash asociada "asigna" la clave al valor.
Sin embargo, es mejor usar el término más preciso, *tabla hash*
porque a veces se implementan otros tipos de mapas con una estructura de datos subyacente diferente.

Each hash table has a *hash function* which
given the key as input to the hash function
returns the location of the associated value as the output.
This makes look up fast.

Cada tabla hash tiene una *función hash* que
dada la llave que se usa, la función hash 
devuelve la ubicación del valor asociado. Esto hace que la búsqueda de elementos sea rápida.

En Python, el tipo de datos del diccionario representa la implementación de la tabla hash.
En C++, el *unordered_map* implementa la tabla hash, y la biblioteca ``<unordered_map>``
debe incluirse de la siguiente manera:

::

  #include <unordered_map>

La sintaxis para el acceso a la tabla hash es muy similar a la que podríamos esperar
excepto que en lugar de usar el índice del elemento para buscar,
usa la llave. Tanto en Python como en C++, las tablas hash se pueden inicializar con pares llave-valor y
Los pares llave-valor también se pueden agregar más tarde, como vemos en el siguiente ejemplo.
En C++, la palabra clave ``first`` se usa para la clave, y ``second`` se usa para el
valor asociado.

.. tabbed:: hashtable1

    .. tab:: C++

        .. activecode:: hashtable1_cpp
            :caption: Usando una Tabla Hash en C++
            :language: cpp

            // Crea una tabla hash table que concuerda
            // la carta en inglés a su equivalente en Español.
            // y muestra el tamaño de 
            // la tabla a la consola
            #include <iostream>
            #include <unordered_map>
            #include <string>
            using namespace std;

            int main() {
                unordered_map<string, string> spnumbers;

                spnumbers = { {"one", "uno"}, {"two", "dos"} };

                spnumbers["three"] = "tres";
                spnumbers["four"] = "cuatro";

                cout << "one is ";
                cout << spnumbers["one"] << endl;

                cout << spnumbers.size() << endl;
            }

    .. tab:: Python

        .. activecode:: hashtable1_py
            :caption: Usando un Dictionario

            """ Equivalent en Python 
            del código en C++"""
            def main():
                spnumbers = {"one":"uno","two":"dos"}

                spnumbers["four"]="cuatro"
                spnumbers["three"]="tres"

                print("one is", end=" ")
                print(spnumbers["one"])

                print(len(spnumbers))
            main()


Es importante tener en cuenta que las tablas hash están organizadas por la ubicación dada
por la función hash en lugar de estar en cualquier
orden particular con respecto a las llaves. Esto hace que la búsqueda sea extremadamente rápida.
Por lo tanto, aunque es posible iterar a través de una tabla hash tanto en C++ como en Python,
es algo raro de hacer
porque los datos normalmente no se almacenan secuencialmente.
Los iteradores de un ``unordered_map`` son
implementado usando punteros para apuntar a elementos del tipo de valor como vemos en
el siguiente ejemplo.

.. tabbed:: hashtable2

    .. tab:: C++

        .. activecode:: hashtable2_cpp
            :caption: Iterating a Hash Table C++
            :language: cpp

            // Crea una tabla hash que concuerda
            // con la palabra en Inglés con su equivalente en Español 
            // y los muestra todos los valores
            // que estan en la tabla a la consola
            #include <iostream>
            #include <unordered_map>
            #include <string>
            using namespace std;

            int main() {
                unordered_map<string, string> spnumbers;

                spnumbers = { {"one","uno"},{"two","dos"},{"three","tres"},{"four","cuatro"},{"five","cinco"} };

                for (auto i=spnumbers.begin(); i!=spnumbers.end(); i++ ){
                    //auto se utiliza para detectar automáticamente el tipo de datos cuando
                    //una variable es declarada. Use esto SOLO cuando declare variables complejas
 
                    cout << i->first << ":";
                    cout << i->second << endl;
                }
            }

    .. tab:: Python

        .. activecode:: hashtable2_py
            :caption: Iterando un Dictionary

            """ Equivalente de Python
            del código en C++ """
            def main():
                spnumbers = {"one":"uno","two":"dos","three":"tres","four":"cuatro","five":"cinco" }

                for key in spnumbers:
                    print(key, end=":")
                    print(spnumbers[key])

            main()


Las tablas hash tienen métodos y operadores. :ref:`Tabla 7 <tab_hashopers>`
describes them, and the session shows them in action.

.. _tab_hashopers:

.. table:: **Tabla 7: Importantes Operadores de Tablas Hash proporcionados en C++**

    ===================== ========================= ================================================================
             **Operador**                   **Uso**                                                  **Explanación**
    ===================== ========================= ================================================================
                 ``[ ]``               ``mymap[k]``        Retorna el valor asociado con ``k``, si no lanza un error
                ``count``    ``mymap.count(llave)``  Retorna ``true`` si la llave está en ``mymap``, ``false`` si no
                ``erase``    ``mymap.erase(llave)``                                  Elimina la entrada de ``mymap``
                ``begin``         ``mymap.begin()``                      Un iterador al primer elemento en ``mymap``
                  ``end``           ``mymap.end()``  iterador que apunta al elemento más allá del final de ``mymap``
    ===================== ========================= ================================================================


Emparejar definiciones
========
.. dragndrop:: matching_HT
   :feedback: Los comentarios muestran coincidencias incorrectas.
   :match_1: [ ]|||Devuelve el valor asociado a la clave, de lo contrario arroja un error.
   :match_2: erase|||Elimina la entrada de la tabla hash.
   :match_3: count|||Devuelve verdadero si la clave está en la tabla hash y falso en caso contrario.
   :match_4: begin|||Un iterador del primer elemento de la tabla hash.
   :match_5: end|||Un iterador que apunta al elemento más allá del final de la tabla hash.

    Une las operaciones de la Tabla Hash con su explicación correspondiente.

