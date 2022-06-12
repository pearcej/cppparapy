..  Copyright (C)  Jan Pearce and Brad Miller
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0
    International License. To view a copy of this license,
    visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Definiendo Funciones en C++ 
----------------------

En general, podemos ocultar los detalles de cualquier computación definiendo una función. 
Una definición de función requiere un nombre, un grupo de parámetros, un tipo de valor de retorno 
y un cuerpo. Puede retornar una variable, un valor o nada (especificado por la palabra clave void). 
Por ejemplo, la función simple definida a continuación retorna un número entero que es el doble del valor que le pasa.

.. _lst_timesTwo:

  .. activecode:: timesTwo
    :language: cpp
    :caption: Implementación de la función timesTwo 

    #include <iostream>
    using namespace std;

    // función que multiplica un número por 2
        int timesTwo(int num) {
        /* el tipo de  dato que retorna es un entero "int" que indica
           que un número entero es retornado */
        return num*2;
    }

    int main() {
        /* tipo de retorno int que indica 
        que se retorna un número entero */
        cout<<timesTwo(5)<<endl;

        return 0;
    }



La sintaxis de la definición de esta función incluye el nombre, ``timesTwo``, 
y una lista entre paréntesis de parámetros formales y sus tipos. 
Para esta función, un ``int`` llamado ``num`` es el único parámetro formal, 
lo que sugiere que ``timesTwo`` necesita solo un dato para hacer su trabajo. 
Los detalles, ocultos "dentro de la caja", simplemente calculan el 
resultado de ``num*2`` y lo devuelven. Podemos invocar o llamar a la función 
``timesTwo`` pidiéndole a C++ que la evalúe, pasando un valor de parámetro real, 
en este caso, ``3``. Tenga en cuenta que la llamada a ``timesTwo`` devuelve un 
número entero que a su vez se puede pasar a otra invocación.

Miremos una función similar.


.. _lst_timesTwoVoid:

  .. activecode:: timesTwoVoid
    :language: cpp
    :caption: Implementación de la función timesTwoVoid 

    #include <iostream>
    using namespace std;

    // función que multiplica un número por 2
    // excepto que no hace nada, solo envía a la consola

    void timesTwoVoid(int num) {
      /* tipo de retorno void 
      indica que no se devuelve nada */
      cout<< num*2<<endl;
    }

    int main() {
        /* tipo de retorno int que indica que
            se retorna un número entero */
        timesTwoVoid(5);

        return 0;
    }

La función ``timesTwoVoid`` se comporta de manera muy similar a ``timesTwo``. Sin embargo, hay una diferencia clave entre ellos. 
En lugar del ``int`` en ``timesTwo``, ``timesTwoVoid`` tiene un 
``void`` delante de la definición de su función. A diferencia de ``timesTwo``, ``timesTwoVoid`` es una función no fructífera, 
lo que significa que no devuelve un valor aunque todavía puede imprimir algo.

Podríamos ir un paso más allá e implementar nuestra propia función de raíz cuadrada 
usando una técnica bien conocida llamada "Método de Newton". 
El método de Newton para aproximar raíces cuadradas realiza un cálculo 
iterativo que converge en el valor correcto. La ecuación
:math:`newguess = \frac {1}{2} * (oldguess + \frac {n}{oldguess})`
toma un valor :math:`n` y adivina repetidamente la raíz cuadrada haciendo cada uno
:math:`newguess` the :math:`oldguess` en la iteración subsiguiente.
La conjetura inicial utilizada aquí es :math:`\frac {n}{2}`.
:ref:`Listing 1 <lst_root>` muestra una definición de función que acepta un valor
:math:`n` y retorna la raíz cuadrada de :math:`n` después de hacer 20 conjeturas. 
Nuevamente, los detalles del Método de Newton están ocultos dentro de la definición de la función y el usuario no tiene 
que saber nada sobre la implementación para usar la función para el propósito previsto.
:ref:`Listing 1 <lst_root>` también muestra el uso de los caracteres // como marcador de comentario. 
Los caracteres que siguen a // en una línea se ignoran.



.. _lst_root:

**Listing 1**

.. activecode:: newtonsmethod
  :language: cpp
  :caption: Newton's Method for finding Square Root

  //devuelve la raíz cuadrada de un número como un doble
  #include <iostream>
  using namespace std;

  double squareroot(double n) { /*tipo de retorno doble que indica
                                   que se devuelve un decimal*/
  	double root = n / 2;

  	for (int i = 0; i < 20; i++) {
  		  root = (.5) * (root + (n / root));
  	}

  	return root;
  }

  int main() {
  	cout << squareroot(9) << endl;
  	cout << squareroot(4563) << endl;

  	return 0;
  }

.. activecode:: dogwalk
    :language: cpp

    // función que devuelve el número de pasos caminados
    #include <iostream>
    using namespace std;

    void dogWalk(int steps){
        for (int step = 0; step < steps; step++){
            cout << "el perro camino "<< step << " pasos!"<< endl;
        }
    }

    int main() {
        dogWalk(11);
        
        return 0;
    }

.. mchoice:: dog_walker
    :answer_a: void
    :answer_b: int
    :answer_c: dog
    :answer_d: dogWalk
    :correct: a
    :feedback_a: Correcto, no retorna nada!
    :feedback_b: No del todo, ¡verifique el valor que precede al nombre de la función!
    :feedback_c: No del todo, dog ni siquiera es un tipo de datos!
    :feedback_d: No del todo, ¡ese es el nombre de la función en sí!

    ¿Cuál es el tipo de retorno correcto de la función anterior **int main()**?

Paso de Parámetros: por Valor vs por Referencia
-----------------------------------------------

En todas las funciones que hemos escrito hasta ahora, hemos utilizado un mecanismo 
de llamada de función llamado  **paso por valor **. Llamar a una función por valor implica 
copiar el contenido de los argumentos en las ubicaciones de memoria de los parámetros 
formales correspondientes. Si la función cambia los valores de los parámetros, 
el contenido original en la memoria a la que hacen referencia los argumentos de la 
función que llama no cambia.

Considere las siguientes dos definiciones de función:

::

    void functionExample( int inputVar ) { /*tipo de dato que retorna void, 
                                             indica que no se devuelve nada*/
        int nextVar = inputVar * 2;
        inputVar = 4;

        cout << "nextVar = " << nextVar << " inputVar = " << inputVar;
    }

    void callingFunction() { /*tipo de retorno void que indica
                                 que nada se retorna*/
        int myVar = 10;

        functionExample( myVar );
        cout << "myVar = " << myVar;
    }

Cuando la función ``callingFunction()`` se ejecuta, llama ``functionExample(...)``
con la variable *myVar* que tiene el valor de 10. Dentro de ``functionExample(...)``,
el valor de 10 es copiado de *myVar* al parámetro formal *inputVar*,
asi que el valor de *nextVar* es 10x2, o 20. La siguiente declaración cambia el contenido de *inputVar* a 4,
y ``cout`` dentro de esta función produce lo siguiente: 
::

    nextVar = 20 inputVar = 4



Observe lo que sucede cuando finaliza ``functionExample(...)`` y la ejecución vuelve a ``callingFunction()``. 
El contenido de *myVar* es **todavía el mismo**, ya que la ubicación de myVar difiere de donde se almacena *inputVar*. 
Por lo tanto, *myVar* todavía tiene el valor 10, y la expresión ``cout`` después de la llamada a la función producirá el resultado:

::

    myVar = 10

En otras palabras, cualquier cambio en las variables es local para la función, 
que es exactamente lo que queremos.
--------------
Pero hay un problema

Hemos visto ejemplos de funciones de C++ que no devuelven ningún valor o devuelven 
un solo valor. ¿Qué pasa si queremos que la función devuelva **más** de un valor? 
Necesitamos otro mecanismo de llamada llamado **paso por referencia**. 
Cuando se utiliza este mecanismo, se envía la ubicación actual en la memoria a la 
que hacen referencia los argumentos en lugar de los valores en esa ubicación. 
Para que el compilador sepa que tiene la intención de utilizar el paso por referencia, 
adjunte un "&" al final del nombre del tipo en la lista de parámetros formales en la 
declaración y el encabezado de la función. Cuando haga esto, cualquier cambio en los 
valores de los parámetros también cambiará el valor de los argumentos.

Un ejemplo de una función en la que esto es útil es una función que toma dos valores 
como entrada e intercambia su orden. Considere el siguiente fragmento de programa 
de una función llamada ``swap_values(...)`` que intercambia sus dos entradas y la función 
``main()`` que llama ``swap_values(...)``.

.. _lst_swap_inputs:

    .. activecode:: activepassrefcpp
        :caption: Pasar por Referencia
        :language: cpp

        #include <iostream>
        using namespace std;

        // definición de la función swap_values() 
        // Intercambia los valores ubicados por variable1 y variable2.

        // ¡Observe que esta función no devuelve nada!
        void swap_values(int &variable1, int &variable2) {
            int temp; 		// temporary storage for swap

            temp = variable1;
            variable1 = variable2;
            variable2 = temp;
        }

        int main( ) {
            int first_num, second_num;
            first_num = 7;
            second_num = 8;

            cout << "Dos números antes de la función de intercambio: 1) " << first_num << " 2) " << second_num << endl;
            swap_values(first_num, second_num);
            cout << "Los números después de la función de intercambio: 1) " << first_num << " 2) " << second_num;

            return 0;
        }


Para este programa :ref:`Swap Inputs <lst_swap_inputs>` para invertir el orden de los enteros que escriben los tipos de 
usuarios, la función ``swap_values(...)`` debe poder cambiar los valores de los argumentos. Intente eliminar uno o ambos "&" en este código para ver qué sucede.

Analice el programa y responda la pregunta que implica el paso de parámetros a continuación:

..  activecode:: questionexample1
    :coach:
    :language: cpp

    // demuestra la diferencia entre las funciones que pasan por valor 
    // y las que pasan por referencia
    #include <iostream>
    using namespace std;

    void func1(int var1, int var2){
        int temp;
        temp = var1;
        var1 = var2;
        var2 = temp;
    }

    void func2(int &var1, int &var2){
        int temp;
        temp = var1;
        var1 = var2;
        var2 = temp;
    }

    int main(){
        int num1 = 2;
        int num2 = 3;
        
        func1(num1, num2);
        cout << "resultado de la func1:" << endl;
        cout << "num1: " << num1 << ", num2: " << num2 << endl;
        func2(num1, num2);
        cout << "resultado de la func2:" << endl;
        cout << "num1: " << num1 << ", num2: " << num2 << endl;
        
        return 0;
    }

.. mchoice:: question1_1
    :multiple_answers:
    :answer_a: func2 es una función de paso por referencia, lo que significa que los valores pasados a la función son las referencias de memoria directas de las variables originales.
    :answer_b: func1 es una función de paso por referencia, lo que significa que los valores pasados a la función son las referencias de memoria directas de las variables originales.
    :answer_c: func1 es una función de valor de paso por valor, lo que significa que los valores pasados a la función son copias de las variables originales.
    :answer_d: func2 es una función de valor de paso por valor, lo que significa que los valores pasados a la función son copias de las variables originales.
    :correct: a, c
    :feedback_a: Correcto!
    :feedback_b: No, func1 simplemente usa copias de las variables originales como entrada porque no usa "&".
    :feedback_c: Correcto!
    :feedback_d: No, func2 está usando las referencias de memoria directas de las variables originales porque sus parámetros de entrada están usando "&".

    ¿Cuál es la diferencia entre **func1** y **func2**? Marque todo lo que corresponda.

.. mchoice:: question1_2
   :answer_a: El "&" obliga a las variables a cambiar en el ámbito global, lo que hace que las dos variables no cambien exclusivamente dentro de la función.
   :answer_b: El "&" pasa la ubicación donde se almacenan las dos variables, lo que hace que las dos variables cambien las referencias de memoria.
   :answer_c: El "&" en esta función se usa incorrectamente, lo que da como resultado una referencia de memoria superpuesta.
   :answer_d: Ninguna de las anteriores
   :correct: b
   :feedback_a: No, "&" no tiene nada que ver con alterar enteros en el ámbito global.
   :feedback_b: Correcto!
   :feedback_c: No, el uso de "&" aquí es correcto. Lea el ejemplo del código activo 4 anteriormente en la sección.
   :feedback_d: No, Una de las anteriores es definitivamente cierta.

   ¿Por qué agregar el "&" a los parámetros en la función **func** hace que la salida sea un resultado diferente?

-----------------------------------------------------------------

Arrays como Parámetros en Funciones
---------------------------------

Un array es un tipo de colección de datos que es el ancestro de la lista de Python. 
Discutiremos los arrays con más detalle en el próximo capítulo. 
Las funciones se pueden usar con **parámetros de arrays** para mantener un diseño estructurado. 
Sin embargo, un parámetro formal para un array no es una llamada por valor ni una 
llamada por referencia, sino un nuevo tipo de paso de parámetro denominado parámetro de array. 
En una definición de función, un parámetro de array parece un parámetro de paso por valor 
porque no hay un símbolo de y comercial (&), sino que el nombre de la variable va 
seguido de un conjunto de corchetes ([ y ]).

La siguiente función retorna el promedio de horas trabajadas en el array de enteros (tenga en cuenta que también debemos pasar el número de 
elementos en ese array porque el parámetro del array *list[]* no incluye esa información):

::

    double average( int list[], int length ) {	
         // Es una sintaxis correcta omitir la longitud del array en el propio array.
        double total = 0;                     
         //tipo de retorno doble que indica que se está devolviendo un decimal
        int count;
        for( count = 0; count < length; count++ ) {
            total += double(list[count]);
        };
        return (total / length);
    }


Los parámetros de array parecen *pasar por valor*, pero son efectivamente similares 
a los parámetros que *pasan por referencia*. Cuando se ejecutan, las funciones con estos 
parámetros no hacen copias privadas de los arrays. En su lugar, se pasa la referencia 
para reducir el impacto en la memoria. Por lo tanto, los arrays siempre se pueden 
cambiar permanentemente cuando se pasan como argumentos a funciones.

Después de una llamada a la siguiente función, cada elemento en el tercer argumento de 
matriz es igual a la suma de los dos elementos correspondientes en el primer y segundo argumento:
::

    void add_lists( int first[], int second[], int total[], int length ) { 
        //return type void which indicates that nothing is returned
        int count;
        for( count = 0; count < length; count++ ) { 
            total[count] = first[count] + second[count];
    };}


Examinando detalladamente, podemos ver que los dos primeros arrays no cambian de valor. Para evitar que modifiquemos accidentalmente cualquiera de estos arrays, podemos agregar el modificador ``const`` en el encabezado de la función:
::

    void add_lists( const int first[], const int second[], int total[], int length ) { 
        //tipo de devolución void que indica que no se devuelve nada
        int count;
        for( count = 0; count < length; count++ ) {
            total[count] = first[count] + second[count];
    };}

Estos cambios garantizarían que el compilador no acepte ninguna declaración dentro de la definición de la función que potencialmente modifique los elementos de los arrays *primero* o *segundo*.

Sobrecarga de Funciones
--------------------

**La sobrecarga de funciones** es la capacidad de crear múltiples funciones con nombres 
idénticos pero con implementaciones diferentes. No todos los idiomas admiten la sobrecarga 
de funciones. Python no lo hace, por ejemplo.

En programación C++, dos o más funciones pueden tener el mismo nombre cuando 
se pueden distinguir por los parámetros. Por lo tanto, C++ permite la sobrecarga 
de funciones cuando los tipos de datos de los parámetros difieren o el número de 
parámetros difiere.

La sobrecarga es una buena característica del lenguaje C++. Python no ofrece 
sobrecarga de funciones, por lo que realizar la misma tarea en Python requiere 
una técnica diferente.

Consulte el siguiente ejemplo donde se usa un parámetro opcional para lograr el
misma tarea

.. tabbed:: foverload

  .. tab:: C++

    .. activecode:: foverload_cpp
        :caption: sobrecarga de funciones en C++
        :language: cpp

        // demuestra cómo funciona la sobrecarga de funciones
        // cambiando los parámetros en las entradas.
        #include <iostream>
        using namespace std;

        void myfunct(int n) {
             cout << "1 parámetro: " << n <<endl;
        }

        void myfunct(int n, int m) {
             cout << "2 parametros: " << n;
             cout << " and " << m <<endl;
        }

        int main() {

            myfunct(4);
            myfunct(5, 6);
            myfunct(100);

            return 0;
        }


  .. tab:: Python

    .. activecode:: foverload_py
        :caption: Sobrecarga de Funciones en Python

        """Demuestra el uso de múltiples parámetros usando una sola función"""
        def myfunct(n, m=None):
            if m is None:
                print("1 parámetro: " + str(n))
            else:
                print("2 parámetros: " + str(n), end="")
                print(" and ", str(m))

        def main():
            myfunct(4);
            myfunct(5, 6);
            myfunct(100);

        main()

.. mchoice:: foverloading
    :multiple_answers:
    :answer_a: Ayuda a mantener la coherencia en la forma en que se nombran las funciones en todo el programa.
    :answer_b: Las funciones que realizan tareas similares difieren en función de los parámetros y no del nombre.
    :answer_c: Una función en esencia puede cumplir múltiples tareas dependiendo de los parámetros.
    :answer_d: Elimina el límite de cuántos parámetros se pueden escribir o pasar.
    :correct: a, b, c
    :feedback_a: Echa un vistazo a las otras respuestas también...
    :feedback_b: Echa un vistazo a las otras respuestas también...
    :feedback_c: Echa un vistazo a las otras respuestas también...
    :feedback_d: Incorrecto! La sobrecarga de funciones no tiene nada que ver con eliminar el límite de parámetros.

    ¿Cuáles son los beneficios de la sobrecarga de funciones?

.. admonition:: Autochequeo

   Aquí hay una autocomprobación que realmente cubre todo hasta ahora. ¿Es posible 
   que hayas oído hablar del teorema del mono infinito? El teorema establece que un 
   mono que golpea las teclas al azar en el teclado de una máquina de escribir durante 
   un tiempo infinito seguramente escribirá un texto determinado, como las obras 
   completas de William Shakespeare. Bueno, supongamos que reemplazamos un mono 
   con una función de C++. ¿Cuánto tiempo cree que le tomaría a una función de 
   C++ generar solo una oración de Shakespeare? La oración que buscaremos es: 
   "Creo que es como una comadreja".

   No querrá ejecutar este en el navegador, así que inicie su IDE de C++ favorito. 
   La forma en que simularemos esto es escribir una función que genere una cadena 
   de 28 caracteres de largo eligiendo letras aleatorias de las 26 letras del alfabeto 
   más el espacio. Escribiremos otra función que puntuará cada cadena generada 
   comparando la cadena generada aleatoriamente con el objetivo. 
   Sugerencia: deberá importar la biblioteca <random> para esto.

   Una tercera función llamará repetidamente a generar y puntuar, luego, si 
   el 100% de las letras son correctas, hemos terminado. Si las letras no son correctas, 
   generaremos una cadena completamente nueva. Para facilitar el seguimiento del 
   progreso de su programa, esta tercera función debe imprimir la mejor cadena 
   generada hasta el momento y su puntaje cada 1000 intentos.

.. admonition:: Desafío de autocomprobación

    Vea si puede mejorar el programa en la autocomprobación manteniendo las letras 
    correctas y modificando solo un carácter en la mejor cadena hasta el momento. 
    Este es un tipo de algoritmo en la clase de algoritmos llamados "hill climbling", 
    es decir, solo conservamos el resultado si es mejor que el anterior.
