#ifndef RESULT_H

#define RESULT_H

#include <QEvent>
#include <QString>

#include "../Utils.h"

class ResultEvent : public QEvent {
    
    private:
        Matrix* matr;


    public:
        ResultEvent(Matrix* matr) : QEvent((Type)1200) {
            this->matr = matr;
        };

        QString info() {
            return "Result for calculation.";
        };

        Matrix* get_matr() {
            return this->matr;
        };

};

#endif
