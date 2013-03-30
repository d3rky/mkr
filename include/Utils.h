#ifndef UTILS_H

#define UTILS_H

#include <vector>

using namespace std;

struct Properties {
    float w;
    float h;

    float dx;
    float dy;
    float dt;

    float initial;

    float eps;

    float t;
    Properties(float w, float h, float dx, float dy, float dt, float i, float eps, float t) 
    : w(w), h(h), dx(dx), dy(dy), dt(dt), initial(i), eps(eps), t(t) {};
    Properties() {}
};

/**
 * @enum Направление вектора вдоль оси
 */
enum Direction {
    POSITIVE=1,
    NEGATIVE=-1
};

/**
 * @struct Структура для составляющей части матрицы 
 */
struct MatrixElement {
    int i;
    int j;
    float value;
    MatrixElement(int i, int j, float value) : i(i), j(j), value(value) {}
};

/**
 * @class Матрица
 */
class Matrix {

    private:
        /**
         * Матрица элементов
         */
        float** matrix;
        /**
         * Матрица правых частей
         */
        float* b;

        /**
         * Размерность матрицы
         */
        const int width;
        const int height;

    public:

        /**
         * @constructor
         *
         * @param width {const int}
         * @param height {const int}
         */
        Matrix(const int width, const int height);

        ~Matrix();

        /**
         * Добавить элемент в матрицу
         *
         * @param {MatrixElement}
         */
        void add(MatrixElement);
        /**
         * Добавить несколько элементов в матрицу
         *
         * @param {vector<MatrixElement>}
         */
        void add(vector<MatrixElement>);

        /**
         * @return {float**}
         */
        float** get_matrix();
        /**
         * @return {float*}
         */
        float* get_matrix_values();

        /**
         * @return {const int}
         */
        const int get_width();
        /**
         * @return {const int}
         */
        const int get_height();

        /**
         */
        void print();

};

#endif
