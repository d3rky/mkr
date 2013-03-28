#ifndef BALANCE_CONDITION_H

#define BALANCE_CONDITION_H

#include "AbstractBoundaryCondition.h"
#include "Utils.h"

/**
 * @class Класс граничных условий 3-его рода
 */
class BalanceBoundaryCondition: public AbstractBoundaryCondition {

    public:

        /**
         * @constructor
         *
         */
        BalanceBoundaryCondition();

        virtual vector<MatrixElement> get_value(MkrPoint* point, const float dt);

};

#endif
