#ifndef VIZWINDOW_H
#define VIZWINDOW_H

#include <QMainWindow>
#include "glwidget.h"
#include "glplotwidget.h"
#include "odometryengine.h"
#include "matrix.h"
#include "plotwidget.h"
#include "csvreader.h"
#include <QImage>
#include <qwt_plot_canvas.h>
#include <qwt_plot_marker.h>
#include <qwt_plot_layout.h>
namespace Ui {
class VizWindow;
}

class VizWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit VizWindow(QWidget *parent = 0);
    ~VizWindow();
    void positionPlot(Matrix *);
    void setDataPath(std::string);
    
private:
    Ui::VizWindow *ui;
    enum { NumRows = 2, NumColumns = 3 };

        GLWidget *camglWidget;
        GLPlotWidget *plotglWidget;
        OdometryEngine *odEngine;
        QImage *leftImage;
        Matrix *pos;
        QwtPlot  *plot;
        double count;
        std::vector<double> plot_x;
        std::vector<double> plot_y;
        std::vector<double> gt_x;
        std::vector<double> gt_y;
        CSVReader gtReader;
        std::string data_set_path;
private slots:
    void setCurrentGlWidget();
    void rotateOneStep();

};

#endif // VIZWINDOW_H
