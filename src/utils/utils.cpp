#include <iostream>

#include "../../include/Utils.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////
/**
 * constructors
 */
Matrix::Matrix(const int width, const int height): width(width), height(height) {
    this->matrix = new float*[height];
    this->b = new float[height];

    for(int i=0; i<height; i++) {
        this->matrix[i] = new float[width];
    }

    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            this->matrix[i][j] = 0.0;
        }
        this->b[i] = 0.0;
    }
};

Matrix::~Matrix() {
    delete[] this->b;

    for(int i=0; i<this->height; i++) {
        delete[] this->matrix[i];
    }

    delete[] this->matrix;
}

////////////////////////////////////////////////////////////////////////////////
/**
 * public functions
 */
void Matrix::add(MatrixElement elem) {
    if(elem.i == -1) {
        this->b[elem.j] += elem.value;
    } else {
        this->matrix[elem.i][elem.j] += elem.value;
    }
};

void Matrix::add(vector<MatrixElement> vec_elem) {
    vector<MatrixElement>::iterator it = vec_elem.begin();

    for(; it != vec_elem.end(); ++it) {
        this->add((*it));
    }
};

float** Matrix::get_matrix() {
    return this->matrix;
};

float* Matrix::get_matrix_values() {
    return this->b;
};

const int Matrix::get_width() {
    return this->width;
};

const int Matrix::get_height() {
    return this->height;
};

void Matrix::print() {
    for(int i=0; i<this->height; i++) {
        for(int j=0; j<this->width; j++) {
            cout<<this->matrix[i][j]<<"\t";
        }

        cout<<this->b[i]<<endl;
    }

    cout<<endl;
};
