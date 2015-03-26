#include "recipe.h"
#include "RecipeReader.h"
#include <QString>
#include <QFile>
#include <QDebug>
#include <QUrl>
using namespace std;
Recipe::Recipe(QObject *parent) :
    QObject(parent)
{
    recipeName = "";
    importPath = "";
}

void Recipe::addMashStep(MashStep * step){
    m_mashSteps.append(step);
    emit stepsChanged();
}

void Recipe::setRecipeName(QString recipeName){
    this->recipeName = recipeName;
    recipeNameChanged();
}

QString Recipe::getRecipeName(){
    if (this->recipeName != "")
        return this->recipeName;
    else
        return "No name!";
}

void Recipe::setImportPath(QString path){
    QUrl fileUrl(path);
    importPath = fileUrl.toLocalFile();
    this->importRecipe();
}

QString Recipe::getImportPath(){
    return this->importPath;
}

void Recipe::importRecipe(){
    QFile file(importPath);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    //Instantiate the recipe XML parser
    RecipeReader recipeReader(this);
    recipeReader.read(&file);
    file.close();
}
