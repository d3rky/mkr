#include <iostream>

#include "../../include/Plate.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////
/**
 * constructors
 */

Plate::Plate(const float w, const float h, float init): width(w), height(h) {
    this->initial_condition = init;
};

////////////////////////////////////////////////////////////////////////////////
/**
 * public functions
 */

const float Plate::get_width() {
    return this->width;
};

const float Plate::get_height() {
    return this->height;
};

float Plate::get_initial_cond() {
    return this->initial_condition;
};

void Plate::add_condition(PlateCondition cond) {
    this->conditions.push_back(cond);
};



AbstractBoundaryCondition* Plate::get_condition(
    float x, const float dx, float y, const float dy
) {
    AbstractBoundaryCondition* cond = 0;
    PlateSide side = this->get_plate_side(x, dx, y, dy);
    float coord;

    if(side == UP or side == DOWN) {
        coord = x;
    } else {
        coord = y;
    }

    for(vector<PlateCondition>::iterator it = this->conditions.begin(); 
        it != this->conditions.end(); 
        ++it
    ) {
        if((*it).type == side) {
            if(coord <= (*it).boundary->get_to() and coord >= (*it).boundary->get_from()) {
                cond = (*it).condition;
            }
        }
    }

    return cond;
};

PlateDiscret* Plate::descretize(const float dx, const float dy, const float dt) {
    return new PlateDiscret(this, dx, dy, dt);
};

PlateSide Plate::get_plate_side(
    float x, const float dx, float y, const float dy
) {

    PlateSide plate_side = NOT_SIDE;

    if(y == 0.0) {
        plate_side = DOWN;
    } else if(y+dy > this->get_height()) {
        plate_side = UP;
    } else {
        if(x == 0.0) {
            plate_side = LEFT;
        } else if(x+dx > this->get_width()) {
            plate_side = RIGHT;
        } else {
            plate_side = NOT_SIDE;
        }
    }

    return plate_side;
};
