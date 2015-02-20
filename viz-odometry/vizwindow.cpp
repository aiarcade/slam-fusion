

#include "glwidget.h"
#include <QGridLayout>
#include <QTimer>
#include <QDebug>

#include "vizwindow.h"
#include "ui_vizwindow.h"

VizWindow::VizWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VizWindow)
{


        ui->setupUi(this);
        plot=new QwtPlot ();
        plot->enableAxis(QwtPlot::xBottom, true);
        plot->enableAxis(QwtPlot::yLeft, true);
        plot->setAxisScale( QwtPlot::xBottom, -200.0, 200.0 );
        plot->setAxisScale( QwtPlot::yLeft, -200.0, 200.0 );
        plot->setTitle("MAP");
        plot->setStyleSheet("background-color:white;");
        plot->setFixedSize(900,280);
        QwtPlotLayout *layout=plot->plotLayout();
        layout->setAlignCanvasToScales(true);

        data_set_path="/home/mahesh/dev/vslam/libviso2/2010_03_09_drive_0019";
        std::string gt_file=data_set_path+"/insdata.txt";
        std::string delimters=" ";
        gtReader.readFile(gt_file,delimters,0);
        odEngine=new OdometryEngine();
        odEngine->setDataPath(data_set_path);
        odEngine->start();
        camglWidget= new GLWidget(0, 0);
        plotglWidget= new GLPlotWidget(0, 0);
       // plot=new PlotWidget();
        QImage * left=odEngine->getLeftImage();
        camglWidget->updateTexture(left);
        //plotglWidget->updatePlot(left);

        ui->camLayout->addWidget(camglWidget);
        ui->plotLayout->addWidget(plot);
        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(rotateOneStep()));
        timer->start(10);

        setWindowTitle(tr("VSLAM"));



}

VizWindow::~VizWindow()
{
    delete ui;
}

void VizWindow::setCurrentGlWidget()
{

}

void VizWindow::rotateOneStep()
{
    leftImage=odEngine->getLeftImage();
    pos=odEngine->getPosition();
    camglWidget->updateTexture(leftImage);
    plotglWidget->updatePlot(pos);
   plotglWidget->updateGL();
   camglWidget->updateGL();
   positionPlot(pos);


}

void VizWindow::positionPlot(Matrix *pos)
{

     plot_x.push_back(pos->val[0][3]);
     plot_y.push_back(pos->val[2][3]);
   // qDebug()<<pos->val[0][3]<<pos->val[2][3];
    QwtPlotGrid *grid = new QwtPlotGrid();
    grid->setPen(QPen(Qt::gray, 0.0, Qt::DotLine));
    grid->enableX(true);
    grid->enableXMin(true);
    grid->enableY(true);
    grid->enableYMin(false);
    grid->attach(  plot );

    QwtPlotCurve *curve = new QwtPlotCurve();
    curve->setPen(QPen(QColor( Qt::red ),4) );
    curve->setSamples( plot_x.data(), plot_y.data(), (int) plot_x.size());
    curve->attach(plot);
    curve->show();

    count=count+1;
    std::vector <std::string> gt=gtReader.next();
    if(gt.empty()) qDebug()<<"Empty data";
    double x = (QString::fromStdString(gt[4])).toDouble()+5200;
    double y = (QString::fromStdString(gt[5])).toDouble()+1000;
    double z = (QString::fromStdString(gt[6])).toDouble();
    qDebug()<<x<<y<<z;
    gt_x.push_back(x);
    gt_y.push_back(y);

    QwtPlotCurve *gt_curve = new QwtPlotCurve();
    gt_curve->setPen(QPen(QColor( Qt::green),4) );
    gt_curve->setSamples( gt_x.data(), gt_y.data(), (int) gt_x.size());
    gt_curve->attach(plot);
    gt_curve->show();


    plot->replot();

}

void VizWindow::setDataPath(std::string path)
{
    data_set_path=path;
}


