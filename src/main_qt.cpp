#include <iostream>
#include <fstream>
#include <vector>

#include <QtGui>

#include "../include/Plate.h"
#include "../include/PlateDiscret.h"
#include "../include/Solver.h"
#include "../include/Utils.h"

#include "../include/ui/MainWindow.h"

#define WIDTH 12
#define HEIGHT 4

using namespace std;


Plate* describe_task(const float w, const float h, float initial);
Solver* create_solver(const float eps);
void solve(const float dx, const float dy, const float dt, const float t, Plate* plate, Solver* solver);


void start_calculate(Properties prop) {
    /*
     * Создание пластины
     */
    Plate* plate = describe_task(prop.w, prop.h, prop.initial);

    /**
     * Создаем решатель
     */
    Solver* solver = create_solver(prop.eps);

    /**
     * Решаем задачу
     */
    solve(prop.dx, prop.dy, prop.dt, prop.t, plate, solver);
};


int main(int argc, char** argv) {
    
    /*
     * Описание констант и параметров пластины и задачи
     */

    //точность решения слау
    const float eps = 1E-6;

    //время расчет
    const float t = 20.0;

    //Параметры пластины
    const float w = WIDTH;
    const float h = HEIGHT;
    
    //Шаги дискретизации
    const float dx = 1;
    const float dy = 1;
    const float dt = 1;

    //начальное значение
    float initial = 10;

    Properties prop = {
        w, h,
        dx, dy, dt,
        initial,
        eps,
        t
    };

    /*
     * Gui
     */
    QApplication app(argc, argv);
    MainWindow* main_window = MainWindow::instance(prop);

    main_window->show();

    app.exec();

};
