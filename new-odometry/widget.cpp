#include "widget.h"
#include "ui_widget.h"
#include "featuredetector.h"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    FeatureDetector x;
    x.readImage("/home/mahesh/test.jpg");
    x.computeFeatures();
}

Widget::~Widget()
{
    delete ui;
}
