#ifndef BOUNDARY_H

#define BOUNDARY_H

/**
 * @class класс, описывающий одномерную границу
 */
class Boundary {
  
    /**
     * начало границы
     */
    const float from;
    /**
     * конец границы
     */
    const float to;

    public:
        /**
         * @constructor
         *
         * @param f {const float} начало границы
         * @param t {const float} конец границы
         */
        Boundary(const float f, const float t);

        /**
         * @return {const float} начало границы
         */
        const float get_from();
        /**
         * @return {const float} конец границы
         */
        const float get_to();
};

#endif
