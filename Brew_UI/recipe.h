#ifndef RECIPE_H
#define RECIPE_H
#include <QObject>
#include <QString>
#include <QList>
#include <QQmlListProperty>
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
    void importPathChanged();
    void stepsChanged();
public slots:
    void setRecipeName(QString recipeName);
    void setImportPath(QString path);
    QString getImportPath();
private:
    QString m_recipeName;
    QString importPath;
    void importRecipe();
    QList<MashStep*> m_mashSteps;

};

#endif // RECIPE_H
