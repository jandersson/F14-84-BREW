#include "recipe.h"
#include "RecipeReader.h"
#include <QString>
#include <QFile>
#include <QDebug>
#include <QUrl>
using namespace std;
//Recipe::Recipe(QObject *parent) :
//    QObject(parent)

//{
//    m_recipeName = "";
//    importPath = "";
//}

QString Recipe::style() const{
    return m_style;
}

void Recipe::set_style(const QString &style){
    m_style = style;
    emit style_changed();
}

QQmlListProperty<MashStep> Recipe::getMashSteps(){
    return QQmlListProperty<MashStep>(this, m_mashSteps);
}

void Recipe::addMashStep(MashStep * step){
    m_mashSteps.append(step);
    emit stepsChanged();
}

void Recipe::setRecipeName(QString recipeName){
    this->m_recipeName = recipeName;
    emit recipeNameChanged();
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
    //Save to the database
    this->save();
}
