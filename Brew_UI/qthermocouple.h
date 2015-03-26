#ifndef QTHERMOCOUPLE_H
#define QTHERMOCOUPLE_H

#include <QObject>
#include "Temp_Probe.h"

class Qthermocouple : public QObject, public Temp_Probe
{
    Q_OBJECT
public:
    explicit Qthermocouple(QObject *parent = 0);

signals:
    void temperatureChanged();

public slots:

};

#endif // QTHERMOCOUPLE_H
