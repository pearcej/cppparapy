Veamos un programa en C++
===========================

Una larga tradición en informática es escribir un programa llamado "Hola Mundo". El programa “Hola Mundo” es simple y fácil. No es posible cometer errores lógicos, por lo que lograr que se ejecute depende solo de comprender la sintaxis. Veamos una versión fácil de "Hola Mundo"
en Python:

.. activecode:: hellopysimp
  :language: python

  print("Hola Mundo!")

Ahora, miremos a una versión más “complicada” del programa "Hola Mundo" con una función principal o
``main`` en Python:

.. activecode:: hellopymain
  :language: python

  def main():
      print("Hola Mundo!")
  main()

Ahora, miremos al mismo programa escrito en C++:

.. activecode:: hellocppstd
    :language: cpp

    #include <iostream>

    int main(){

        std::cout << "Hola Mundo!\n";
        return 0;
    }

El programa anterior se puede escribir alternativamente de la siguiente manera para permitir facilitar 
mejor la entrada y salida estándar:

.. activecode:: hellocppnamespace
    :language: cpp

    #include <iostream>
    using namespace std;

    int main(){
        cout << "Hola Mundo!\n";
        return 0;
    }

Lo que vemos fundamentamente es que hay algunas similitudes con la versión complicada de Python, 
como la función ``main`` y la cadena "Hola mundo". Sin embargo, en la versión en C++ hay muchas más 
cosas que dificultan ver lo esencial del programa. ¡No se preocupe! Una habilidad importante para 
un científico computacional es aprender qué ignorar y qué mirar cuidadosamente. Pronto se acostumbrará con los 
elementos en C++ a medida que los vea. Una cosa que le ayudará, es aprender un poco más sobre C++.

Compilación
-----------

Una pregunta que puede tener sobre este pequeño programa es "¿Cómo lo ejecutaría en mi propia máquina?" 
Ejecutar un programa en C++ no es tan simple como ejecutar un programa en Python. 
La primera gran diferencia entre C++ y Python es que Python es un *lenguaje interpretado* mientras que C++ 
es un lenguaje compilado. Podíamos ejecutar nuestros programas de Python usando el **intérprete** de Python y, 
normalmente, eso era todo lo que tomaba para ejecutar el programa. En C++, ejecutar programas es un proceso de dos pasos.

Primero, debemos escribir el programa hola mundo en un archivo y guardar ese archivo con un nombre como ``hello.cpp`` 
Una vez que hemos guardado el archivo, lo compilamos desde la línea de comandos o desde un entorno de desarrollo integrado `(IDE) <https://www.redhat.com/es/topics/middleware/what-is-ide>`_. 
Solo después de compilar el programa podemos ejecutarlo.

Ahora puede que se pregunte ¿de qué sirve este paso adicional? ¿Qué hace compilar por nosotros? Hay un par 
de beneficios importantes que obtenemos al compilar:

-  Detección temprana de errores 

-  Ejecuciones más rápidas de los programas 

El trabajo del compilador es convertir su código en C++ a un lenguaje que su máquina puede entender. 
Llamamos al código que la computadora entiende **Lenguaje de Máquina**. La computadora interpreta el 
lenguaje de máquina al igual que el intérprete de Python interpreta el código en Python. Sin embargo, 
dado que el lenguaje de máquina está mucho más cerca del lenguaje nativo de la computadora, funciona más rápido.

Cuando el compilador hace la traducción, puede encontrar muchos diferentes tipos de errores. 
Por ejemplo, si se olvida declarar una variable el compilador los encontrará y se los mostrará antes de que 
ejecute el programa. Veremos en breve algunos ejemplos de errores que el compilador captura. Lo más probable 
es que también cometas estos errores muy pronto, pero primero hablemos de cada una de las declaraciones en un programa C++.

.. dragndrop:: interpreterdrag
    :feedback: Esto es retroalimentación
    :match_1: Compilador||| Generalmente transforma el código escrito en un lenguaje de alto nivel en un lenguaje de bajo nivel para crear un programa ejecutable.
    :match_2: Interpretador||| Ejecuta directamente declaraciones en un lenguaje de secuencias de comandos sin necesidad de que se hayan ensamblado en lenguaje de máquina.

    Relacione el compilador y el intérprete con la definición correcta.


Uso de encabezados y bibliotecas
---------------------------

Las instrucciones del preprocesador en C++ aparecen como declaraciones precedidas por el símbolo numeral ``#``.
Estos le dicen al preprocesador qué archivo, encabezado o biblioteca debe poner a disposición
del compilador. Por ejemplo, ``#include <iostream>`` se asegurará de que
la biblioteca ``iostream`` está disponible en tiempo de compilación.
Aquí, el término *encabezado* se usa para un tipo de archivo C++ que contiene definiciones
de funciones y variables, pero no las implementaciones de funciones.

Puede pensar en la expresión ``#include ...`` en C++ como si funcionara un poco como
la declaración ``import ...`` en Python.
La declaración ``import`` de Python accede directamente al código escrito en otro archivo
mientras que la instrucción ``#include`` en C++ copia clases y funciones de
otro archivo.

En Python, una declaración para importar se ve así: 
::

  import classname

Hay dos maneras de usar ``#include`` en C++:

::

  #include <nombredelabiblioteca>
  #include "nombredelabiblioteca"

Aquí los símbolos de mayor y menor ``<>`` son usados para incluir bibliotecas o 
encabezados dados en la implementación como los encabezados en la biblioteca estandard (``iostream``, ``string``, etc.). 
Las dobles comillas ``"`` son usadas para los encabezados y los archivos que no son dados por la implementación.

La función main
-----------------

A diferencia de Python, cada programa C++ **debe** tener una función ``main`` que comienza
con ``int main()``. Esta función ``main`` se declara implícitamente en lugar de
explícitamente como debemos hacer en Python cuando tenemos una función main. Es por eso que
no ve una llamada de función explícita que invoque main.

El ``int`` en ``int main()`` indica que el *tipo de retorno* de la función ``main`` será
un número entero. La última línea de la función ``main`` de C++ suele ser ``return 0``,
para que pueda ver que el programa realmente retorna el número entero 0.
Se retorna cero para indicar la finalización exitosa de la función ``main``. 
En caso de que se pregunte por qué se retorna un número entero, si comete un error de
manejo en C++, en lugar de 0, puede alternativamente retornar un código de error con un número entero que represente
un error específico cuándo y dónde ocurre.

Las funciones en C++ y otros bloques de código en C++ se agrupan usando los símbolos de llaves ``{}``.
Las llaves son usadas como se usan las tabulaciones en Python. 
Muchos también usan el tabulado en C++ para indicar bloques de código, pero las tabulaciones y otros 
espacios en blanco (en su mayoría) no tienen un significado intrínseco en C++. En su lugar, se debe usar el punto y coma (``;``) para concluir la mayoría de las declaraciones en C++.

De hecho, el siguiente programa funcionará perfectamente a pesar de que la falta de espacios  
hace que sea más difícil de leer para los humanos.


.. activecode:: hellocppugly
    :language: cpp

    #include <iostream>
    using namespace std; int main(){cout << "Hola Mundo!\n"; return 0;}


Mientras programa en C++, le recomendamos que continúe usando
el tipo de formato legible al que se ha acostumbrado en Python.
Seguramente apreciará esto cuando esté depurando su código.

Sin mirar, intente poner el siguiente código en el orden correcto.

.. parsonsprob:: pp_introcpp_order
   :language: c++
   :adaptive:
   :noindent:

   Reorganice correctamente el código a continuación para implementar hola mundo en C++
   -----
   &#x22D5include &#x003Ciostream&#x003E
   =====
   using namespace std;
   =====
   int main()
   {
   =====
       cout << "Hola Mundo!\n";
   =====
       return 0;
   =====
   }



Comentarios en C++
---------------

Ambos Python y C++ admiten comentarios que no son procesados por el intérprete o el compilador.

En Python, una sola línea de comentario comienza con el símbolo de  (``#``).
En C++, el equivalente son dos barras diagonales (``//``).
En ambos casos el resto de la línea es tratado como un comentario e ignorado por el intérprete o compilador. Python admite comentarios usando triple comillas. 

Al igual que Python, C++ también admite comentarios de varias líneas
empezando con
``/*``
y terminando con 
``*/``.

La cadena de documentación entre comillas triples en Python se usa a menudo para procesar automáticamente la documentación. 
No hay equivalente en el estándar C++ a la cadena de documentación entre comillas triples en Python. Sin embargo, 
los grupos de símbolos ``/**`` y ``*/`` a menudo se usan para indicar bloques de documentación al comienzo de una clase, programa o función, 
lo cual es legal porque el segundo asterisco ``*`` es parte del comentario de varias líneas. 
Ciertas bibliotecas también procesarán automáticamente el texto entre estos grupos de símbolos, como una cadena de documentación.

::

  // el resto de esta línea es un comentario de C++ que el compilador ignora
  /* Este es un comentario de C++ de varias líneas que puede abarcar muchas líneas, comenzando y terminando con los símbolos dados */


Salida estándar
---------------

A menudo tenemos la necesidad de interactuar con los usuarios, ya sea para obtener datos o para proporcionar algún tipo de resultado.
La biblioteca C++ ``<iostream>`` nos proporciona la funcionalidad para obtener información
desde la entrada estándar, así como para enviar información a la salida estándar. Esta entrada y salida es manejada por lo que
se conoce como ``flujo``.

Un ``flujo`` es esencialmente un canal en el que los datos fluyen desde el origen hasta el destino (a menudo denominado "sumidero").
Los flujos de salida envían datos, y el flujo de salida estándar ``cout`` envía datos de caracteres a la pantalla.
Entonces, ``cout`` significa "salida de caracteres".
Al igual que la instrucción ``print`` de Python, ``cout`` se usa para que
imprima en el dispositivo de salida estándar, que suele ser su pantalla.
Cuando se usa ``cout``, también verá que se usa ``<<``.
Cuando este conjunto de símbolos se usan juntos, se denominan "operador de salida".
El operador de salida se utiliza para dirigir la salida al archivo o dispositivo de salida designado.
El operador de salida también se puede usar para concatenar la salida, como el "+"
se puede usar para concatenar en Python.

.. activecode:: hellocppducky
    :language: cpp

    /* Alguna vez ha escuchado de rubber duck debugging?
        See https://en.wikipedia.org/wiki/Rubber_duck_debugging */
    #include <iostream>
    using namespace std;

    int main(){
      cout << "Alguna vez ha escuchado de rubber duck debugging?" << endl;
      cout << "                __     " << endl;
      cout << "              <(o )___-" << endl;
      cout << "               ( .__> /" << endl;
      cout << "                `----' " << endl;
    }


Entrada Estándar
--------------
Además de poder generar la salida estándar, queremos poder recibir información del usuario.
El comando ``cin`` es algo similar a ``cout`` excepto que se usa para obtener entrada de caracteres.
La entrada transmite datos directos desde una fuente, como el teclado o un archivo.
Como habrás adivinado, ``cin`` significa "entrada de caracteres" y hace que obtener entrada desde el dispositivo de entrada estándar (generalmente el teclado) sea relativamente fácil.
El operador de entrada en C++ es ``>>``.

Este un ejemplo que usa ``cin``:

.. raw :: html

    <div>
    <iframe height="600px" width="100%" src="https://repl.it/@sheepof/cin-ejemplo?lite=true" scrolling="no" frameborder="no" allowtransparency="true" allowfullscreen="true" sandbox="allow-forms allow-pointer-lock allow-popups allow-same-origin allow-scripts allow-modals"></iframe>
    </div>

Tipo de Declaraciones
-----------------

En este ejemplo, puedes notar la línea ``float num`` que declara una nueva variable llamada ``num`` de tipo ``float``.
Al igual que las funciones, todas las variables en C++ deben declararse antes de su uso y
no pueden cambiar de tipo. Esto se conoce como **escritura estática**.
La línea ``float num`` esencialmente le dice al compilador que reserve suficiente espacio para un número de coma flotante,
y para nombrar esta ubicación de memoria ``num.`` Luego, lo que el usuario escriba se almacenará en la variable ``num``.
Usando la función ``cout``, podemos escribir instrucciones que pedirán al usuario que ingrese datos y luego
incorporar esos datos en un procesamiento posterior.
Por ejemplo, en el ejemplo anterior, la entrada de número entero se duplica y luego se muestra en la consola.

Hablaremos más sobre el tipo de declaraciones en la sección sobre tipos de datos, y
profundizaremos cuando hablemos sobre la entrada y la salida más adelante cuando discutamos flujos en C++ y el manejo de archivos.


Resumen
=======
Ahora que hemos ejecutado nuestro programa "Hola Mundo", regresemos y veamos
atentamente para ver qué podemos aprender sobre C++.

.. activecode:: hellocommented
    :language: cpp

    /* Este programa "Hola Mundo!" demuestra los conceptos de comentarios, el uso de bibliotecas y usar output en C++ 
    */

    #include <iostream>
    using namespace std;

    int main(){         // main() debe existir y retornar un número entero
        cout << "Hola Mundo!\n";
        return 0;       // 0 indica que el programa ha terminado exitosamente
    }

Este simple ejemplo ilustra algunas reglas muy importantes:

1. Todo en C++ debe declararse como un tipo específico de objeto o variable, incluida la declaración del tipo de retorno para cada función.

2. Todo programa C++ debe tener una función que comience como ``int main()``, y termine con la declaración ``return 0;`` cuando se haya completado exitosamente.

3. Las declaraciones de C++ terminan con un punto y coma.

4. Los espacios en blanco casi no tienen sentido en C++, pero todos los bloques de código de C++ deben estar rodeados por llaves {}, en lugar de usar
   sangría para definir bloques como se hace en Python.

Compruébalo tú mismo
==============

.. mchoice:: mc_comment
   :answer_a: &#x003C!-
   :answer_b: &#x22D5
   :answer_c: //
   :answer_d: @
   :answer_e: Ninguna de las anteriores
   :correct: c
   :feedback_a: No, &#x003C!- es usado en html para comenzar commentarios, pero no es usado en C++.
   :feedback_b: No, &#x22D5 es usado en Python para comentarios, pero en C++ es usado para las instrucciones del compilador como cargar una biblioteca de código. 
   :feedback_c: Correcto!
   :feedback_d: No, @ no es usado en C++.
   :feedback_e: Uno de los anteriores es correcto.

   ¿Qué símbolo o conjunto de símbolos comienza un comentario en C++ cuando el comentario se extiende solo hasta el final de una línea?

.. mchoice:: mc_mlcomment
  :answer_a: Verdadero
  :answer_b: Falso
  :correct: a
  :feedback_a: Correcto!
  :feedback_b: Incorrecto, ambos idiomas admiten comentarios de varias líneas. Python usa comillas triples mientras que en C++ comienzan con /* y terminan con */.

  Verdadero o Falso: Ambos Python y C++ admiten comentarios multilínea. En c++, los comentarios comienzan con ``/*`` y terminan con ``*/``.


.. mchoice:: mc_comment
   :answer_a: cout x;
   :answer_b: output x;
   :answer_c: print x;
   :answer_d: Ninguna de las anteriores
   :correct: d
   :feedback_a: Parcialmente correcto. El objeto cout significa salida de caracteres y lo necesita, pero también necesitará usar el operador de inserción <<.
   :feedback_b: No, output no es un comando u objecto en C++.
   :feedback_c: No, print es un comando en Python, pero no es usado en C++.
   :feedback_d: La declaración correcta es "cout << x;" o "std:cout x;" Pero el operador de inserción es ciertamente necesario.

  Dada una variable llamada x. ¿Qué declaración imprimirá lo que contiene x?

.. fillintheblank:: input

   ¿Qué palabra clave de la biblioteca estándar (std) se usa junto con el operador de extracción para aceptar la entrada de C++ desde el teclado como entrada estándar?
  - :cin: Correcto! Significa entrada de caracteres, del inglés *character input*
    :raw_input: Eso es en Python, no en C++!
    :input: Eso es en Python, no en C++!
    :scanf: Eso es en C, no en C++!
    :default: Incorrecto. Por favor, intente nuevamente.
