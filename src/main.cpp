#include <iostream>
#include <fstream>
#include <vector>

#include "../include/DerichleBoundaryCondition.h"
#include "../include/NeumanBoundaryCondition.h"
#include "../include/Plate.h"
#include "../include/PlateDiscret.h"
#include "../include/Boundary.h"
#include "../include/GaussSeidel.h"

#define WIDTH 12
#define HEIGHT 4

using namespace std;

int main(int argc, char** argv) {
    
    //точность решения слау
    const float eps = 1E-6;

    //время расчет
    const float t = 20.0;

    //результат вычислений
    float* result;

    //Параметры пластины
    const float w = WIDTH;
    const float h = HEIGHT;
    
    //Шаги дискретизации
    const float dx = 1;
    const float dy = 1;
    const float dt = 1;

    //начальное значение
    float initial = 10;

    //название output файла
    const char* output_filename = "build/default.output";
    //выходной поток
    ofstream output(output_filename, ios::trunc | ios::out);

    cout<<endl<<"Creating conditions...";
    
    //Задаем граничные условия
    PlateCondition down_cond = {
        DOWN, 
        new NeumanBoundaryCondition(0, 0, POSITIVE), 
        new Boundary(1, WIDTH)
    };
    PlateCondition up_right_cond = {
        UP,
        new NeumanBoundaryCondition(0, 0, POSITIVE),
        new Boundary(WIDTH/2.0, WIDTH)
    };
    PlateCondition up_left_cond = {
        UP,
        new DerichleBoundaryCondition(0, 500),
        new Boundary(1, WIDTH/2)
    };
    PlateCondition left_cond = {
        LEFT,
        new DerichleBoundaryCondition(0, 500),
        new Boundary(1, HEIGHT)
    };
    PlateCondition right_cond = {
        RIGHT,
        new DerichleBoundaryCondition(0, 500),
        new Boundary(1, HEIGHT)
    };

    cout<<"OK"<<endl;

    cout<<endl<<"Creating plate...";

    //Создаем объект-пластину
    Plate* plate = new Plate(w, h, initial);

    cout<<"OK"<<endl;

    cout<<endl<<"Creating solver...";

    //Создаем решатель
    Solver* solver = new GaussSeidel(eps);

    cout<<"OK"<<endl;

    cout<<endl<<"Adding conditions to plate...";

    //Добавляем к ней граничные условия
    plate->add_condition(down_cond);
    plate->add_condition(up_right_cond);
    plate->add_condition(up_left_cond);
    plate->add_condition(left_cond);
    plate->add_condition(right_cond);

    cout<<"OK"<<endl;

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
