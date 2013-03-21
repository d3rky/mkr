#include <math.h>

#include "../../include/GaussSeidel.h"

////////////////////////////////////////////////////////////////////////////////
/**
 * constructors
 */
GaussSeidel::GaussSeidel(const float eps): Solver(eps) {
    ;
};

////////////////////////////////////////////////////////////////////////////////
/**
 * private functions
 */
bool GaussSeidel::converge(float* x, float* xp, const int n) {
    for (int i=0; i < n; i++)  {
        if (fabs(x[i] - xp[i]) >= eps) 
            return false;
    }
    return true;
};

////////////////////////////////////////////////////////////////////////////////
/**
 * public functions
 */
float* GaussSeidel::solve(Matrix* matrix) {
    float* result = new float[matrix->get_height()];
    float* prev_result = new float[matrix->get_height()];
    float** mat = matrix->get_matrix();
    float* b = matrix->get_matrix_values();

    for(int i=0; i<matrix->get_height(); i++) {
        result[i] = 0.0;
        prev_result[i] = 0.0;
    }

    do {

        for(int i=0; i<matrix->get_height(); i++) {
            float var = 0.0;
        
            for(int j=0; j<matrix->get_width(); j++) {
                if(j != i) { 
                    var += (mat[i][j] * result[j]);
                }
            }
            prev_result[i] = result[i];
            result[i] = (b[i] - var) / mat[i][i];
        }
    } while(!this->converge(result, prev_result, matrix->get_height()));


    return result;
};
