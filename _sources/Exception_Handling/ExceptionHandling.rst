..  Copyright (C)  Jan Pearce y Brad Miller
    Este trabajo está bajo la licencia Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. Para ver una copia de esta licencia, visite http://creativecommons.org/licenses/by-nc-sa/4.0/.

Manejo de Excepciones
~~~~~~~~~~~~~~~~~~

Hay dos tipos de errores que suelen ocurrir al escribir programas. El primero,
conocido como **error de sintaxis**, simplemente significa que el programador 
ha cometido un error en la estructura de una declaración o expresión. 
Por ejemplo, es incorrecto escribir una declaración en una línea y olvidar el punto y coma.

::
    int main() {
        int i = 10
        return 0;
    }

    >>  exit status 1
        main.cpp: In function 'int main()':
        main.cpp:3:5: error: expected ',' or ';' before 'return'
             return 0;
         ^~~~~~

En este caso, el compilador de C++ no puede completar el 
procesamiento de esta instrucción porque no concuerda con las reglas del lenguaje. 
Los errores sintácticos suelen ser más frecuentes cuando está aprendiendo un nuevo lenguage de programación.

El otro tipo de error, conocido como **error lógico**, denota una situación
en la que el programa se ejecuta pero da un resultado incorrecto.
Esto puede deberse a un error en el algoritmo o a un error en la traducción
de ese algoritmo. En algunos casos, los errores lógicos llevan a situaciones
muy malas, como intentar dividir por cero o intentar acceder a un elemento
de una lista donde el índice del elemento está fuera de los límites de la lista. 
En este caso, el error lógico conduce a un error de tiempo de ejecución que
hace que el programa finalice. Estos tipos de errores de tiempo de ejecución
suelen denominarse **excepciones**.

La mayoría de las veces, los programadores principiantes simplemente piensan 
en las excepciones como errores fatales de tiempo de ejecución que causan
el final de la ejecución. Sin embargo, la mayoría de los lenguajes de programación 
proporcionan una forma de lidiar con estos errores que permitirán al programador
tener algún tipo de intervención si así lo desea. Además, los programadores pueden 
crear sus propias excepciones si detectan una situación en la ejecución del programa 
que lo amerite.

Cuando ocurre una excepción, decimos que la excepción ha sido "lanzada". Usted puede "atrapar" la 
excepción que se ha generado utilizando una declaración de prueba ``try``. Por ejemplo, 
considere la siguiente sesión que le pide al usuario un número entero y luego usa el
operador de división. Si el usuario ingresa un segundo número que no es 0, la impresión 
mostrará el resultado de la división. Sin embargo, si el usuario ingresa 0, C++ generará 
un error y devolverá un valor distinto a 0.

::

    main.cpp: In function 'int main()':
    main.cpp:5:13: warning: division by zero [-Wdiv-by-zero]
       cout << 10/0;
               ~~^~
    exit status -1


Podemos manejar esta excepción creando una función de división que puede lanzar un error. 
Un bloque de prueba y captura correspondiente puede "atrapar" la excepción e imprime un 
mensaje al usuario en caso de que ocurra una excepción. Por ejemplo, intente cambiar los 
valores asignados a firstNum y secondNum en el siguiente código:

.. _lst_divisioncode:

  .. activecode:: divisionErr_cpp
    :caption: Manejo de errores para la división
    :language: cpp

    // Muestra el manejo de la excepción usando "try", "throw",
    // y "catch" para poder generar 
    // un mensaje de error en la consola
    #include <iostream>
    using namespace std;

    double div(double num1, double num2) {
    	if (num2 == 0) {
    		// Si el segundo número es 0, lanza "throw" este error
    		throw " No se puede divir por 0!\n";
    	}

    	return num1 / num2;
    }

    int main() {
        // Obtener datos del usuario
    	float firstNum=10;
        float secondNum=0;

    	try {
    		// Intento de dividir los dos números
    		double result = div(firstNum, secondNum);
    		cout << "result of division: " << result << endl;

    	} 
        catch (const char *err) {
    		// Si un error es identificado, vamos a imprimirlo
    		cout << err;
    	}

    	return 0;
    }


Esto detectará el hecho de que ``div`` genera una excepción y, en su lugar, devolverá el error al usuario. 
Esto significa que el programa no terminará sino que continuará con las declaraciones que siguen.

También es posible que un programador use declaraciones anidadas de prueba "try" y excepción "except", 
junto con diferentes errores lanzados para administrar lo que sucede en su código. 
El programa seguirá ejecutándose después de detectar el error, pero podemos detenerlo devolviendo un 
valor distinto a 0 en nuestra función principal. Esto se conoce como un ``código de error``.

El siguiente código debe ejecutarse dentro de una carpeta y puede usarse para abrir archivos. 
Idealmente, uno de los archivos debería llamarse "archivo.txt". 
El programa le pedirá al usuario un nombre de archivo y puede detectar si ese archivo no 
existe o si el "archivo.txt" predeterminado no existe. Esta es otra aplicación útil para el manejo de errores.

::

    #include <fstream>
    #include <iostream>
    using namespace std;

    void printFile(char filename[32]) {
        ifstream in_stream;
        in_stream.open(filename);

        if (!in_stream.good()) {
            // Throws an error
                in_stream.close();

            throw "\nA un archivo con ese nombre no existe!";
        }

        char ch;

        cout<<endl;
        while (!in_stream.eof()) {
            cout << ch;
            ch = in_stream.get();
        }
        cout << endl;

        in_stream.close();
    }

    int main() {
        char filename[32];
        cout << "Filename: ";
        cin >> filename;

        try {
            // Intenta imprimir el archivo
            printFile(filename);
        } 
        catch (const char *msg) {
            // Runs if error is thrown
            cerr << msg << endl; //cerr is used to output errors similar to cout.

            // En su lugar usa el archivo predeterminado para imprimir 
            try {
                char defaultFile[32] = "file.txt";
                printFile(defaultFile);
            } 
            catch (const char *msg) {
                cerr << " Archivo predeterminado no fue encontrado!" << endl; //cerr es usado para imprimir errores similares a cout. 
            }
        }

        return 0;
    }



Hay muchos tipos de excepciones predeterminadas que se pueden usar en la biblioteca estándar
de C++. Puede consultar la documentación oficial de C++ para obtener una lista de todos los tipos de 
excepción disponibles y cómo crear su propio tipo de excepción.

Resumen
~~~~~~~~~~~~

1. Hay dos tipos de errores que ocurren al escribir programas: errores sintácticos y errores lógicos.

2. Un error de sintaxis es un error que ocurre debido a un error de escritura o una declaración incorrecta 
que no está permitida en un idioma. Esto puede detectarse fácilmente ya que el programa no se ejecuta hasta que se solucione.

3. Los errores lógicos son errores que ocurren no debido a un error en la forma en que se escribe el código,
sino porque el código produce un valor no deseado o inesperado, como una división entre 0 que conduce a un valor
indefinido.

4. Los errores lógicos se pueden detectar utilizando ``try`` y ``catch``, que pueden ayudar a identificar qué está causando el error y evitar confusiones sobre el problema.


Compuébalo tú mismo
~~~~~~~~~~~~~~

.. clickablearea:: syntax_error
    :question: Dele click en el error sintáctico.
    :iscode:
    :feedback: Recuerde que los errores sintácticos ocurren más cuando se esta aprendiendo un nuevo lenguaje de programación

    :click-incorrect:int age;:endclick:
    :click-incorrect:cout << "age:";:endclick:
    :click-incorrect:cin >> age;:endclick:
    :click-incorrect:if (age > 18) {:endclick:
    :click-incorrect:cout << "You can vote in the U.S!";}:endclick:
    :click-incorrect:else {:endclick:
    :click-correct:cout << You cannot vote in the U.S yet.;:endclick:
    }

.. clickablearea:: logic_error
    :question: Dele click en el error lógico.
    :iscode:
    :feedback: Si queremos que el código diga cuándo podemos votar, ¿en qué casos debería decir cuándo podemos y cuándo no?

    :click-incorrect:int age;:endclick:
    :click-incorrect:cout << "age:";:endclick:
    :click-incorrect:cin >> age;:endclick:
    :click-correct:if (age > 18) {:endclick:
    :click-incorrect:cout << "You can vote in the U.S!";}:endclick:
    :click-incorrect:else {:endclick:
    :click-incorrect:cout << You cannot vote in the U.S yet.;:endclick:
    }
