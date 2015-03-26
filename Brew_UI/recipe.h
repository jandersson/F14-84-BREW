#ifndef RECIPE_H
#define RECIPE_H
#include <QObject>
#include <QString>
#include <QList>
#include "mashstep.h"
class Recipe : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString recipeName READ getRecipeName WRITE setRecipeName NOTIFY recipeNameChanged)
    Q_PROPERTY(QString importPath READ getImportPath WRITE setImportPath NOTIFY importPathChanged)
    Q_PROPERTY(QQmlListProperty<MashStep> mashSteps READ getMashSteps NOTIFY stepsChanged)

public:
    explicit Recipe(QObject *parent = 0);

    QString getRecipeName() const {
        return m_recipeName;
    }

    QQmlListProperty<MashStep> getMashSteps();
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
