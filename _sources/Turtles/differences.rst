Las Tortugas de Python vs C-Turtle
==========================================

:code:`C-Turtle` varia de la biblioteca de Python :code:`turtle` primordialmete en la sintaxis. La mayoría de los métodos 
son exactamente los mismos, pero hay algunas diferencias notables. Los colores, por ejemplo, deben ser rodeados por llaves ( '{' and '}')¨
cuando se usan los nombres de los colores como "red", "green", o "blue". También puede usar un color aleatorio usando la cadena "random". 

.. code-block:: cpp

    ct::Color red   = {"red"};
    ct::Color green = {"green"};
    ct::Color blue  = {"blue"};
    ct::Color random = {"random"};

    //This works due to the variable above...
    turtle.pencolor(red);

    //And so do these.
    turtle.pencolor({"green"});
    turtle.pencolor({"random"});

A diferencia de Python, el método :code:`write` no permite que especifique ni la fuente ni el tamaño de las letras. Esto es debido al complejo manejo
and of Fonts by operating systems that is far more cumbersome to manage in C++. Furthermore, there is no "world" screen mode like
there is in Python. Normally, this would allow you to specify the "bounds" of your canvas (e.g, specify minimum
and maximum coordinates for your canvas).

Default shapes are also different and somewhat limited in comparison. Python offers six shapes by default, being "arrow", "circle",
"turtle", "square", "triangle", and "classic". :code:`C-Turtle`, on the other hand, offers four shapes by default: "arrow", "triangle",
"indented triangle", and "square".

Hay algunos métodos de utilidad disponibles en :code:`C-Turtle` que no están disponibles en Python como :code:`shift` and :code:`middle`.
Este método :code:`shift` simplemente añade a las coordenadas X y Y de la tortuga. Si su tortuga está en la coordenada
600x, 400y y  :code:`shift` is called with coordinate 50x and -50y, the turtle's final position would be 650x, 350y. The latter
of the two, :code:`middle`, returns the point exactly between two other points. Vea el ejemplo de abajo.

.. code-block:: cpp

    turtle.goTo(600, 400);
    turtle.shift(50, -50);
    //Turtle position is now 650x, 350y.

.. code-block:: cpp

    ct::Point a = {400, 300};
    ct::Point b = {450, 300};

    //Should equal the point 425x, 300y.
    ct::Point middle = ct::middle(a, b);