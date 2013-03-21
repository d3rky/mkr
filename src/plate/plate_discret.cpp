#include <iostream>
#include "math.h"

#include "../../include/PlateDiscret.h"
    
using namespace std;

class AbstractBoundaryCondition;

////////////////////////////////////////////////////////////////////////////////
/**
 * private functions
 */

int PlateDiscret::get_num_of_points(const float len, const float step) {
    return floor(len/step);
}

////////////////////////////////////////////////////////////////////////////////
/**
 * constructors
 */

PlateDiscret::PlateDiscret(
        Plate *plate, 
        const float dx, 
        const float dy, 
        const float dt
): width(plate->get_width()), height(plate->get_height()), dx(dx), dy(dy), dt(dt) {

    //Определяем количество точек по x и y в зависимости от шага дискретизации
    int points_in_row = this->get_num_of_points(this->width, dx),
        points_in_col = this->get_num_of_points(this->height, dy);

    this->i = points_in_row;
    this->j = points_in_col;

    float curr_step_x=1.0,
          curr_step_y=1.0;

    //создаем точки
    for(int i=0; i<points_in_col; i++) {

        vector<MkrPoint*> points_row;

        for(int j=0; j<points_in_row; j++) {

            //Проверяем, является ли точка граничной
            int is_boundary = plate->is_boundary_point(curr_step_x, dx, curr_step_y, dy);
            AbstractBoundaryCondition* cond = 0;
            float initial = 0;

            //Если точка граничная, то задаем граничное условие
            if(is_boundary) {
                cond = plate->get_condition(curr_step_x, dx, curr_step_y, dy);
            }
            
            //Задаем начальное условие
            initial = plate->get_initial_cond();

            points_row.push_back(new MkrPoint(
                curr_step_x, curr_step_y, j, i, is_boundary, initial, cond, this
            ));

            curr_step_x += this->dx;
        }

        this->points.push_back(points_row);

        curr_step_x = 1.0;
        curr_step_y += this->dy;
    }
};

////////////////////////////////////////////////////////////////////////////////
/**
 * public functions
 */
int PlateDiscret::get_i() {
    return this->i;
};

int PlateDiscret::get_j() {
    return this->j;
};

const int PlateDiscret::get_point_num(const int i, const int j) {
    return this->get_i()*i + j;
};

Matrix* PlateDiscret::get_matrix() {
    Matrix* matrix = new Matrix(
        this->get_i()*this->get_j(),
        this->get_i()*this->get_j()
    );
    vector<vector<MkrPoint*> >::iterator it = this->points.begin();

    //коэффициенты dx^2*dx^2, dt*dy^2, dt*dx^2
    float dx2dy2 = pow(this->dx, 2)*pow(this->dy, 2),
        dtdy2 = this->dt*pow(this->dy, 2),
        dtdx2 = this->dt*pow(this->dx, 2);

    for(; it != this->points.end(); ++it) {
        for(vector<MkrPoint*>::iterator p_it=(*it).begin();
            p_it != it->end();
            ++p_it
        ) {
            vector<MatrixElement> matrix_part; 
            MatrixElement matrix_element;

            //Если точка является граничной, то берем разностную схему из граничного условия,
            //Если нет, то формируем разностную схему исходя из уравнения теплопроводности
            if((*p_it)->get_boundary_type()) {
                matrix_part = (*p_it)->get_boundary_cond_value(this->dt);
            } else {

                matrix_element = {
                    this->get_point_num((*p_it)->get_j(), (*p_it)->get_i()),
                    this->get_point_num((*p_it)->get_j(), (*p_it)->get_i()),
                    dx2dy2
                };
                matrix_part.push_back(matrix_element);

                matrix_element = {
                    this->get_point_num((*p_it)->get_j(), (*p_it)->get_i()),
                    this->get_point_num((*p_it)->get_j(), (*p_it)->get_i()+1),
                    -1.0*dtdy2
                };
                matrix_part.push_back(matrix_element);

                matrix_element = {
                    this->get_point_num((*p_it)->get_j(), (*p_it)->get_i()),
                    this->get_point_num((*p_it)->get_j(), (*p_it)->get_i()),
                    2.0*(dtdy2+dtdx2)
                };
                matrix_part.push_back(matrix_element);

                matrix_element = {
                    this->get_point_num((*p_it)->get_j(), (*p_it)->get_i()),
                    this->get_point_num((*p_it)->get_j(), (*p_it)->get_i()-1),
                    -1.0*dtdy2
                };
                matrix_part.push_back(matrix_element);

                matrix_element = {
                    this->get_point_num((*p_it)->get_j(), (*p_it)->get_i()),
                    this->get_point_num((*p_it)->get_j()+1, (*p_it)->get_i()),
                    -1.0*dtdx2
                };
                matrix_part.push_back(matrix_element);

                matrix_element = {
                    this->get_point_num((*p_it)->get_j(), (*p_it)->get_i()),
                    this->get_point_num((*p_it)->get_j()-1, (*p_it)->get_i()),
                    -1.0*dtdx2
                };
                matrix_part.push_back(matrix_element);

                matrix_element = {
                    -1,
                    this->get_point_num((*p_it)->get_j(), (*p_it)->get_i()),
                    (*p_it)->get_initial_cond()
                };
                matrix_part.push_back(matrix_element);
            }

            matrix->add(matrix_part);
        }
    }

    return matrix;
};

const int PlateDiscret::get_point_j(const int point_num) {
    return point_num/this->i;
};

const int PlateDiscret::get_point_i(const int point_num) {
    const int j = this->get_point_j(point_num);

    return this->i - (((j+1) * this->i)-point_num);
};

void PlateDiscret::set_initial_values(float* values) {
    for(int val=0; val<this->height*this->width; val++) {

        int i = this->get_point_i(val),
            j = this->get_point_j(val);

        this->points[j][i]->set_initial_cond(values[val]);
    }
};

void PlateDiscret::print(ostream& stream) {
    vector<vector<MkrPoint*> >::reverse_iterator it = this->points.rbegin();

    for(; it != this->points.rend(); ++it) {
        for(vector<MkrPoint*>::iterator p_it=(*it).begin();
            p_it != it->end();
            ++p_it
        ) {
            stream<<(*p_it)->get_initial_cond()<<"\t";
        }

        stream<<endl;
    }

};
