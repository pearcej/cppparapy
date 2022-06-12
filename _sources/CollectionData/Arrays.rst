..  Copyright (C)  Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
    To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Colecciones
~~~~~~~~~~~

Además de los tipos de datos numéricos, booleanos y de caracteres, C++ también ofrece tipos de colección integrados. 
Un tipo de datos de **colección** es una agrupación de una cierta cantidad de otros elementos de datos (posiblemente solo cero o uno) 
que tienen algún significado compartido o necesitan ser operar juntos.

Las matrices, los vectores, las cadenas, los conjuntos y las tablas hash están dentro de los tipos de colección de C++ que son útiles.

Arrays 
~~~~~~

**¿Qué es un array?**
Un array (también conocido como arreglo) es una estructura de datos que consta de una colección ordenada de elementos de datos, de tipo idéntico, 
en la que cada elemento puede identificarse mediante un índice del array. En términos más técnicos, una estructura de datos de array 
es un arreglo ordenado de valores ubicados en direcciones igualmente espaciadas en la memoria de la computadora contigua.

NOTA: un **array** en C++ siempre se almacena en la memoria contigua. Los arrays de C++ se pueden asignar de dos maneras diferentes:

    1) *asignado estáticamente* en el que el tamaño del array se define en tiempo de compilación y no puede cambiar
    2) *asignado dinámicamente* en el que se utilizan punteros en el proceso de asignación para que el tamaño pueda cambiar en tiempo de ejecución

    
En C++ moderno, el array asignado estáticamente se usa típicamente en situaciones en las que la velocidad es esencial o donde existen restricciones 
de hardware, y una estructura de datos llamada vector se usa típicamente cuando se requiere más flexibilidad.

Como programador de Python, es posible que vea un array como el ancestro de la lista de Python, 
y puede recordar que las listas de Python en realidad se implementan a través de un array subyacente que consta de referencias.

Los arrays de C++ son similares a las listas de Python, excepto que debido a que C++ almacena variables directamente, cada elemento de un array 
de C++ debe tener un tipo de datos idéntico. Al igual que las listas de Python, los índices de las matrices comienzan desde 0.

El uso de arrays nos permite utilizar un conjunto ordenado de ubicaciones de memoria que luego podemos manipular como una sola entidad 
y que, al mismo tiempo, nos brinda acceso directo a cada componente individual.

**¿Por qué usar un Array?**

C++ es un lenguaje que se usa a menudo para el procesamiento en tiempo real 
o de bajo nivel donde la velocidad es esencial y/o solo hay una cantidad 
fija de espacio disponible.

El hecho de que los elementos de un array se almacenen en la memoria en ubicaciones de memoria contigua 
hace que la búsqueda a través del índice sea muy, muy rápida. 
En computación, una **palabra** es la unidad de datos utilizada por un diseño de procesador particular, 
como de 32 o 64 bits. Por ejemplo, un array de 100 variables enteras, con índices del 0 al 99, 
podría almacenarse como 100 palabras en las direcciones de memoria 20000, 20004, 20008, … 20396. 
El elemento con índice i estaría ubicado en la dirección 20000 + 4 × i .

Arrays de C++ asignadas estáticamente deben declararse con un tipo y un tamaño en tiempo de compilación.
::

    double darray[4];
    int iarray[10];
    char arr2[3000];




También es posible inicializar arrays asignados estáticamente en tiempo de compilación, 
en ese caso el número de elementos determina el tamaño del arreglo.
::

    int arr[] = {1, 2, 3, 4};  // Este tiene 4 elementos
    char arr2[] = {'a', 'b', 'c'}; // Este tiene 3 elementos 
    string arr3[] = {"this", "is", "an", "array"}; // Este tiene 4 elementos



Tenga en cuenta que un array con un solo elemento no es del mismo tipo que el tipo **atómico**, por lo que los siguientes no son lo mismo.

::

    double darray[] = {1.2};  // debe usar el índice para acceder al valor
    double ddouble = 1.2;     // no se puede usar el índice para acceder al valor


**Sea Cuidadoso con los Arrays**

La velocidad y el control de bajo nivel que los arrays nos ofrecen como programadores es poderoso... y peligroso. 
Como programador de Python, el uso de un array de C++ lo ayudará a comprender mejor las ventajas y desventajas de las protecciones que ofrece Python.

Estos son ejemplos de iteraciones.

.. tabbed:: list-array

  .. tab:: C++

    .. activecode:: listarray_cpp
        :caption: Iterando un array en C++
        :language: cpp

        // genera todos los elementos en un array
        // a la consola
        #include <iostream>
        using namespace std;

        int main(){
            int myarray[] = {2,4,6,8};
            for (int i=0; i<4; i++){
                cout << myarray[i] << endl;
            }
            return 0;
        }

  .. tab:: Python

    .. activecode:: listarray_py
        :caption: Iterating a list in Python

        """Demonstrates how python protects from 
        iterating past the end of a list"""

        def main():
            mylist = [2, 4, 6, 8]
            for i in range(8):
                print(mylist[i])

        main()



Las protecciones que ofrece Python, sin embargo, toman tiempo y C++ está diseñado 
para ser rápido. Python nunca te permitiría iterar más allá del final de una lista. 
C ++ no solo le permitirá iterar más allá de cualquier extremo de un array, sino 
que también le permitirá cambiar los valores más allá de cualquier extremo de un array 
con resultados a veces catastróficos.

La frase, "ten cuidado con lo que deseas" es excelente para recordar cuando se programa 
en C++. Porque C++ generalmente intentará hacer todo lo que le pidas.

.. tabbed:: array_error

  .. tab:: C++

    .. activecode:: array_error_cpp
        :caption: Iterando un array en C++
        :language: cpp

        #include <iostream>
        using namespace std;

        // Demuestra que pasa cuando se itera  
        // afuera de un array en C++
        // también genera la ubicación del valor en la memoria
        int main(){
            int myarray[] = {2,4,6,8};
            for (int i=0; i<=8; i++){
                cout << myarray[i] << endl;
                cout << "id: " << &myarray[i] << endl;
            }
            return 0;
        }

  .. tab:: Python

    .. activecode:: array_error_py
        :caption: Iterando una lista en Python

        """ Demuestra cómo python protege de 
        iterar más allá del final de una lista,
         y muestra el uso de Id como la locación de memoria y"""

        def main():
            mylist = [2,4,6,8]
            print(mylist)
            for i in range(5):
                print(mylist[i])
                print("id: "+str(id(mylist[i])))

        main()

La velocidad de C ++ tiene el costo de una verificación de errores mínima o nula. 
A veces, esto puede tener resultados desconcertantes, como en el siguiente ejemplo.

Debe usar una matriz cuando necesite velocidad o necesite trabajar con restricciones 
de hardware. De lo contrario, es posible que desee considerar el uso de otro tipo de datos de colección, el *vector*.

.. tabbed:: array_werror

  .. tab:: C++

    .. activecode:: array_werror_cpp
        :caption: Array write error in C++
        :language: cpp

        #include <iostream>
        using namespace std;

        // Demuestra cómo al iterar fuera 
        // de un array en C++, puede cambiar los datos en otros lugares
        int main(){
            int myarray[] = {2, 4};
            int otherdata[]={777, 777};
            for (int i=0; i<4; i++){
                myarray[i]=0;
                cout <<"myarray["<< i << "]=";
                cout << myarray[i]<< endl;
                cout << "add:" << &myarray[i] << endl;
            }

            for (int i=0; i<2; i++){
                cout <<"otherdata["<< i << "]=";
                cout << otherdata[i]<< endl;
                cout << "add:" << &otherdata[i] << endl;
            }

            return 0;
        }

  .. tab:: Python

    .. activecode:: array_werror_py
        :caption: Escribir un error en Python

        """ Demuestra cómo python protege de iterar más allá del final de una lista y cambiar cualquier otro dato""" 
        def main():
            mylist = [2, 4]
            otherdata = [777, 777]
            for i in range(4):
                print(mylist[i])
                print("id: "+str(id(mylist[i])))

            for j in range(2):
                  print(otherdata[i])
                  print("id: "+str(id(otherdata[i])))

        main()



.. mchoice:: mc_werror
   :answer_a: Nada. Todo esta bien.
   :answer_b: Todos los datos se reinicializaron automáticamente.
   :answer_c: No tengo ni idea. Por favor dame una pista.
   :answer_d: El primer bucle salió de los límites y escribió sobre los valores en otros datos.
   :answer_e: ninguno de las anteriores
   :correct: d
   :feedback_a: En realidad hay un problema. Mire cuidadosamente.
   :feedback_b: No. C++ solamente hace lo que le dice que haga.
   :feedback_c: Intente otra vez. Uno de estos es correcto. Mira las direcciones de memoria.
   :feedback_d: Bien!
   :feedback_e: Uno de los anteriores es correcto.

   En el ejemplo anterior, ¿qué pasó con otherdata[ ] en C++?

.. mchoice:: mc_array
    :answer_a: int myarray(5);
    :answer_b: myarray[5];
    :answer_c: int myarray[5];
    :answer_d: Ninguno de los anteriores
    :correct: c
    :feedback_a: ¡Revise los caracteres al final del array! ¡Ahora es una función!
    :feedback_b: Se está olvidando algo importante!
    :feedback_c: Bien hecho!
    :feedback_d: Revisa los caracteres al final del array!

    ¿Cuál es la forma correcta de declarar una matriz en C++?

