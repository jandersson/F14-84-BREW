#ifndef QTHERMOCOUPLEMANAGER_H
#define QTHERMOCOUPLEMANAGER_H

#include <QObject>
#include <QQmlListProperty>

class QthermocoupleManager : public QObject
{
    Q_OBJECT
public:
    explicit QthermocoupleManager(QObject *parent = 0);

    Q_PROPERTY(QQmlListProperty<QthermocoupleManager> thermocoupleList READ getThermocoupleList NOTIFY thermocoupleListChanged)
    QQmlListProperty<Qthermocouple> getThermocoupleList();

signals:
    void thermocoupleListChanged();
public slots:
    void addThermocouple(Qthermocouple * thermocouple);
private:
    QList<Qthermocouple*> m_thermocoupleList;

};

#endif // QTHERMOCOUPLEMANAGER_H
