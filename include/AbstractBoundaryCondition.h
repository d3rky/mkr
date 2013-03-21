#ifndef ABSTRACT_BOUNDARY_CONDITION_H

#define ABSTRACT_BOUNDARY_CONDITION_H

#include <vector>

#include "Utils.h"
#include "MkrPoint.h"

class MkrPoint;

using namespace std;

/**
 * @class Абстрактный класс для граничных условий
 */
class AbstractBoundaryCondition {

    protected:
        float k;
        float b;

    public:
        /**
         * @constructor
         */
        AbstractBoundaryCondition(float k, float b) {
            this->b = b;
            this->k = k;
        };

        /**
         * Чисто виртуальная функция, которая возвращает значение
         * граничного условия. Для граничных условий 2-ого или 3-его рода
         * понадобятся аргументы
         */
        virtual vector<MatrixElement> get_value(MkrPoint* point=0, const float dt=0) = 0;

};

#endif
