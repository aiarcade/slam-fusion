#ifndef VIZWINDOW_H
#define VIZWINDOW_H

#include <QMainWindow>
#include "glwidget.h"
#include "odometryengine.h"
namespace Ui {
class VizWindow;
}

class VizWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit VizWindow(QWidget *parent = 0);
    ~VizWindow();
    
private:
    Ui::VizWindow *ui;
    enum { NumRows = 2, NumColumns = 3 };

        GLWidget *glWidgets[NumRows][NumColumns];
        GLWidget *currentGlWidget;
   OdometryEngine odEngine;
private slots:
    void setCurrentGlWidget();
    void rotateOneStep();

};

#endif // VIZWINDOW_H
