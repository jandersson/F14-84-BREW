#ifndef RECIPEREADER_H
#define RECIPEREADER_H
#include <QXmlStreamReader>
#include <QIODevice>
#include "recipe.h"

class RecipeReader{
public:
    RecipeReader(Recipe * recipe);
    void read(QIODevice * device);
private:
    QXmlStreamReader xml;
    void readRecipe();
    Recipe * recipe;
    MashStep * step;
};

#endif // RECIPEREADER_H
