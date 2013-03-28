#ifndef PLATE_H

#define PLATE_H

#include <vector>

#include "PlateDiscret.h"
#include "AbstractBoundaryCondition.h"
#include "Boundary.h"

using namespace std;

class PlateDiscret;
class AbstractBoundaryCondition;

/**
 * @enum стороны пластины
 */
enum PlateSide {
    NOT_SIDE=0,
    UP,
    RIGHT,
    DOWN,
    LEFT
};

/**
 * @struct Связываем граничное условие с его положением на пластине и
 *      границами действия
 */
struct PlateCondition {
    PlateSide type;
    AbstractBoundaryCondition* condition;
    Boundary* boundary; 
};

/**
 * @class класс, характеризующий пластину
 */
class Plate {
    
    private:
        
        /**
         * Ширина пластины
         */
        const float width;
        /**
         * Высота пластины
         */
        const float height;

        /**
         * Начальное условие
         */
        float initial_condition;

        /**
         * Граничные условие, приложенные к пластине
         */
        vector<PlateCondition> conditions;

    public:

        /**
         * @constructor
         *
         * @param w {const float} ширина пластины
         * @param h {const float} высота пластины
         * @param initial {float} начальное значение
         */
        Plate(const float w, const float h, float initial);

        /**
         * @return {const float}
         */
        const float get_width();
        /**
         * @return {const float}
         */
        const float get_height();
        /**
         * @return {float}
         */
        float get_initial_cond();

        /**
         * @param cond {PlateCondition} граничное условие, с привязанным местом
         *      приложения и границами
         */
        void add_condition(PlateCondition cond);

        /**
         * По координатам точки возвращаем сторону пластины
         *
         * @param x {float} координата x точки
         * @param dx {const float} шаг дискретизации по x
         * @param y {float} координата y точки
         * @param dy {const float} шаг дискретизации по y
         *
         * @return {PlateSide} сторона пластины (верхняя, нижняя, правая, левая)
         */
        PlateSide get_plate_side(
            float x,
            const float dx,
            float y,
            const float dy
        );

        /**
         * @return {vector<PlateCondition>}
         */
        const vector<PlateCondition> get_condition();

        /**
         * Определяем граничное условие, по переданной точке, из расчета, что 
         *      точка является граничной
         *
         * @param x {float} координата x точки
         * @param dx {const float} шаг дискретизации x
         * @param y {float} координата y точки
         * @param dy {const float} шаг дискретизации y
         *
         * @return {AbstractBoundaryCondition*} граничное условие
         */
        AbstractBoundaryCondition* get_condition(
            float x, 
            const float dx,
            float y,
            const float dy
        );

        /**
         * Дискретизируем пластину
         *
         * @param dx {const float} шаг дискретизации по x
         * @param dy {const float} шаг дискретизации по y
         * @param dt {const float} шаг дискретизации по t
         *
         * @return {PlateDiscret*} дискретизированная пластина (набор точек с 
         *      начальными и граничными условиями)
         */
        PlateDiscret* descretize(const float dx, const float dy, const float dt);

};

#endif
