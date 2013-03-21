#ifndef PLATE_DISCRET_H

#define PLATE_DISCRET_H

#include <vector>
#include <iostream>

#include "MkrPoint.h"
#include "Plate.h"
#include "Utils.h"

using namespace std;

class Plate;
class MkrPoint;

/**
 * @class Пластина, разбитая на множество точек
 */
class PlateDiscret {
    
    private:

        /**
         * Множество точек, образующих пластину
         */
        vector<vector<MkrPoint*> > points;
        
        const float width;
        const float height;

        /**
         * Количество точек по ширине
         */
        int i;
        /**
         * Количество точек по высоте
         */
        int j;

        /**
         * Шаги дискретизации
         */
        const float dx;
        const float dy;
        const float dt;

        /**
         * Внутренняя функция, определяющая количество точек при заданной
         *      длине и шаге дискретизации
         *
         * @param len {const float} длина
         * @param step {const float} шаг дискретизации
         *
         * @return {int} количество точек
         */
        int get_num_of_points(const float len, const float step);

    public:
        /**
         * @constructor
         *
         * @param plate {Plate*} пластина, которую надо дискретизировать
         * @param dx {const float} шаг дискретизации по x
         * @param dy {const float} шаг дискретизации по y
         * @param dt {const float} шаг дискретизации по t
         */
        PlateDiscret(Plate *plate, const float dx, const float dy, const float dt);

        int get_i();
        int get_j();

        /**
         * По положению точки на пластине определяем ее номер
         *
         * @param i {const int}
         * @param j {const int}
         *
         * @return {const int}
         */
        const int get_point_num(const int i, const int j);
        /**
         * По номеру точки восстанавливаем столбец
         *
         * @param point_num {const int}
         *
         * @return {const int}
         */
        const int get_point_i(const int point_num);
        /**
         * По номеру точки восстанавливаем строку
         *
         * @param point_num {const int}
         *
         * @return {const int}
         */
        const int get_point_j(const int point_num);

        /**
         * Из модели получим матрицу
         *
         * @return {Matrix}
         */
        Matrix* get_matrix();

        /**
         * Изменяем начальное значение температуры для узлов пластины
         *
         * @param values {float*}
         */
        void set_initial_values(float* values);

        void print(ostream& stream);
};

#endif
