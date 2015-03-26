#include "recipemanager.h"

RecipeManager::RecipeManager(QObject *parent) :
    QObject(parent)
{
}

void RecipeManager::addRecipe(Recipe * recipe){
    m_recipeList.append(recipe);
    emit recipeListChanged();
}

QQmlListProperty<Recipe> RecipeManager::getRecipeList(){
    return QQmlListProperty<Recipe>(this, m_recipeList);
}
