#include "qthermocouple.h"

Qthermocouple::Qthermocouple(QObject *parent) :
    QObject(parent)
{
}

Qthermocouple::Qthermocouple(QString name){
    thermocoupleName = name;
}

QString Qthermocouple::getName(){
    return this->thermocoupleName;
}
