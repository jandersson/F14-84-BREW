#ifndef RECIPEREADER_H
#define RECIPEREADER_H
#include <QXmlStreamReader>
#include <QIODevice>

class RecipeReader{
public:
    void read(QIODevice * device);
private:
    QXmlStreamReader xml;
    void readRecipe();
};

#endif // RECIPEREADER_H
