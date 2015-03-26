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
    m_recipeName = "";
    importPath = "";
}

void Recipe::addMashStep(MashStep * step){
    m_mashSteps.append(step);
    emit stepsChanged();
}

void Recipe::setRecipeName(QString recipeName){
    this->m_recipeName = recipeName;
    emit recipeNameChanged();
}

QString Recipe::getRecipeName(){
    return this->m_recipeName;
}

void Recipe::setImportPath(QString path){
    QUrl fileUrl(path);
    importPath = fileUrl.toLocalFile();
    emit importPathChanged();
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
