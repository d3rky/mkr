#ifndef MAIN_WINDOW_H

#define MAIN_WINDOW_H

#include <vector>

#include <QWidget>
#include <QPushButton>
#include <QGraphicsView>
#include <QEvent>
#include <QRgb>

#include "../Utils.h"

#include "ResultEvent.h"

class MainWindow : public QWidget {

    Q_OBJECT

    private:
        QPushButton* calculate_button;

        QGraphicsView* draw;

        Properties prop;

        static MainWindow* m_instance;

        MainWindow(Properties prop, QWidget* parent=0);

        void update_draw(Matrix* matr);

        QColor* get_rgb(float value);

    public:
        void update_values(Matrix* matr);

        bool event(QEvent* event);

        static MainWindow* instance(Properties prop, QWidget* parent=0) {
            
            if(!m_instance) {
                m_instance = new MainWindow(prop, parent);
            }

            return m_instance;
        };

        static MainWindow* instance() {
            if(!m_instance) {
                return 0;
            }

            return m_instance;
        };

    public slots:
        void calculate_button_clicked();

};

#endif