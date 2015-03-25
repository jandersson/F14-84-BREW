#ifndef QTHERMOCOUPLE_H
#define QTHERMOCOUPLE_H

#include <QObject>

class Qthermocouple : public QObject, public Temp_Probe
{
    Q_OBJECT
public:
    explicit Qthermocouple(QObject *parent = 0);

signals:

public slots:

};

#endif // QTHERMOCOUPLE_H
