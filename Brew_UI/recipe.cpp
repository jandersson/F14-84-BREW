#include "recipe.h"
#include "RecipeReader.h"
#include <QString>
#include <QFile>
#include <QDebug>
#include <QUrl>
using namespace std;
Recipe::Recipe(QObject *parent) :
    QDjangoModel(parent)
{
}

QString Recipe::style() const{
    return m_style;
}

void Recipe::set_style(const QString &style){
    m_style = style;
    emit style_changed();
}

int Recipe::mash_steps() const{
    return m_mash_steps;
}

void Recipe::setRecipeName(QString recipeName){
    this->m_recipeName = recipeName;
    emit recipeNameChanged();
    this->save();
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
