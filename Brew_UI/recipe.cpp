#include "recipe.h"
#include <QString>
using namespace std;
Recipe::Recipe(QObject *parent) :
    QObject(parent)
{
    recipeName = "";
    importPath = "";
}

void Recipe::setName(QString recipeName){
    this->recipeName = recipeName;
}

QString Recipe::getRecipeName(){
    if (this->recipeName != "")
        return this->recipeName;
    else
        return "No name!";
}

void Recipe::setImportPath(QString path){
    this->importPath = path;
}

QString Recipe::getImportPath(){
    return this->importPath;
}
