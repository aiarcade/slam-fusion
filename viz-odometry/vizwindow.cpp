

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
        OdometryEngine odEngine;
        odEngine.start();
        QImage * left=odEngine.getLeftImage();
        qDebug() << left->width();
        qDebug() << left->height();
        QImageWriter writer("/home/mahesh/test.jpg");
        if(!writer.write(*left))
        {
            qDebug() << writer.errorString();
        }
        for (int i = 0; i < 1; ++i) {
            for (int j = 0; j < 1; ++j) {
                QColor clearColor;
                clearColor.setHsv(((i * NumColumns) + j) * 255
                                  / (NumRows * NumColumns - 1),
                                  255, 63);

                glWidgets[i][j] = new GLWidget(0, 0);
                glWidgets[i][j]->setClearColor(clearColor);
                glWidgets[i][j]->rotateBy(+42 * 16, +42 * 16, -21 * 16);
                ui->mainLayout->addWidget(glWidgets[i][j], i, j);

                connect(glWidgets[i][j], SIGNAL(clicked()),
                        this, SLOT(setCurrentGlWidget()));
            }
        }

        currentGlWidget = glWidgets[0][0];

        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(rotateOneStep()));
        timer->start(20);

        setWindowTitle(tr("Textures"));

}

VizWindow::~VizWindow()
{
    delete ui;
}

void VizWindow::setCurrentGlWidget()
{
    currentGlWidget = qobject_cast<GLWidget *>(sender());
}

void VizWindow::rotateOneStep()
{
    if (currentGlWidget)
        currentGlWidget->rotateBy(+2 * 16, +2 * 16, -1 * 16);
}
