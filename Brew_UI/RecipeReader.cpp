#include "RecipeReader.h"
#include <QIODevice>
#include <QDebug>


void RecipeReader::read(QIODevice * device){
    //read accepts a QIODevice and sets it using setDevice()
    xml.setDevice(device);

    if (xml.readNextStartElement()){
        if (xml.name() == "RECIPES"){
            readRecipe();
        }
        else
            xml.raiseError("File is not a BeerSmith recipe");
    }

}

void RecipeReader::readRecipe(){
    while (xml.readNextStartElement()){
        if (xml.name() == "RECIPE"){
            while (xml.readNextStartElement()){
                if (xml.name() == "NAME"){
                    qDebug() << "Found the recipe name: " << xml.readElementText();

                }
                else
                    xml.skipCurrentElement();
            }
        }
    }
}
