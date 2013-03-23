#ifndef NEUMAN_BOUNDARY_CONDITION_H

#define NEUMAN_BOUNDARY_CONDITION_H

#include "AbstractBoundaryCondition.h"
#include "Utils.h"

/**
 * @class Класс для граничных условия 2-ого рода (типа Неймана)
 */
class NeumanBoundaryCondition: public AbstractBoundaryCondition {

    protected:

        /**
         * Направление вдоль этой нормали
         */
        const int direction;

    public:
        /**
         * @constructor
         *
         * @param k {float} коэффициент k линейной функции
         * @param b {float} коэффициент b линейной функции (kx+b)
         * @param direction {enum: Utils.h/Direction} направление вдоль нормали
         */
        NeumanBoundaryCondition(
            float k, 
            float b,
            const int direction
        );

        /**
         * @param point {MkrPoint*} точка, к которой приложено граничное условие
         * @param dt {const float} шаг дискретизации по времени
         *
         * @return {float}
         */
        virtual vector<MatrixElement> get_value(MkrPoint* point, const float dt);

};

#endif 
