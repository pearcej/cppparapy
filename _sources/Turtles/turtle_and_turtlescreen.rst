Tortugas y TurtleScreen
=====================

Las tortugas deben existir en un :code:`TurtleScreen` para ser utilizadas. Esta es una diferencia significativa de
Python, ya que debe crear su propia pantalla *antes* de crear un objeto :code:`Tortuga`.

.. code-block:: cpp

    ct::TurtleScreen screen;
    ct::Turtle turtle(screen);
    //Observe cómo se le da la pantalla a nuestra tortuga cuando la creamos.

Cerrar un :code:`TurtleScreen` funciona exactamente como lo hace en Python. Para este capítulo, solo se usa :code:`bye`.
Llamarlo no es completamente necesario, ya que también se llama automáticamente si no se ha llamado a él o a un método equivalente.
Cuando se trabaja fuera del libro de texto, el método :code:`exitonclick` también está disponible.

.. code-block:: cpp

    screen.bye();

Las tortugas se basan en la siguiente premisa: "Hay una tortuga en un lienzo con un bolígrafo de color
unido a su cola". En este caso, el *lienzo* es un :code:`TurtleScreen`. Esta Tortuga
seguir cualquier orden que le des, que consiste en decirle que vaya en ciertas direcciones, de qué color
de bolígrafo a utilizar, cuándo subir o bajar su bolígrafo, y otros. A continuación se muestra un esquema de los más utilizados
métodos cuando se trabaja con tortugas.

=================  ==========================================================================
    Nombre                                  Descripción
=================  ==========================================================================
turtle.left        gira la tortuga un cierto número de unidades hacia la izquierda.
turtle.right       gira la tortuga un cierto número de unidades a la derecha.
turtle.penup       levanta el lapicero de pintura en el extremo de la cola de la tortuga.
turtle.pendown     baja el lapicero de pintura en el extremo de la cola de la tortuga.
turtle.fillcolor   le dice a la tortuga de qué color será el interior de la forma. 
turtle.beginfill   le dice a la tortuga que comience a llenar una forma a medida que se mueve.
turtle.endfill     le dice a la tortuga que termine de llenar la forma que ha creado mientras se movía.
turtle.pencolor    le dice a la tortuga con qué color dibujará. 
turtle.width       le dice a la tortuga qué tan grande debe usar una lapicero de pintura.
turtle.speed       le dice a la tortuga qué tan rápido debe ir, más rápido o más lento que la liebre.
turtle.back        mueve la tortuga hacia atrás un número de unidades.
turtle.forward     mueve la tortuga hacia adelante un número de unidades.
turtle.goto        le dice a la tortuga que se mueva a una coordenada específica.
turtle.write       le dice a la tortuga que escriba algún tipo de texto.
=================  ==========================================================================

Muchos de estos métodos se utilizan junto con otros para crear diferentes imágenes. Todas las configuraciones de :code:`speed`
con los que puede estar familiarizado Python también están disponibles en CTurtle. Todas las velocidades se miden en un rango de 1 a 10,
siendo este último el más rápido y el primero el más lento. La excepción es la velocidad más rápida, :code:`TS_FASTEST`,
que se establece en 0 al igual que para el equivalente de Python :code:`"fastest"`. El prefijo :code:`TS` representa "Velocidad de tortuga".

===================== ============== ==========
Nombre Turtle Python  Nombre C-Turtle  Velocidad
===================== ============== ==========
     "el más rápido"   TS_FASTEST       0
     "rápido"            TS_FAST       10
     "normal"          TS_NORMAL        6
     "despacio"        TS_SLOW          3
     "el más despacio" TS_SLOWEST       1
===================== ============== ==========

Considere el siguiente ejemplo anotado.

.. activecode:: cturtle_4
    :language: cpp

    #include <CTurtle.hpp>
    namespace ct = cturtle;

    int main() {
        //Cree una pantalla de tortuga y agregue nuestra tortuga a ella.
        ct::TurtleScreen screen;
        ct::Turtle turtle(screen);
        
        //Establecer la velocidad de la tortuga en la opción más lenta disponible.
        turtle.speed(ct::TS_SLOWEST);
        //Cualquier número del 0 al 10 también funcionaría.
        //turtle.speed(7);
        
        //Establece el color de relleno de la tortuga en morado.
        turtle.fillcolor({"purple"});
        
        //Le dice a la tortuga que comience a llenar una forma a medida que se mueve.
        turtle.begin_fill();
        
        //Le dice a la tortuga que haga un cuadrado.
        //Itera una vez por cada esquina del cuadrado.
        for (int i = 0; i < 4; i++) {
        
            //Le dice a la tortuga que avance 50 unidades.
            turtle.forward(50);
            
            //Le dice a la tortuga que gire 90 grados a la derecha.
            turtle.right(90);
        }
        
        //Le dice a la tortuga que termine de rellenar la forma que ha delineado.
        turtle.end_fill();
    
        //Cierra la pantalla de la tortuga.
        screen.bye();
        return 0;
    }

El resultado esperado sería un cuadrado morado en el centro del lienzo de la tortuga.
Si tiene experiencia con Turtles en Python, mucho de lo que ve en el ejemplo debería verse
familiar. Si no, ¡no te preocupes! Todo será cubierto en este capítulo.

El orden de las operaciones dadas a una tortuga es importante, ya que algunas acciones deben completarse
Uno después del otro. Un buen ejemplo de esto es :code:`begin_fill` y :code:`end_fill`
patrón, que debe llamarse en ese orden específico para llenar realmente una forma.

.. parsonsprob:: cturtle_question_3

    Construya un programa que llene un triángulo verde usando begin_fill y end_fill 
    usando el código de ejemplo anterior como guía.
    -----
    #include <CTurtle.hpp>
    namespace ct = cturtle;
    =====
    int main(){
    =====
        ct::TurtleScreen scr;
        ct::Turtle turtle(scr);
    =====
        turtle.fillcolor({"green"});
    =====
        turtle.begin_fill();
    =====
        for(int i = 0; i < 3; i++){
            turtle.forward(50);
            turtle.right(60);
        }
    =====
        turtle.end_fill();
    =====
        scr.bye();
    =====
        return 0;
    =====
    }

Hay 14 métodos de uso común para las tortugas. Muchos de ellos tienen nombres que indican lo que hacen.
¡Vea si puede hacer coincidir la descripción de cada método con sus nombres!

.. dragndrop:: cturtle_dnd_1
   :match_1: doblar a la izquierda.|||turtle.left
   :match_2: gira a la derecha.|||turtle.right
   :match_3: levantar el lapicero.|||turtle.penup
   :match_4: poner el lapicero abajo.|||turtle.pendown
   :match_5: con que color rellenar el dibujo.|||turtle.fillcolor
   :match_6: empezar a llenar la forma.|||turtle.beginfill
   :match_7: deja de llenar la forma.|||turtle.endfill
   :match_8: cambiar el color de la pluma.|||turtle.pencolor
   :match_9: cambiar el tamaño de la pluma.|||turtle.width
   :match_10: cambiar la velocidad. |||turtle.speed

   Haga coincidir las descripciones de los métodos de tortuga con los métodos a los que pertenecen.
