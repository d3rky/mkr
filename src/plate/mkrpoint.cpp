#include "../../include/MkrPoint.h"

#ifdef DEBUG
    #include <iostream>
    
    using namespace std;
#endif

////////////////////////////////////////////////////////////////////////////////
/**
 * constructors
 */

MkrPoint::MkrPoint(
    const float x, const float y,
    const int i, const int j,
    const int boundary_type,
    float initial_cond, 
    AbstractBoundaryCondition* bound_cond,
    PlateDiscret* plate
): x(x), y(y), i(i), j(j), boundary_type(boundary_type) {

    this->boundary_condition = bound_cond;
    this->initial_condition = initial_cond;
    this->plate = plate;
};

////////////////////////////////////////////////////////////////////////////////
/**
 * public functions
 */

const float MkrPoint::get_x() {
    return this->x; 
};

const float MkrPoint::get_y() {
    return this->y;
};

const int MkrPoint::get_i() {
    return this->i;
};

const int MkrPoint::get_j() {
    return this->j;
};

AbstractBoundaryCondition* MkrPoint::get_boundary_cond() {
    return this->boundary_condition;
};

vector<MatrixElement> MkrPoint::get_boundary_cond_value(const float dt) {
    AbstractBoundaryCondition* cond = this->get_boundary_cond();

    return cond->get_value(this, dt);
};

const float MkrPoint::get_initial_cond() {
    return this->initial_condition;
};

const int MkrPoint::get_boundary_type() {
    return this->boundary_type;
};

PlateDiscret* MkrPoint::get_plate() {
    return this->plate;
};

void MkrPoint::set_initial_cond(float value) {
    this->initial_condition = value;
};
