..  Copyright (C)  Jan Pearce
   This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Conjuntos desordenados
^^^^^^^^^^^^^^

Un **conjunto_desordenado** es una colección desordenada de cero o más valores de datos únicos de C++
de un tipo particular.
Para usar unordered_sets, importe ``unordered_set`` de la biblioteca de plantillas estándar con
``#incluye <conjunto_desordenado>``.

Unordered_sets permite la recuperación rápida de elementos individuales en función de su valor.
En un conjunto_desordenado, el valor de un elemento es al mismo tiempo su clave, que lo identifica de manera única.
Las ``claves`` son **inmutables**, por lo tanto, los elementos en un ``unordered_set`` no se pueden modificar una vez en el contenedor -
Sin embargo, se pueden insertar y quitar.


Los conjuntos no ordenados no permiten duplicados y se inicializan utilizando caracteres delimitados por comas.
valores encerrados entre llaves. La colección se puede asignar a
una variable como se muestra a continuación.


::

    set<int> mySet = {3, 6, 4, 78, 10}


Los conjuntos desordenados admiten una serie de métodos que deberían ser familiares para aquellos que
han trabajado con conjuntos en un entorno matemático. :ref:`Tabla 6 <tab_setmethods>`
proporciona un resumen. A continuación se muestran ejemplos de su uso.

.. _tab_setmethods:

.. table:: **Tabla 6: Métodos proporcionados por conjuntos en C++**

    ======================== ================================= ================================================================
             **Nombre**                           **Uso**                                                  **Explanación**
    ======================== ================================= ================================================================
                   ``union``                   ``set_union()``   Retorna un conjunto con todos los elementos de ambos conjuntos
            ``intersection``            ``set_intersection()``   Retorna un nuevo conjunto con solo los elementos comunes a ambos conjuntos
              ``difference``              ``set_difference()``    Devuelve un nuevo conjunto con todos los elementos del primer conjunto, no del segundo.
                     ``add``             ``aset.insert(item)``                                   Agrega un elemento al conjunto
                  ``remove``              ``aset.erase(item)``                                 Elimina el artículo del conjunto
                   ``clear``                  ``aset.clear()``                         Elimina todos los elementos del conjunto
    ======================== ================================= ================================================================

El siguiente código es un ejemplo de un programa que puede detectar si un carácter específico está en un conjunto desordenado.

.. activecode:: Unordered_set_example
    :language: cpp
    
    // Función que comprueba si un char
    // está en el conjunto desordenado
    #include <iostream>
    #include <unordered_set>
    using namespace std;

    void checker(unordered_set<char> set, char letter){
        if(set.find(letter) == set.end()){
            cout << "la letra " << letter << " no está en el conjunto." << endl;
        }
        else{
            cout << "la letra " << letter << " está en el conjunto." << endl;
        }
    }

    int main(){
    unordered_set<char> charSet = {'d', 'c', 'b', 'a'};

    char letter = 'e';
    checker(charSet, letter);
    charSet.insert('e');
    checker(charSet, letter);
    return 0;
    }

el método ``find`` usado para un condicional en ``Checker`` compara
cada elemento del conjunto con el parámetro dado hasta que haya una coincidencia. la
La sección ``set.find(letter) == set.end()`` significa que si ``find`` no puede
encuentra la ``letra`` antes de llegar al final del conjunto, luego ``letra``
no está contenido en el conjunto.

Emparejar definiciones
========
.. dragndrop:: matching_us
   :feedback: Los comentarios muestran coincidencias incorrectas.
   :match_1: union||| Devuelve un nuevo conjunto con todos los elementos de ambos conjuntos.
   :match_2: intersección||| Devuelve un nuevo conjunto con solo los elementos comunes a ambos conjuntos.
   :match_3: difference||| Devuelve un nuevo conjunto con todos los elementos del primer conjunto, no del segundo.
   :match_4: add||| Añade un elemento al conjunto.
   :match_5: remove||| borra el elemento del conjunto.
   :match_6: clear|||Elimina todos los elementos del conjunto.

Relaciona las operaciones de Conjuntos no Ordenados con su correspondiente explicación.

Resumen
^^^^^^^

1.  Un array de C++ asignado estáticamente es una colección ordenada de uno o más valores de datos de C++ de tipo idéntico almacenados en memoria contigua.

2. Un vector es un array asignado dinámicamente con muchos métodos útiles. Es más similar a la lista de Python que a la matriz.

3. Las cadenas C++ son una colección secuencial de cero o más caracteres. Son muy similares a las cadenas de Python.

4. Se utiliza una tabla hash para almacenar pares clave-valor. Aplica una función hash relacionada a la clave para calcular la ubicación del valor asociado. La búsqueda suele ser muy rápida.

5. Un conjunto es una colección desordenada de valores únicos.

Compruébalo tú mismo
^^^^^^^^^^^^^^


.. mchoice:: mc_fixed
   :answer_a: array
   :answer_b: tabla hash 
   :answer_c: string
   :answer_d: vector
   :answer_e: Más de una de las anteriores
   :correct: a
   :feedback_a: Correcto!
   :feedback_b: No. las tablas hash no están ordenadas.
   :feedback_c: Una cadena solo funcionaría para datos de caracteres. Intentar otra vez.
   :feedback_d: Hay una mejor opción dado que el grupo tiene una longitud fija
   :feedback_e: Solo uno de lo anteriores es el mejor.

   ¿Qué estructura de C++ es la mejor opción para un grupo de datos ordenados de longitud fija?



.. dragndrop:: collect_data_types
   :feedback: Los comentarios muestran coincidencias incorrectas.
   :match_1: Array|||{“Que”, “Soy”, “Yo”, "estoy"}
   :match_2: Set|||{“Que”, “Soy”, “Yo”}
   :match_3: String|||“Que Soy Yo”
   :match_4: Tabla Hash|||{​{“Que”, “soy Yo”}​}

    Arrastre cada tipo de datos a su correspondiente sintaxis de inicialización de C++.
