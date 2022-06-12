Características Avanzadas
=================

Las tortugas son una gran herramienta y, por lo tanto, tienen muchas opciones que dictan cómo funcionan.
Algunas características y funcionalidades son más complicadas que otras, relacionadas con el funcionamiento interno.
de las propias tortugas. Algunos de estos incluyen los métodos :code:`tracer` y :code:`undo`, y también modos de pantalla.

Los modos de pantalla dictan la dirección de las mediciones de ángulos. Esto significa que, dependiendo del modo en el que se encuentre un :code:`TurtleScreen`
el objeto está dentro, los ángulos positivos podrían representar rotaciones en el sentido de las agujas del reloj o en el sentido contrario a las agujas del reloj. El método :code:`mode`
for :code:`TurtleScreen` te permite establecer en qué modo está una pantalla.

=========== ================ ================
    Mode        Rotación         Ángulos 
=========== ================ ================
SM_STANDARD       Este       Counterclockwise
  SM_LOGO         Norte         Clockwise
=========== ================ ================

Con respecto a los ángulos, las tortugas pueden usar tanto *grados* como *radianes* para sus rotaciones. Puede elegir entre los dos usando el
Métodos :code:`radianes` y :code:`grados` para el objeto Tortuga. De forma predeterminada, todos los ángulos se miden en *grados*. Esta opción
solo afecta los métodos relacionados con la rotación, como :code:`left` y :code:`right`.
.. code-block:: cpp

    turtle.degrees();
    turtle.right(90);//giro de 90 grados a la derecha
    turtle.radians();
    turtle.left(1.5708f);//Rotación equivalente en radianes hacia la izquierda.

The :code:`tracer(N)` method is used to control how many times the Turtle is actually
drawn on the screen. This method belongs to the :code:`TurtleScreen` object, and effects
all turtles that are on the screen. The :code:`N` in the method represents the input,
only allowing the :code:`TurtleScreen` to display one frame out every :code:`N`.

.. core-block:: cpp

    screen.tracer(12);
    //Muestra uno de cada 12 fotogramas de animación.

Esto se puede combinar con el método :code:`speed` disponible para las tortugas para lograr **muy** rápidamente
imágenes dibujadas. La velocidad máxima que puede tener una Tortuga, :code:`TS_FASTEST`, deshabilita completamente la animación
para tortugas entre movimientos y rotaciones. Esto permite que la configuración :code:`tracer` se relacione directamente
al número total de acciones que realiza la tortuga. Las acciones que realiza la tortuga suceden independientemente
de si se muestran o no en la pantalla.

.. code-block:: cpp

    screen.tracer(3); //Muestra uno de cada 3 cuadros de animación.
    turtle.speed(ct::TS_FASTEST);  //Disabilita la animación de  la tortuga

    turtle.forward(50);//Esto no se muestra en la pantalla...
    turtle.right(90);//Esto tampoco...
    turtle.forward(50);//Pero esta acción es, porque es tercero de tres.

Se agrega un cuadro de animación para casi todas las acciones que realiza una tortuga, independientemente de si
la tortuga se está moviendo o agregando algo a la pantalla. Esto incluye métodos como
:code:`begin_fill` y :code:`end_fill`, que no hacen nada visualmente pero sí
dígale a la tortuga que comience o deje de rastrear sus propios movimientos.

Considere el siguiente ejemplo y las preguntas relacionadas.

.. code-block:: cpp

    #include <CTurtle.hpp>
    namespace ct = cturtle;
    
    int main(){
        ct::TurtleScreen screen;
        ct::Turtle turtle(screen);

        turtle.speed(ct::TS_FASTEST);
        screen.tracer(6);

        for(int i = 0; i < 3; i++){
            turtle.right(60);
            turtle.forward(50);
        }   

        screen.bye();

        return 0;
    }

.. mchoice:: cturtle_advanced_mchoice_1
   :answer_a: 3
   :answer_b: 6
   :answer_c: 1
   :answer_d: 12
   :correct: c
   :feedback_a: Incorrecto! Considere cuántas acciones realiza la tortuga en el bucle for.
   :feedback_b: Incorrecto! Considere la configuración del trazador para la pantalla.
   :feedback_c: Correcto!
   :feedback_d: Incorrecto! Considere cuántas acciones realiza la tortuga en el bucle for.

   ¿Cuántos cuadros de animación crea el código anterior?

De manera similar a la configuración del rastreador, cada acción que realiza una tortuga también se agrega a la *cola de deshacer*. Esto le permite hacer un seguimiento
de las acciones que está realizando durante un período de tiempo. La cola solo puede crecer hasta cierto tamaño, a partir de 100 acciones en total.
Esto es modificable a través del método :code:`setundobuffer` que pertenece a las tortugas. Cada acción se suma, incluso si
la acción no cambia nada visualmente. Esta función es comparable a la herramienta "deshacer" disponible en la mayoría de los editores de texto.
Las tortugas pueden "deshacer" su progreso con el método :code:`undo`.

.. mchoice:: cturtle_advanced_mchoice_2
    :answer_a: 3
    :answer_b: 6
    :answer_c: 1
    :answer_d: 12
    :correct: b
    :feedback_a: Incorrecto! Considere cuántas acciones realiza la tortuga en el bucle for.
    :feedback_b: Correcto!
    :feedback_c: Incorrecto! Considere recibir acciones para realizar la tortuga en el bucle.
    :feedback_d: Incorrecto! Considere cuántas acciones realiza la tortuga en el bucle for.

    ¿Cuántas acciones habrá en la cola de deshacer de la tortuga para el código anterior?
