#ifndef QTHERMOCOUPLEMANAGER_H
#define QTHERMOCOUPLEMANAGER_H

#include <QObject>
#include <QList>
#include <QQmlListProperty>
#include "qthermocouple.h"
class QthermocoupleManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Qthermocouple> thermocoupleList READ getThermocoupleList NOTIFY thermocoupleListChanged)
public:
    explicit QthermocoupleManager(QObject *parent = 0);


    QQmlListProperty<Qthermocouple> getThermocoupleList();

signals:
    void thermocoupleListChanged();
public slots:
    void addThermocouple(Qthermocouple * thermocouple);
private:
    QList<Qthermocouple*> m_thermocoupleList;

};

#endif // QTHERMOCOUPLEMANAGER_H
