..  Copyright (C)  Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike
    4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.

Vectors
-------
Los **vectores** son mucho más similares a las listas de Python que los arrays. Los vectores usan un array asignada 
dinámicamente para almacenar sus elementos, por lo que pueden cambiar de tamaño y también tienen otras características amigables. 
Debido a que usan un array asignado dinámicamente, usan ubicaciones de almacenamiento contiguas, lo que significa que se puede 
acceder a sus elementos y recorrerlos, y también se puede acceder a ellos aleatoriamente mediante índices. Sin embargo, los vectores 
tienen un tamaño dinámico, por lo que su tamaño puede cambiar automáticamente. Se puede insertar o eliminar un nuevo elemento de 
cualquier parte de un vector, y se aplicará la reasignación automática para otros elementos existentes en el vector. A diferencia 
de las listas de Python, los vectores son homogéneos, por lo que todos los elementos del vector deben ser del mismo tipo.

Los vectores son una clase que está disponible a través de una biblioteca llamada Biblioteca de plantillas estándar (STL), 
y se usa una notación < > para indicar el tipo de datos de los elementos. Para usar vectores, es necesario incluir la biblioteca de vectores.

::

    #include <vector>


.. _tbl_vectorbasics:

.. table:: **Common C++ Vector Operators**


    ===================== ============================= ====================================================
     **Operación del vector**     **Uso**           **Explicación**
    ===================== ============================= ====================================================
                  ``[ ]``               ``myvector[i]``                   access value of element at index i
                    ``=``         ``myvector[i]=value``                   assign value to element at index i
            ``push_back``    ``myvect.push_back(item)``            Appends item to the far end of the vector
             ``pop_back``         ``myvect.pop_back()``      Deletes last item (from  far end) of the vector
               ``insert``    ``myvect.insert(i, item)``                           Inserts an item at index i
                ``erase``           ``myvect.erase(i)``                       Erases an element from index i
                 ``size``             ``myvect.size()``             Returns the actual size used by elements
             ``capacity``         ``myvect.capacity()``       Returns the size of allocated storage capacity
              ``reserve``    ``myvect.reserve(amount)``               Request a change in capacity to amount
    ===================== ============================= ====================================================




Una tarea de programación muy común es hacer crecer un vector usando el método ``push_back()`` para agregarlo 
al vector como vemos en el siguiente ejemplo. Debido a que los vectores pueden cambiar de tamaño, los vectores 
suelen asignar algo de almacenamiento adicional para adaptarse a un posible crecimiento. Por lo tanto, el vector 
normalmente tiene una capacidad real mayor que el *tamaño* de almacenamiento estrictamente necesario para contener 
sus elementos.

Iterando a través de Vectores
~~~~~~~~~~~~~~~~~~~~~~~~~
Al iterar vectores, primero debe encontrar la longitud de su contenedor. 
Simplemente puede llamar a la función ``.length()``. Para los arrays, 
el número de elementos se puede encontrar obteniendo el tamaño en 
la memoria del array usando la función ``sizeof()``, y luego dividiéndolo 
por el tamaño del primer elemento del arreglo usando la misma función 
``sizeof()``. Debido a que todos los elementos en las matrices de C++ 
son del mismo tipo, ocupan la misma cantidad de espacio y eso se puede 
usar para encontrar la cantidad de elementos que contiene el array!

.. activecode:: vectorIteration1
   :language: cpp
   :sourcefile: ArrayIteration.cpp

   #include <iostream>
   using namespace std;

   int main() {
       int nums[] = {1,3,6,2,5};
       //Dividir el tamaño del array (en bytes) por el tamaño de un solo elemento (en bytes)
       // para obtener el número total de elementos del array.
       int numsSize = sizeof(nums)/sizeof(nums[0]); // Obtener el tamaño del array nums

       for (int index=0; index<numsSize; index++) {
           cout << nums[index] << endl;
       }


      // Implementación más simple que solo puede funcionar en
      // Versiones más recientes de C++

      // for (int item:nums) {
      //     cout << item << endl;
      // }

  	return 0;
   }



Se ha comentado una versión secundaria opcional del bucle ``for`` del código anterior.
Puede intentar ejecutar esto en su versión de C++ para ver si funciona, pero en algunas 
versiones anteriores de C++, como C++98, no funciona.

El ciclo anterior asigna la variable ``index`` para que sea cada valor sucesivo de 0 a numsSize. 
Luego, el valor en ese índice del array se imprime en la consola.
    

Emparejar definiciones
^^^^^^^^
.. dragndrop:: matching_vectors
   :feedback: Los comentarios muestran coincidencias incorrectas.
   :match_1: [ ]||| Accede al valor de un elemento.
   :match_2: =||| Asigna valor a un elemento.
   :match_3: push_back||| Agrega el elemento al final del vector.
   :match_4: pop_back||| Elimina el último elemento del vector.
   :match_5: insert||| Inyecta un elemento en el vector..
   :match_6: erase||| Elimina un elemento del índice elegido.
   :match_7: size||| Retorna la capacidad real utilizada por los elementos.
   :match_8: capacity||| Retorna la cantidad de espacio de almacenamiento asignado.
   :match_9: reserve||| Solicitar cambio de espacio a importe

    Relaciona las operaciones vectoriales con su correspondiente explicación.

.. tabbed:: intro_vector

  .. tab:: C++

    .. activecode:: introvector_cpp
        :caption: Usando un vector en C++
        :language: cpp

        // función que usa un vector para elevar al cuadrado
        // todos los numeros del 0 al 49
        // utiliza la operación de reserva para ahorrar espacio en la memoria
        #include <iostream>
        #include <vector>
        using namespace std;

        int main(){

            vector<int> intvector;
            intvector.reserve(50);

            for (int i=0; i<50; i++){
                intvector.push_back(i*i);
                cout << intvector[i] << endl;
            }
            return 0;
        }

  .. tab:: Python

    .. activecode:: introvector_py
        :caption: Usando una lista de Python

        """Usa una lista para cuadrar cada
        número del 0 al 49"""
        def main():
            intlist=[]
            for i in range(50):
                intlist.append(i*i)
                print(intlist[i])

        main()


En el ejemplo anterior, el uso de ``reservar`` era opcional. 
Sin embargo, es una buena idea usarlo antes de hacer crecer 
un vector de esta manera porque ahorrará tiempo. Debido a que 
los vectores se almacenan en arreglos subyacentes que requieren 
memoria contigua, cada vez que el tamaño del vector es demasiado 
grande para la capacidad, el vector completo debe moverse a una 
ubicación más grande en la memoria, y todo ese copiado lleva tiempo. 
En una implementación típica, la capacidad se duplica cada vez. 
como en el ejemplo que sigue.

.. activecode:: vector_no_reserve_cpp
    :caption: con el uso de  ``reserve``
    :language: cpp

    // función que usa un vector para elevar al cuadrado
    // todos los numeros del 0 al 49
    // y no utiliza reserva.
    // muestra la cantidad de espacio utilizado
    #include <iostream>
    #include <vector>
    using namespace std;

    int main(){

        vector<int> intvector;
        // sin intvector.reserve(50);

        for (int i=0; i<50; i++){
            intvector.push_back(i*i);
            cout << intvector[i] << endl;
            cout << "capacity: " << intvector.capacity() << endl;
        }
        return 0;
    }




Recordando que C++ está diseñado para la velocidad, 
no para la protección, es probable que no nos sorprenda lo siguiente:

.. tabbed:: vector_errors

  .. tab:: C++

    .. activecode:: vector_errors_cpp
        :caption: Vectores fuera de límites
        :language: cpp

        // Nota: el conteo siempre comienza en 0
        // Esto demuestra lo que sucede cuando
        // acceder a datos fuera de su vector

        #include <iostream>
        #include <vector>
        using namespace std;

        int main(){

            vector<int> intvector;
            intvector.reserve(10);

            for (int i=0; i<10; i++){
                intvector.push_back(i);
            }

            for (int i=0; i<=10; i++){
                cout << "intvector[" << i << "]="
                <<intvector[i] << endl;
            }

            return 0;
        }

  .. tab:: Python

    .. activecode:: vector_errors_py
        :caption: Lista de Python fuera de los límites

        """Demuestra las protecciones de Python
       en contra de iterar fuera de una lista"""
        def main():
            intlist=[]
            for i in range(10):
                intlist.append(i)

            for i in range(11):
                print("intlist[" + str(i) + "]=" + str(intlist[i]))

        main()



.. mchoice:: mc_array_vector
   :answer_a: Los vectores pueden cambiar de tamaño.
   :answer_b: Los vectores ofrecen todas las características y protecciones de las listas de Python
   :answer_c: Los vectores no usan memoria contigua, por lo que se pueden insertar elementos.
   :answer_d: Más de uno de los anteriores
   :answer_e: Ninguna de las anteriores
   :correct: a
   :feedback_a: Correcto! Buen trabajo!
   :feedback_b: No todas las protecciones de las listas las ofrecen los vectores; uno todavía puede iterar fuera de cualquier extremo.
   :feedback_c: No. Aunque los elementos se pueden insertar en vectores, requieren memoria contigua.
   :feedback_d: No. Solo uno de los anteriores es correcto.
   :feedback_e: Uno de los anteriores es de hecho correcto.

   ¿Cuál de las siguientes es la mayor diferencia entre una matriz de C++ y un vector de C++?


.. mchoice:: mc_vector1
   :answer_a: Nada. Es completamente opcional.
   :answer_b: Usarlo ahorrará tiempo si conoce el tamaño máximo necesario.
   :answer_c: Es necesario para que se pueda asignar memoria.
   :answer_d: Ninguna de las anteriores
   :correct: b
   :feedback_a: Es opcional pero tiene un propósito. Intentar otra vez.
   :feedback_b: Correcto!
   :feedback_c: No es requerido.
   :feedback_d: Uno de los anteriores es de hecho correcto.

   ¿De qué sirve el método ``reserva`` en un vector?
