ABOUT
=====

Laboratory work №1.

For information on about how to build and run the project, please see HOWTO.txt.

ABOUT THE TASK
==============

The task is to simulate the heat of plate (only plate is available) with size w*h, 
using the heat equation:
     dT/dt = d^2x/dt^2 + d^2y/dt^2

The equation is solved implicitly.

You can also set initial condition of the set. There are two types of boundary condition:
 - Derichle boundary condition. It is set as T = k*t + b,
 - Neuman boundary condition. dT/dn = k*t + b.
 - Balance boundary condition dT/dn = T

DEPENDING
=========

Now it depends only on Qt 4.8
