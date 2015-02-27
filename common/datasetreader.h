#ifndef DATASETREADER_H
#define DATASETREADER_H

#include <QObject>
#include <QString>
#include <string>
#include<vector>

class DataSetReader : public QObject
{
    Q_OBJECT
public:
    explicit DataSetReader(QObject *parent = 0);
    void setPath(QString );
    QImage getLeftImage(int no);
    QImage  getRightImage(int no);
    std::vector<string> getGroundTruth(int no);
private:
        QString path;
signals:
    
public slots:
    
};

#endif // DATASETREADER_H
