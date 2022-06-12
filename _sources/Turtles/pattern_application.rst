Aplicación Practica - Tessellation
====================================

El arte toma una variedad de formas, que van desde lo abstracto a lo realista, y consiste
en una variedad de materiales increíblemente amplia. Los antiguos sumerios teñían y secaban
pequeños trozos de arcilla para crear mosaicos. Estos mosaicos a menudo se componían de
formas y patrones que se superponían sin espacios entre ellos. Esta forma de arte se conoce
hoy como teselado, que se puede observar en cualquier edificio moderno que esté compuesto
de ladrillos, o cualquier piso cubierto con baldosas de cerámica. Los mosaicos se definen 
por sus formas entrelazadas, sin embargo, de qué están hechas estas formas, o el medio, varía según el artista.

Los medios comunes para esta forma de arte han cambiado con el tiempo, desde piezas
de arcilla hasta piezas de madera. Más recientemente, los medios digitales se
han utilizado como una alternativa eficaz a los materiales físicos. Las tortugas
son uno de los muchos medios digitales de este tipo y, a menudo, se utilizan para
crear imágenes ricas en características repetitivas. Su tarea será crear una imagen
de teselado similar a un mosaico utilizando tortugas.

Considere los siguientes ejemplos.

.. activecode:: cturtle_practical_example_cpp
    :language: cpp

    #include <CTurtle.hpp>
    namespace ct = cturtle;

    int main() {
        const int SQUARE_SIZE = 35;

        ct::TurtleScreen scr;
        scr.tracer(0);//deshabilitar animación
        ct::Turtle turtle(scr);
        turtle.speed(ct::TS_FASTEST);
        turtle.penup();

        for(int i = 0; i < 8; i++){
            turtle.goTo(-scr.window_width()/2,-scr.window_height()/2+ (i*SQUARE_SIZE)+SQUARE_SIZE);

            bool is_blue = i % 2 == 0;//even (true) or odd (false) row?
            
            for(int j = 0; j < 8; j++){
                ct::Color color;

                if(is_blue){
                    color = {"blue"};
                }else{
                    color = {"orange"};
                }

                turtle.begin_fill();
                turtle.fillcolor(color);

                for(int i = 0; i < 4; i++){
                    turtle.forward(SQUARE_SIZE);
                    turtle.right(90);
                }

                turtle.end_fill();

                turtle.forward(SQUARE_SIZE);
                is_blue = !is_blue;//flip-flop between true and false
            }
        }
        
        scr.bye();
        return 0;
    }

.. activecode:: cturtle_practical_example_Python
    :language: Python

    import turtle

    SQUARE_SIZE = 35

    wn = turtle.Screen()
    wn.tracer(0);
    square = turtle.Turtle()
    square.speed(10)
    square.pu()
    square.goto(-turtle.window_width()/2,turtle.window_height()/2);
    square.pd()

    a = 0
    b = 0
    for i in range(8):
        if(b == 0):
            a=1
        else:
            a=0
        for j in range(8):
            square.penup()
            square.goto(-turtle.window_width() / 2 + j * SQUARE_SIZE, (-turtle.window_height() / 2) + i * SQUARE_SIZE + SQUARE_SIZE)
            square.pendown()
            if(a==0):
                square.fillcolor('orange')
                a=1
            else:
                square.fillcolor('blue')
                a=0
            square.begin_fill()
            for k in range(4):
                square.forward(SQUARE_SIZE)
                square.right(90)
            square.end_fill()
        if(b==0):
            b=1
        else:
            b=0
    wn.tracer(1)


Debe crear una imagen similar con los siguientes criterios:

- No debe haber cuatro bordes en la forma elegida, pero 3 o 5+ está bien.
- No debe haber más de dos colores para las formas en la imagen.

.. activecode:: cturtle_practical_prompt
    :language: cpp

    #include <CTurtle.hpp>
    namespace ct = cturtle;

    int main() {
        ct::TurtleScreen scr;
        scr.tracer(0);//deshabilitar animación
        ct::Turtle turtle(scr);
        
        //Escriba su código aquí
        
        scr.bye();
        return 0;
    }

