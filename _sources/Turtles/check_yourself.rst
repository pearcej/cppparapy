Compruébalo tú mismo
==============

.. activecode:: turtle_checkyourself_ac_1
    :language: cpp

    #include <CTurtle.hpp>
    namespace ct = cturtle;

    int main() {
        ct::TurtleScreen scr;
        ct::Turtle turtle(scr);

        turtle.begin_fill();

        for(int i = 0; i < 4; i++){
            turtle.forward(50);
            turtle.right(90);
        }

        turtle.end_fill();

        scr.bye();
        return 0;
    }

.. mchoice:: turtle_checkyourself_mchoice_1
   :answer_a: 13
   :answer_b: 10
   :answer_c: 8
   :answer_d: 4
   :correct: b
   :feedback_a: No, piense en cuantas veces fill es usado....
   :feedback_b: Correcto!
   :feedback_c: Incorrecto! Considere que casi todo lo que hace una tortuga es una acción, incluso el relleno.
   :feedback_d: Incorrecto! Considere que hay algunas acciones en un bucle for.

   ¿Qué tan grande sería la cola de deshacer para el ejemplo de código anterior?

.. code-block:: cpp

    #include <CTurtle.hpp>
    namespace ct = cturtle;

    int main() {
        ct::TurtleScreen scr;
        ct::Turtle turtle(scr);

        for(int i = 0; i < 5; i++){
            turtle.forward(50);
            turtle.right(144);
        }

        scr.bye();
        return 0;
    }

.. mchoice:: turtle_checkyourself_mchoice_2
   :answer_a: Círculo
   :answer_b: Ninguna forma
   :answer_c: Pentágono
   :answer_d: Estrella
   :correct: d
   :feedback_a: Incorrecto! Considere cuántas veces itera el bucle for...
   :feedback_b: Incorrecto! The turtle's pen is always down.
   :feedback_c: Incorrecto! Considere el ángulo la tortuga gira con cada iteración.
   :feedback_d: Correcto!

   ¿Qué tipo de forma crea el activecode anterior?

.. mchoice:: turtle_checkyourself_mchoice_3
  :answer_a: Verdadero
  :answer_b: Falso
  :correct: a
  :feedback_a: Correcto!
  :feedback_b: Incorrecto!

   Puede tener más de una tortuga en una pantalla.