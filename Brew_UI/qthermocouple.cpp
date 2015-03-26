#include "qthermocouple.h"

Qthermocouple::Qthermocouple(QObject *parent) :
    QObject(parent)
{
}

Qthermocouple::Qthermocouple(QString name){
    this->name = name;
}

QString Qthermocouple::getName(){
    return this->thermocoupleName;
}
