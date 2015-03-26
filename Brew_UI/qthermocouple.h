#ifndef QTHERMOCOUPLE_H
#define QTHERMOCOUPLE_H

#include <QObject>
#include <QString>
#include "Temp_Probe.h"

class Qthermocouple : public QObject, public Temp_Probe
{
    Q_OBJECT
    Q_PROPERTY(double temperature READ getTemperature NOTIFY temperatureChanged)
    Q_PROPERTY(QString name READ getName NOTIFY nameChanged)

public:
    explicit Qthermocouple(QObject *parent = 0);
    Qthermocouple(QString name);

signals:
    void temperatureChanged();
    void nameChanged();

public slots:

    QString getName();

private:

    QString thermocoupleName;

};

#endif // QTHERMOCOUPLE_H
