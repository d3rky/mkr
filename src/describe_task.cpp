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
        new Boundary(1, w)
    };
    PlateCondition up_right_cond = {
        UP,
        new NeumanBoundaryCondition(0, 0, POSITIVE),
        new Boundary(w/2.0, w)
    };
    PlateCondition up_left_cond = {
        UP,
        new DerichleBoundaryCondition(0, 500),
        new Boundary(1, w/2)
    };
    PlateCondition left_cond = {
        LEFT,
        new DerichleBoundaryCondition(0, 500),
        new Boundary(1, h)
    };
    PlateCondition right_cond = {
        RIGHT,
        new DerichleBoundaryCondition(0, 500),
        new Boundary(1, h)
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

/**
 * Решаем задачу
 *
 * @param dx {const float} шаг дискретизации по x
 * @param dy {const float} шаг дискретизации по y
 * @param dt {const float} шаг дискретизации по времени
 * @param t {const float} время, до которого идет расчет
 * @param plate {Plate*} пластина
 * @param solver {Solver*} решатель СЛАУ
 */
void solve(const float dx, const float dy, const float dt, const float t, Plate* plate, Solver* solver) {

    //название output файла
    const char* output_filename = "build/default.output";
    //выходной поток
    ofstream output(output_filename, ios::trunc | ios::out);

    //результат вычислений
    float* result;

    cout<<endl<<"Discretizing plate...";

    //Разбиваем пластину на узлы
    PlateDiscret* plate_discret = plate->descretize(dx, dy, dt);

    cout<<"OK"<<endl;

    cout<<endl<<"Starting solving..."<<endl;
    cout<<"End solving at time "<<t<<endl;

    //Из текущей модели получаем матрицу, которую и будем решать
    Matrix* matrix = plate_discret->get_matrix();

    //Решаем уравнение
    for(float curr_t=0.0; curr_t<t; curr_t+=dt) {
        result = solver->solve(matrix);

        plate_discret->set_initial_values(result);

        matrix = plate_discret->get_matrix();

        cout<<endl;
        cout<<"/////////////////////////////////////////////////////////////////////"<<endl;
        cout<<"Start printing result matrix after "<<curr_t<<" units of simulation"<<endl<<endl;
    
        plate_discret->print(cout);
    
        cout<<endl<<"End printing result matrix."<<endl;
        cout<<"/////////////////////////////////////////////////////////////////////"<<endl;
    }

    cout<<endl<<endl<<"Writing results to file "<<output_filename<<endl;

    plate_discret->print(output);

    output.close();
};
