#include "mashstep.h"

MashStep::MashStep(QObject *parent) :
    QObject(parent)
{
}
void MashStep::setStepName(QString name){
    this->name = name;
    emit stepNameChanged();
}

QString MashStep::getStepName(){
    return this->name;
}

void MashStep::setStepType(QString type){
    this->type = type;
    emit stepTypeChanged();
}

QString MashStep::getStepType(){
    return this->type;
}

void MashStep::setStepTemp(double temperature){
    this->temperature = temperature;
    emit stepTempChanged();
}

double MashStep::getStepTemp(){
    return this->temperature;
}

void MashStep::setStepTime(double time){
    this->time = time;
    emit stepTimeChanged();
}

double MashStep::getStepTime(){
    return this->time;
}
