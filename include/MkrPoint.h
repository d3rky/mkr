#ifndef MKR_POINT_H

#define MKR_POINT_H

#include <vector>

#include "AbstractBoundaryCondition.h"
#include "PlateDiscret.h"

class PlateDiscret;

/**
 * @class Класс для точек, 
 */
class MkrPoint {
    
    private:
        
        /**
         * Координаты точки
         */
        const float x;
        const float y;

        /**
         * Номер точки
         */
        const int i;
        const int j;

        /**
         * Если точка граничная, то какая-это граница
         */
        const int boundary_type;

        /**
         * Граничное условие, которое привязано к этой точке
         */
        AbstractBoundaryCondition* boundary_condition;

        /**
         * Начальное условие
         */
        float initial_condition;

        /**
         * Пластина, к которой принадлежит точка
         */
        PlateDiscret* plate;

    public:

        /**
         * @constructor
         *
         * @param x {const float} координат x точки
         * @param y {const float} координата y точки
         * @param i {const int} номер столбца
         * @param j {const int} номер строки
         * @param boundary_type {const int} тип границы (UP, DOWN, etc.)
         * @param initial_cond {float} начальное условие
         * @param bound_cond {AbstractBoundaryCondition*} граничное условие
         * @param plate {PlateDiscret*} пластина, к которой принадлежит точка
         */
        MkrPoint(
            const float x, const float y, 
            const int i, const int j,
            const int boundary_type,
            float initial_cond, 
            AbstractBoundaryCondition* bound_cond,
            PlateDiscret* plate
        );

        /**
         * @return {const float}
         */
        const float get_x();
        /**
         * @return {const float}
         */
        const float get_y();
        /**
         * @return {const int}
         */
        const int get_i();
        /**
         * @return {const int}
         */
        const int get_j();

        /**
         * @return {AbstractBoundaryCondition*}
         */
        AbstractBoundaryCondition* get_boundary_cond();
        /**
         * Возвращаем значение граничного условия для точки
         *
         * @param dt {const float}
         *
         * @return {float}
         */
        vector<MatrixElement> get_boundary_cond_value(const float dt);
        /**
         * @return {const float}
         */
        const float get_initial_cond();

        /**
         * @return {PlateDiscret*}
         */
        PlateDiscret* get_plate();

        /**
         * @return {const int}
         */
        const int get_boundary_type();

        /**
         * Устанавливаем начальное значение температуры
         *
         * @param value {float}
         */
        void set_initial_cond(float value);
};

#endif
