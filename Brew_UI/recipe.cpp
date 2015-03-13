#include "recipe.h"
#include <string>
#include <QDebug>
#include <iostream>
#include <QString>
using namespace std;
Recipe::Recipe(QObject *parent) :
    QObject(parent)
{
}

void Recipe::setName(QString recipeName){
    this->recipeName = recipeName;
}
