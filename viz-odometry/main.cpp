#include <QApplication>
#include "vizwindow.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    VizWindow w;
    w.show();
    
    return a.exec();
}
