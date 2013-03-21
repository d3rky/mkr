#include <iostream>

#include <QGridLayout>

#include "../../include/ui/MainWindow.h"

using namespace std;

void start_calculate(Properties prop);

////////////////////////////////////////////////////////////////////////////////
/**
 * constructors
 */
MainWindow::MainWindow(Properties prop, QWidget* parent) : QWidget(parent) {
    this->prop = {
        prop.w, prop.h,
        prop.dx, prop.dy, prop.dt,
        prop.initial,
        prop.eps,
        prop.t
    };

    QGridLayout* layout = new QGridLayout();

    number = new QLabel();
    draw = new QLabel();

    number->setMinimumSize(100, 100);
    number->setFrameStyle(QFrame::Box);
    draw->setMinimumSize(100, 100);
    draw->setFrameStyle(QFrame::Box);

    painter = new QPainter(draw);

    calculate_button = new QPushButton("Calculate");
    connect(calculate_button, SIGNAL(clicked()), SLOT(calculate_button_clicked()));

    layout->addWidget(calculate_button, 2, 1, 1, 2, Qt::AlignJustify);
    layout->addWidget(number, 1, 1, Qt::AlignJustify);
    layout->addWidget(draw, 1, 2, Qt::AlignJustify);

    setLayout(layout);
    setWindowTitle("Mkr");
};

////////////////////////////////////////////////////////////////////////////////
/**
 * public slots
 */
void MainWindow::calculate_button_clicked() {
    start_calculate(this->prop);
};

////////////////////////////////////////////////////////////////////////////////
/**
 * public functions
 */
void update_values(Matrix* matr) {
    ;
};


