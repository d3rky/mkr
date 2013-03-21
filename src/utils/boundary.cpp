#include "../../include/Boundary.h"

////////////////////////////////////////////////////////////////////////////////
/**
 * constructors
 */

/**
 * @constructor
 */
Boundary::Boundary(const float f, const float t): from(f), to(t) {
    ;
};

////////////////////////////////////////////////////////////////////////////////
/**
 * public functions
 */

/**
 * Возвращаем начало границы
 */
const float Boundary::get_from() {
    return this->from;
};

/**
 * Возвращаем конец границы
 */
const float Boundary::get_to() {
    return this->to;
};
