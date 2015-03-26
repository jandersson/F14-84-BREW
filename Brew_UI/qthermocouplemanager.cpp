#include "qthermocouplemanager.h"

QthermocoupleManager::QthermocoupleManager(QObject *parent) :
    QObject(parent)
{
}

void QthermocoupleManager::addThermocouple(Qthermocouple *thermocouple){
    m_thermocoupleList.append(thermocouple);
    emit thermocoupleListChanged();
}

QQmlListProperty<Qthermocouple> QthermocoupleManager::getThermocoupleList(){
    return QQmlListProperty<Qthermocouple>(this, m_thermocoupleList);
}
