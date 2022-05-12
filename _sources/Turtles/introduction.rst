Introduction
============

C++ is designed with the principal that speed is more important than safety and error-checking.
This differs from languages like Python, which is considerably more restrictive in regards to
aspects such as memory allocations and resource management. C++ is translated to "machine language"
when it is compiled, which is a step skipped by Python. Python skips this step in favor of immediate
interpretation of the code itself.

This difference is what allows C++ to be as fast as it is, which also makes it particularly good
for graphically-intensive applications. Graphical applications heavily leverage memory management
to display every pixel you see on your screen. Python does not allow for the creation of arrays like in
C++, which are just "chunks" of memory of a fixed size. Furthermore, running directly on the hardware
allows C++ to communicate better with other components of your computer, such as your graphics processing unit, or "GPU".
This is one of many reasons C++ is considered an industry standard for high-performance graphics applications, such as
video games or software used for visual effects in movies.

What are Turtles?
=======================
Turtle graphics are a popular and simple way for introducing programming to beginners. 
It was part of the original Logo programming language developed by 
Wally Feurzeig, Seymour Papert, and Cynthia Solomon in 1967.

Imagine turtles as being a digital marker used for drawing various shapes, images, and designs.
Drawing with Turtles can be as basic as a simple triangle and as complex as a highly detailed fractal image.
Nearly all commands used when drawing with Turtles are as simple as telling your Turtle to move forward, backward,
left, and right in as few or many steps as desired.

The :code:`turtle` library is commonly used in Python. This chapter will cover a close analog for turtle graphics between 
Python and C++, the :code:`C-Turtle` library.

Turtles in C++
=======================================

Python is particularly well-suited for educational purposes due to its
wide array of built in tools and good documentation. These things are particularly
lacking in regards to C++, as many of the built-in tools require complicated syntax
and deep understanding of the language itself. One of these tools is the :code:`turtle` library,
which is very well suited for educational purposes because it offers live, interactive,
and visual representations of your code.

Visual representations afford students an opportunity to observe a facet of computer science
from an alternative point of view: rather than waiting anxiously for the print statement
to come around after your program churns, you get a visual representation of the concept itself.
This is particularly useful for abstract concepts such as recursion and iteration.

For C++, a library called :code:`C-Turtle` is used to provide an equivalent of Python's :code:`turtle`.
It acts as a close replacement to provide easy to use graphics to C++, while maintaining
the objects and commands you might be used to in Python. It was developed by Jesse Walker-Schadler
at Berea College during the summer of 2019, and can be found on GitHub here: https://github.com/walkerje/C-Turtle

Below is a comparison of the two versions, C++ and Python, which do
the same thing. Try running both and comparing how the code looks between the two versions.

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
    :answer_a: Students receive instant feedback and gratification for their work.
    :answer_b: Students will pay less attention to how their code works, and more attention to its end result.
    :answer_c: Students get more acquainted with RGB values common in web development.
    :answer_d: Students will be more comfortable working with concepts they are used to, such as Turtles.
    :correct: a, d
    :feedback_a: Correct!
    :feedback_b: Incorrect, because equal thought must be put into the usage of Turtles as well as the outcome.
    :feedback_c: Incorrect, because RGB values are not the focus or reason behind using Turtles.
    :feedback_d: Correct!

    How might students benefit from having a visual representation such as C-Turtle? Check all that apply.
