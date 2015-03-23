#ifndef RECIPE_H
#define RECIPE_H
#include <QObject>
#include <QString>
#include <QList>
#include "mashstep.h"
class Recipe : public QObject
{
    Q_OBJECT
public:
    explicit Recipe(QObject *parent = 0);
    void addMashStep(MashStep * step);
signals:
    void recipeNameChanged();
public slots:
    QString getRecipeName();
    void setRecipeName(QString recipeName);
    void setImportPath(QString path);
    QString getImportPath();
private:
    QString recipeName;
    QString importPath;
    void importRecipe();
    QList<MashStep*> mashSteps;

};

#endif // RECIPE_H
