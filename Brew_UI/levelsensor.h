#ifndef LEVELSENSOR_H
#define LEVELSENSOR_H

#include <QObject>

class LevelSensor : public QObject
{
    Q_OBJECT
public:
    explicit LevelSensor(QObject *parent = 0);

signals:

public slots:

};

#endif // LEVELSENSOR_H
