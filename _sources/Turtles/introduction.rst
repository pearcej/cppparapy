Introducción
============

C++ está diseñado con el principio de que la velocidad es más importante que la seguridad 
y la verificación de errores. Esto difiere de lenguajes como Python, que es considerablemente 
más restrictivo en aspectos como la asignación de memoria y la gestión de recursos. C ++ se 
traduce a "lenguaje de máquina" cuando se compila, que es un paso que Python omite. 
Python se salta este paso a favor de la interpretación inmediata del propio código.

Esta diferencia es lo que permite que C++ sea tan rápido como lo es, lo que también lo hace 
particularmente bueno para aplicaciones con uso intensivo de gráficos. Las aplicaciones gráficas 
aprovechan en gran medida la gestión de la memoria para mostrar cada píxel que ve en su pantalla. 
Python no permite la creación de arreglos como en C++, que son solo "pedazos" de memoria de un tamaño fijo. 
Además, ejecutarse directamente en el hardware permite que C++ se comunique mejor con otros componentes de 
su computadora, como su unidad de procesamiento de gráficos o "GPU". Esta es una de las muchas razones por 
las que C ++ se considera un estándar de la industria para aplicaciones gráficas de alto rendimiento, 
como videojuegos o software utilizado para efectos visuales en películas.

¿Qué son las tortugas?
=======================
Los gráficos de tortugas son una forma popular y sencilla de introducir la programación a los principiantes. 
Era parte del lenguaje de programación Logo original desarrollado por Wally Feurzeig, Seymour Papert y Cynthia Solomon en 1967.

Imagine tortugas como un marcador digital utilizado para dibujar varias formas,
imágenes y diseños. Dibujar con tortugas puede ser tan básico como un simple triángulo
y tan complejo como una imagen fractal altamente detallada. 
Casi todos los comandos utilizados al dibujar con Turtles son tan simples como decirle a tu Turtle que
se mueva hacia adelante, hacia atrás, hacia la izquierda y hacia la derecha en los pocos o muchos pasos que desees.

La biblioteca :code:`turtle` es comonmente usada en Python. Este capítulo cubrirá un análogo cercano para
gráficos de tortugas entre Python y C++, la biblioteca :code:`C-Turtle`.

Tortugas en C++
=======================================

Python es particularmente adecuado para fines educativos debido a su amplia gama de herramientas
integrados y buenas documentaciones. Estas cosas faltan particularmente en lo que respecta a C ++,
ya que muchas de las herramientas integradas requieren una sintaxis complicada y una comprension
profundo del lenguaje en sí. Una de estas herramientas es la biblioteca :code:`turtle`,
que es muy adecuado para fines educativos porque ofrece representaciones en vivo, interactivas
y visuales de su código.

Las representaciones visuales brindan a los estudiantes la oportunidad de observar una faceta de
las ciencias de la computación desde un punto de vista alternativo: en lugar de esperar ansiosamente
a que aparezca la declaración impresa después de que su programa se agite, obtiene una representación
visual del concepto en sí. Esto es particularmente útil para conceptos abstractos como la recursividad
y la iteración.

En C++, la biblioteca llamada :code:`C-Turtle` es usado como equivalente de la biblioteca :code:`turtle` en Python.
Actúa como un reemplazo cercano para proporcionar gráficos fáciles de usar para C++, mientras mantiene
los objetos y comandos a los que podría estar acostumbrado en Python. Fue desarrollado por Jesse Walker-Schadler
en Berea College durante el verano de 2019 y se puede encontrar en GitHub aquí: https://github.com/walkerje/C-Turtle

A continuación se muestra una comparación de las dos versiones, C++ y Python, que hacen lo mismo.
Intente ejecutar ambos y compare cómo se ve el código entre las dos versiones.

.. activecode:: cturtle_1
    :language: cpp

    #include <CTurtle.hpp>
    namespace ct = cturtle;

    int main() {
        ct::TurtleScreen scr;
        ct::Turtle turtle(scr);
        turtle.speed(ct::TS_SLOWEST);
        turtle.fillcolor({"purple"});
        turtle.begin_fill();
        for (int i = 0; i < 4; i++) {
            turtle.forward(50);
            turtle.right(90);
        }
        turtle.end_fill();
        scr.bye();
        return 0;
    }

.. activecode:: cturtle_python_1
    :language: python

    import turtle

    turt = turtle.Turtle()
    turt.fillcolor("purple")
    turt.speed("slowest")

    turt.begin_fill()
    for i in range(4):
        turt.forward(50)
        turt.right(90)
    turt.end_fill()

.. mchoice:: cturtle_question_1
    :answer_a: Los estudiantes reciben comentarios instantáneos y gratificación por su trabajo.
    :answer_b: Los estudiantes prestarán menos atención a cómo funciona su código y más atención a su resultado final.
    :answer_c: Los estudiantes se familiarizan más con los valores RGB comunes en el desarrollo web.
    :answer_d: Los estudiantes se sentirán más cómodos trabajando con conceptos a los que están acostumbrados, como Tortugas.
    :correct: a, d
    :feedback_a: Correcto!
    :feedback_b: Incorrecto, porque se debe pensar igual en el uso de las Tortugas como en el resultado.
    :feedback_c: Incorrecto, porque los valores RGB no son el enfoque o la razón detrás del uso de Turtles.
    :feedback_d: Correcto!

   ¿Cómo se beneficiarían los estudiantes de tener una representación visual como C-Turtle? Marque todo lo que corresponda.
