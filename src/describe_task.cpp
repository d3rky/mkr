#include <iostream>
#include <fstream>

#include "../include/Plate.h"
#include "../include/DerichleBoundaryCondition.h"
#include "../include/NeumanBoundaryCondition.h"
#include "../include/Boundary.h"
#include "../include/GaussSeidel.h"

using namespace std;

/**
 * Создаем условие
 *
 * @param w {const float} ширина
 * @param h {const float} высота
 * @param initial {float} начальное значение
 */
Plate* describe_task(
    const float w,
    const float h,
    float initial
) {
    cout<<endl<<"Creating conditions...";
    
    //Задаем граничные условия
    PlateCondition down_cond = {
        DOWN, 
        new NeumanBoundaryCondition(0, 0, POSITIVE), 
        new Boundary(0, w)
    };
    PlateCondition up_right_cond = {
        UP,
        new NeumanBoundaryCondition(0, 0, POSITIVE),
        new Boundary(w/2.0, w)
    };
    PlateCondition up_left_cond = {
        UP,
        new DerichleBoundaryCondition(0, 500),
        new Boundary(0, w/2)
    };
    PlateCondition left_cond = {
        LEFT,
        new DerichleBoundaryCondition(0, 500),
        new Boundary(0, h)
    };
    PlateCondition right_cond = {
        RIGHT,
        new DerichleBoundaryCondition(0, 500),
        new Boundary(0, h)
    };

    cout<<"OK"<<endl;

    cout<<endl<<"Creating plate...";

    //Создаем объект-пластину
    Plate* plate = new Plate(w, h, initial);

    cout<<"OK"<<endl;

    cout<<endl<<"Adding conditions to plate...";

    //Добавляем к ней граничные условия
    plate->add_condition(down_cond);
    plate->add_condition(up_right_cond);
    plate->add_condition(up_left_cond);
    plate->add_condition(left_cond);
    plate->add_condition(right_cond);

    cout<<"OK"<<endl;

    return plate;
};

/**
 * Создаем решатель
 *
 * @param eps {const float} точность решения
 *
 * @return {Solver*} решатель
 */
Solver* create_solver(const float eps) {
    cout<<endl<<"Creating solver...";

    Solver* solver = new GaussSeidel(eps);

    cout<<"OK"<<endl;

    return solver;
};
