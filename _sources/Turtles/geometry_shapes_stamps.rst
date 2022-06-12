Geometría, Formas y Sellos
============================

Cada forma básica en :code:`C-Turtle` es un conjunto de coordenadas. Dentro de la biblioteca :code:`C-Turtle`
tenemos la opción de unas pocas formas selectas en las que podemos habitar nuestras tortugas.
Para cambiar la apariencia de tu Tortuga, puedes usar :code:`shape` para configurar tu Tortuga a
una de las cuatro formas predeterminadas o una forma personalizada. :code:`C-Turtle` presenta cuatro formas predeterminadas, :code:`triangle`,
:code:`indented_triangle`, :code:`square` y :code:`arrow`.

El siguiente ejemplo de código muestra cómo establecer la forma de una tortuga dándole el nombre de una forma.

.. code-block:: cpp

  turtle.shape("cuadrado");

Dado que todas las formas primitivas se definen como una colección de puntos, todas las formas predeterminadas también se definen de esta manera.
Los polígonos, para formas personalizadas y predeterminadas, deben tener sus puntos definidos en el sentido contrario a las agujas del reloj para que aparezcan correctamente.
Esto se debe a las matemáticas detrás del llenado de formas arbitrarias, y es una limitación que casi todos los gráficos de computadora necesitan para
acatar. Considere el orden de sus puntos en la siguiente tabla y cómo podrían considerarse "en sentido contrario a las agujas del reloj".
Están en orden de arriba a abajo, y existe un borde entre los primeros y últimos puntos para cada una de estas formas. tenga en cuenta
que las coordenadas Y positivas son *más bajas* en la pantalla, mientras que las coordenadas Y negativas son *más altas* en la pantalla. Coordenadas en
el origen, es decir, la coordenada 0x, 0y, está en el "punto" o "punta" de la tortuga. Esta es la razón por la que la mayoría de las formas predeterminadas
tienen su primera coordenada allí.

======== ===================== ========== ========
triangulo   indented_triangle   cuadrado   flecha
======== ===================== ========== ========
(0, 0)          (0, 0)          (-5, -5)   (0, 0)
(-5, 5)        (-5, 10)          (-5, 5)  (-5, 5)      
(5, 5)          (0, 8)           (5, 5)   (-3, 5)
  .             (5, 10)          (5, 10)  (-3, 10)
  .               .                .       (3, 10)
  .               .                .       (3, 5)
  .               .                .       (5, 5)
======== ===================== ========== ========

Usar la forma por defecto :code:`indented_triangle` como ejemplo, Figura 1 muestra la naturaleza del orden en sentido antihorario.

.. figure:: cc_polygon.png
    :align: centro
    :alt: Todos los puntos deben estar orientados, en orden y en dirección a la izquierda, en relación con el centro de la forma completa.

    Figura 2: Definición de Triángulo con Sangría

El siguiente código de ejemplo ilustra cómo crear su propia forma. Usamos la clase :code:`Polygon` para representar nuestra forma.
Para este ejemplo, tomamos la forma predeterminada de :code:`triangle` y hacemos que cada coordenada Y sea negativa para que aparezca al revés.

.. code-block:: cpp

    ct::Polygon upside_down_triangle = {
      {0, 0},   //primer punto
      {-5, -5}, //segundo punto 
      {5, -5}  //etc
    };

El siguiente código es un ejemplo completo para configurar su tortuga en una forma personalizada. Siéntase libre de experimentar con
las coordenadas del polígono, ¡puede que te sorprendas con la forma que obtienga!

.. activecode:: cturtle_geometry_ac_1
    :language: cpp
    
    #include <CTurtle.hpp>
    namespace ct = cturtle;

    int main(){
        ct::TurtleScreen screen;
        screen.tracer(1, 1000);
        ct::Turtle turtle(screen);

        ct::Polygon upside_down_triangle = {
          {0, 0},   //primer punto
          {-5, -5}, //segundo punto
          {5, -5}  //etc
        };  

        turtle.shape(upside_down_triangle);
        turtle.forward(50);

        screen.bye();
        return 0;
    }

Las estampas proporcionan una forma de hacer varias copias de la forma de la tortuga en la pantalla sin tener que calcar cada una.
forma individualmente con la tortuga. Esto se puede usar para una variedad de efectos visuales, sin embargo, a menudo se usa como un
utilidad de ahorro de tiempo. Las estampas se pueden colocar con el método :code:`stamp` de los objetos Turtle, que devuelve un número entero
que actúa como **ID** del sello que se ha colocado. El método :code:`clearstamp` del objeto Tortuga puede
se puede usar para eliminar una sola estampa de la pantalla, mientras que el método :code:`clearstamps` se usa para eliminar múltiples
estampas a la vez.
 
El siguiente código es un ejemplo completo que muestra cómo combinar formas personalizadas con la colocación de estampas.

.. activecode:: cturtle_geometry_ac_2
    :language: cpp

    #include <CTurtle.hpp>
    namespace ct = cturtle;

    int main(){
        ct::TurtleScreen screen;
        screen.tracer(1, 1000);
        ct::Turtle turtle(screen);

        ct::Polygon upside_down_triangle = {
          {0, 0},   //Primer punto
          {-5, -5}, // Segundo punto
          {5, -5}  // etc.
        };  

        turtle.shape(upside_down_triangle);
        
        //Dibuja un cuadrado donde cada borde tenga 50 unidades de largo.
        for(int i = 0; i < 4; i++){
            //Estampa en las esquina del cuadrado.
            int corner_stamp = turtle.stamp();

            turtle.forward(25);
            turtle.stamp(); //Estampa a la mitad del borde del cuadrado.
            turtle.forward(25);

            turtle.right(90);
            //Limpia la estampa de las esquinas.
            turtle.clearstamp(corner_stamp);
        }

        turtle.clearstamps();

        screen.bye();
        return 0;
    }
