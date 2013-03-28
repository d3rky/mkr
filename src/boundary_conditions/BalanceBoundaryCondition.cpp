#include "../../include/BalanceBoundaryCondition.h"

////////////////////////////////////////////////////////////////////////////////
/**
 * constructors
 */
BalanceBoundaryCondition::BalanceBoundaryCondition(): AbstractBoundaryCondition(0, 0) {
    ;  
};

////////////////////////////////////////////////////////////////////////////////
/**
 * public functions
 */
vector<MatrixElement> BalanceBoundaryCondition::get_value(MkrPoint* point, const float dt=0) {
    vector<MatrixElement> result;
    MatrixElement elem;

    int x_offset = 0;
    int y_offset = 0;

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

    float dn;

    if(x_offset != 0) {
        dn = point->get_plate()->get_dx();
    } else {
        dn = point->get_plate()->get_dy();
    }

    elem = {
        point->get_plate()->get_point_num(point->get_i(), point->get_j()),
        point->get_plate()->get_point_num(point->get_i(), point->get_j()),
        -1.0*(1+dn)
    };
    result.push_back(elem);

    elem = {
        point->get_plate()->get_point_num(point->get_i(), point->get_j()),
        point->get_plate()->get_point_num(point->get_i()+y_offset, point->get_j()+x_offset),
        1.0
    };
    result.push_back(elem);

    elem = {
        -1,
        point->get_plate()->get_point_num(point->get_i(), point->get_j()),
        0.0
    };
    result.push_back(elem);

    return result;
};
