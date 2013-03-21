#include "../../include/NeumanBoundaryCondition.h"

#ifdef DEBUG
    #include <iostream>

    using namespace std;
#endif

////////////////////////////////////////////////////////////////////////////////
/**
 * constructors
 */

NeumanBoundaryCondition::NeumanBoundaryCondition(
    float k, 
    float b,
    const int direction
): AbstractBoundaryCondition(k, b), direction(direction) {
    ;
};

////////////////////////////////////////////////////////////////////////////////
/**
 * public functions
 */

/**
 * Положительное направление - это направление внутрь пластины
 */
vector<MatrixElement> NeumanBoundaryCondition::get_value(MkrPoint* point, const float dt=0) {
    vector<MatrixElement> result;
    MatrixElement elem;

    int x_offset = 0;
    int y_offset = 0;

    elem = {
        point->get_plate()->get_point_num(point->get_j(), point->get_i()),
        point->get_plate()->get_point_num(point->get_j(), point->get_i()),
        1.0
    };
    result.push_back(elem);

    switch (point->get_boundary_type()) {
        case UP:
            y_offset = -1;
            break;
        case DOWN:
            y_offset = 1;
            break;
        case LEFT:
            x_offset = 1;
            break;
        case RIGHT:
            x_offset = -1;
            break;
    };

    elem = {
        point->get_plate()->get_point_num(point->get_j(), point->get_i()),
        point->get_plate()->get_point_num(point->get_j()+y_offset, point->get_i()+x_offset),
        -1.0
    };
    result.push_back(elem);

    elem = {
        -1,
        point->get_plate()->get_point_num(point->get_j(), point->get_i()),
        (this->k*dt + this->b)*this->direction
    };
    result.push_back(elem);

    return result;
};
