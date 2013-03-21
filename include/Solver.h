#ifndef SOLVER_H

#define SOLVER_H

#include "Utils.h"

class Solver {
    protected:
        const float eps; 

    public:
        Solver(const float eps): eps(eps) {};

        virtual float* solve(Matrix* matrix)=0;
};

#endif
