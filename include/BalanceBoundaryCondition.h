#ifndef BALANCE_CONDITION_H

#define BALANCE_CONDITION_H

#include "AbstractBoundaryCondition.h"
#include "Utils.h"

/**
 * @class Класс граничных условий 3-его рода
 */
class BalanceBoundaryCondition: public AbstractBoundaryCondition {
    
    protected:

        /**
         * Направление вдоль нормали
         */
        const int direction;

    public:

        /**
         * @constructor
         *
         * @param direction {enum: Utils.h/Direction} направление вдоль нормали
         */
        BalanceBoundaryCondition(const int direction);

        virtual vector<MatrixElement> get_value(MkrPoint* point, const float dt);

};

#endif
