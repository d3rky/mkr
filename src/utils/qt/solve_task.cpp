#include <iostream>
#include <fstream>

#include <QApplication>

#include "../../../include/Plate.h"
#include "../../../include/Solver.h"
#include "../../../include/PlateDiscret.h"
#include "../../../include/Utils.h"

#include "../../../include/ui/MainWindow.h"
#include "../../../include/ui/ResultEvent.h"

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

    //Наше главное окно
    MainWindow* main_window = MainWindow::instance();

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

        QApplication::sendEvent(main_window, new ResultEvent(matrix));

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