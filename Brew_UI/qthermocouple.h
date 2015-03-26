#ifndef QTHERMOCOUPLE_H
#define QTHERMOCOUPLE_H

#include <QObject>
#include "Temp_Probe.h"

class Qthermocouple : public QObject, public Temp_Probe
{
    Q_OBJECT
    Q_PROPERTY(double temperature READ getTemperature NOTIFY temperatureChanged)

public:
    explicit Qthermocouple(QObject *parent = 0);

signals:
    void temperatureChanged();

public slots:

};

#endif // QTHERMOCOUPLE_H
