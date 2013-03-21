#ifndef GAUSS_SEIDEL_H

#define GAUSS_SEIDEL_H

#include "Solver.h"

class GaussSeidel: public Solver {
    private:
        bool converge(float* x, float* xp, const int n);

    public:
        GaussSeidel(const float eps);

        virtual float* solve(Matrix* matrix);
};

#endif
