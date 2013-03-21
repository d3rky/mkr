#ifndef MAIN_WINDOW_H

#define MAIN_WINDOW_H

#include <vector>

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QLabel>

#include "../Utils.h"

class MainWindow : public QWidget {

    Q_OBJECT

    private:
        QPushButton* calculate_button;
        QPainter* painter;

        QLabel* number;
        QLabel* draw;

        Properties prop;

    public:
        MainWindow(Properties prop, QWidget* parent=0);

        void update_values(Matrix* matr);

    public slots:
        void calculate_button_clicked();

};

#endif