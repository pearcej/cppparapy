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
     **Operación del vector**                       **Uso**                                      **Explicación**
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


A very common programming task is to grow a vector using the ``push_back()`` method to append to the vector
as we see in the next example.
Because vectors can change size, vectors typically allocate some extra storage to accommodate for possible growth.
Thus the vector typically has an actual *capacity* greater than the storage *size* strictly needed to contain its elements.


Iterating through Vectors
~~~~~~~~~~~~~~~~~~~~~~~~~

When iterating vectors, you must first find the length of your container. You can simply call the ``.length()`` function.
For arrays, the number of elements can be found by getting the size in memory of the array
by using the ``sizeof()`` function, and then dividing it by the size of the first element of
the array using the same ``sizeof()`` function. Because all elements in C++ arrays are
the same type, they take the same amount of space and that can be used to find the number
of elements the Array contains!

.. activecode:: vectorIteration1
   :language: cpp
   :sourcefile: ArrayIteration.cpp

   #include <iostream>
   using namespace std;

   int main() {
       int nums[] = {1,3,6,2,5};
       //Divide the size of the array (in bytes) by the size of a single element (in bytes)
       // to get the total number of elements in the array.
       int numsSize = sizeof(nums)/sizeof(nums[0]); // Get size of the nums array

       for (int index=0; index<numsSize; index++) {
           cout << nums[index] << endl;
       }


      // Simpler Implementation that may only work in
      // Newer versions of C++

      // for (int item:nums) {
      //     cout << item << endl;
      // }

  	return 0;
   }


An optional secondary version of the ``for`` loop has been commented out of the above code.
You can try running this in your version of C++ to see if it works, but in some older versions of C++,
such as C++98, it does not.

The above loop assigns the variable ``index`` to be each successive value from 0 to numsSize.
 Then, the value at that index in the array is printed to the console.
    

Matching
^^^^^^^^
.. dragndrop:: matching_vectors
   :feedback: Feedback shows incorrect matches.
   :match_1: [ ]|||Accesses value of an element.
   :match_2: =||| Assigns value to an element.
   :match_3: push_back|||Appends item to the end of the vector.
   :match_4: pop_back||| Deletes last item of the vector.
   :match_5: insert|||Injects an item into the vector.
   :match_6: erase|||Deletes an element from the choosen index.
   :match_7: size|||Returns the actual capacity used by elements.
   :match_8: capacity|||Returns the ammount of allocated storage space.
   :match_9: reserve||| Request a change in space to amount

    Match the Vector operations with their corresponding explination.

.. tabbed:: intro_vector

  .. tab:: C++

    .. activecode:: introvector_cpp
        :caption: Using a vector in C++
        :language: cpp

        // function that uses a vector to square
        // every number from 0 to 49
        // uses the reserve operation to save space in memory
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
        :caption: Using a Python list

        """Uses a list to square every
        number from 0 to 49 """
        def main():
            intlist=[]
            for i in range(50):
                intlist.append(i*i)
                print(intlist[i])

        main()


In the above example, the use of ``reserve`` was optional. However, it is a good
idea to use it before growing a vector in this way because it will save time.
Because vectors are stored in underlying arrays which require contiguous memory,
every time the vector's size gets too large for the capacity, the entire vector must
be moved to a larger location in memory, and all that copying takes time.
In a typical implementation, the capacity is doubled each time. as in the
example that follows.


.. activecode:: vector_no_reserve_cpp
    :caption: With use of ``reserve``
    :language: cpp

    // function that uses a vector to square
    // every number from 0 to 49
    // and does not use reserve.
    // shows amount of space used
    #include <iostream>
    #include <vector>
    using namespace std;

    int main(){

        vector<int> intvector;
        // without intvector.reserve(50);

        for (int i=0; i<50; i++){
            intvector.push_back(i*i);
            cout << intvector[i] << endl;
            cout << "capacity: " << intvector.capacity() << endl;
        }
        return 0;
    }


Remembering that C++ is designed for speed, not protection,
we will likely not be surprised by the following:

.. tabbed:: vector_errors

  .. tab:: C++

    .. activecode:: vector_errors_cpp
        :caption: Vectors out of bounds
        :language: cpp

        // Note: counting always starts at 0
        // This demonstrates what happens when
        // accessing datat outside of your vector

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
        :caption: Python list out of bounds

        """Demonstrates python's protections
        against iterating outside of a list"""
        def main():
            intlist=[]
            for i in range(10):
                intlist.append(i)

            for i in range(11):
                print("intlist[" + str(i) + "]=" + str(intlist[i]))

        main()



.. mchoice:: mc_array_vector
   :answer_a: Vectors can change size.
   :answer_b: Vectors offer all of the features and protections of Python lists
   :answer_c: Vectors don't use contiguous memory, so elements can be inserted.
   :answer_d: more than one of the above
   :answer_e: none of the above
   :correct: a
   :feedback_a: Right! Good job!
   :feedback_b: Not all of the protections of lists are offered by vectors; one can still iterate off of either end.
   :feedback_c: No. Although elements can be inserted in vectors, they do require contiguous memory.
   :feedback_d: No. Only one of the above is correct.
   :feedback_e: One of the above is indeed correct.

   Which of the following is the biggest difference between a C++ array and a C++ vector?


.. mchoice:: mc_vector1
   :answer_a: Nothing. It is completely optional.
   :answer_b: Using it will save time if you know the maximum size needed.
   :answer_c: It is required so memory can be allocated.
   :answer_d: none of the above
   :correct: b
   :feedback_a: It is optional but it does serve a purpose. Try again.
   :feedback_b: Right!
   :feedback_c: It is not required.
   :feedback_d: One of the above is indeed correct.

   What good is the ``reserve`` method in a vector?
