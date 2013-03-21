#ifndef DERICHLE_BOUNDARY_CONDITION_H

#define DERICHLE_BOUNDARY_CONDITION_H

#include "AbstractBoundaryCondition.h"

/**
 * @class Класс для граничных условий 1-ого рода (типа Дерихле) 
 */
class DerichleBoundaryCondition: public AbstractBoundaryCondition {

    public:
        /**
         * @constructor
         *
         * @param k {float} значение граничного условия
         * @param b {float} значение граничного условия (kx+b)
         */
        DerichleBoundaryCondition(float k, float b);

        /**
         * Возвращаем значение граничного условия
         *
         * @param dt {const float} шаг дискретизации по времени
         * @param point {MkrPoint*} точка, к которой приложено граничное условие
         *
         * @return {float}
         */
        virtual vector<MatrixElement> get_value(MkrPoint* point, const float dt);


};

#endif
