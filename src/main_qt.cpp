#include <QtGui>

int main(int argc, char** argv) {

    QApplication app(argc, argv);

    QWidget wgt;

    QPushButton* button = new QPushButton("Click me");

    //Layout setup
    QHBoxLayout* lay = new QHBoxLayout();
    lay->addWidget(button);

    wgt.setLayout(lay);

    wgt.show();

    return app.exec();
};
