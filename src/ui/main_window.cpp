#include <iostream>
#include "math.h"

#include <QGridLayout>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QString>
#include <QFont>

#include "../../include/ui/MainWindow.h"

using namespace std;

void start_calculate(Properties prop);

////////////////////////////////////////////////////////////////////////////////
/**
 * private functions
 */
QColor* MainWindow::get_rgb(float value) {
    int max_value = 800,
        min_value = 0,
        b_value,
        r_value,
        g_value = 0;

    b_value = (255 - value*255/max_value);
    r_value = value*255/max_value;

    return new QColor(r_value, g_value, b_value); 
};

void MainWindow::update_draw(Matrix* matr) {
    int rect_width = 800/matr->get_width(),
        rect_height = 200/matr->get_height();

    float** matr_values = matr->get_matrix();

    QGraphicsScene* scene = new QGraphicsScene();

    for(int j=matr->get_height()-1; j>=0; j--) {
        for(int i=0; i<matr->get_width(); i++) {
            QColor* rgb = this->get_rgb(matr_values[j][i]);

            scene->addRect(
                i*rect_width, 
                (matr->get_height()-j+1)*rect_height, 
                rect_width, 
                rect_height,
                QPen(),
                QBrush(*rgb)
            );

            QGraphicsTextItem* text = scene->addText(
                QString::number(matr_values[j][i]),
                QFont(
                    QString("Arial"),
                    10
                )
            );
            text->setPos(i*rect_width, (matr->get_height()-j+1)*rect_height);
        }
    }

    draw->setScene(scene);
};

////////////////////////////////////////////////////////////////////////////////
/**
 * constructors
 */
MainWindow::MainWindow(Properties prop, QWidget* parent) 
: QWidget(parent) {
    this->prop = {
        prop.w, prop.h,
        prop.dx, prop.dy, prop.dt,
        prop.initial,
        prop.eps,
        prop.t
    };

    QGridLayout* layout = new QGridLayout();

    draw = new QGraphicsView();
    draw->setMinimumSize(800, 200);
    draw->setFrameStyle(QFrame::Box);

    calculate_button = new QPushButton("Calculate");
    connect(calculate_button, SIGNAL(clicked()), SLOT(calculate_button_clicked()));

    layout->addWidget(calculate_button, 2, 1, 1, 2, Qt::AlignJustify);
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
void MainWindow::update_values(Matrix* matr) {
    update_draw(matr);
};

bool MainWindow::event(QEvent* event) {
    if(event->type() == 1200) {
        ResultEvent* result_event = static_cast<ResultEvent* >(event);

        update_values(result_event->get_matr());

        return true;
    }

    return QWidget::event(event);
};

MainWindow* MainWindow::m_instance = 0;
