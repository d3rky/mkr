#include "../../include/DerichleBoundaryCondition.h"

#ifdef DEBUG
    #include <iostream>

    using namespace std;
#endif

////////////////////////////////////////////////////////////////////////////////
/**
 * constructors
 */

DerichleBoundaryCondition::DerichleBoundaryCondition(float k, float b): AbstractBoundaryCondition(k, b) {
    ;
};

////////////////////////////////////////////////////////////////////////////////
/**
 * public functions
 */

vector<MatrixElement> DerichleBoundaryCondition::get_value(MkrPoint* point, const float dt=0) {
    vector<MatrixElement> result;
    MatrixElement elem = MatrixElement(0.0, 0.0, 0.0);

    elem = MatrixElement(
        point->get_plate()->get_point_num(point->get_i(), point->get_j()),
        point->get_plate()->get_point_num(point->get_i(), point->get_j()),
        1.0
    );

    result.push_back(elem);

    elem = MatrixElement(
        -1,
        point->get_plate()->get_point_num(point->get_i(), point->get_j()),
        this->k*dt + this->b
    );

    result.push_back(elem);

    return result;
};
