#ifndef RECIPEMANAGER_H
#define RECIPEMANAGER_H

#include <QObject>
#include <QList>
#include "recipe.h"
#include <QQmlListProperty>
class RecipeManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Recipe> recipeList READ getRecipeList NOTIFY recipeListChanged)
public:
    explicit RecipeManager(QObject *parent = 0);
    QQmlListProperty<Recipe> getRecipeList();

signals:
    void recipeListChanged();
public slots:
    void addRecipe(Recipe * recipe);
private:
    QList<Recipe*> m_recipeList;
};

#endif // RECIPEMANAGER_H
