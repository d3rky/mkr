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
    MatrixElement elem;

    elem = {
        point->get_plate()->get_point_num(point->get_j(), point->get_i()),
        point->get_plate()->get_point_num(point->get_j(), point->get_i()),
        1.0
    };

    #ifdef DEBUG
        cout<<endl<<"Get value for DerichleBoundaryCondition: "<<endl;
        cout<<" - Point j "<<point->get_j()<<" i "<<point->get_i()<<endl;
        cout<<" - Point num "<<point->get_plate()->get_point_num(point->get_j(), point->get_i())<<endl;
        cout<<" - value "<<this->k*dt + this->b<<endl;
    #endif

    result.push_back(elem);

    elem = {
        -1,
        point->get_plate()->get_point_num(point->get_j(), point->get_i()),
        this->k*dt + this->b
    };

    result.push_back(elem);

    return result;
};
