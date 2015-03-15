#include "RecipeReader.h"
#include <QIODevice>
#include <QDebug>

RecipeReader::RecipeReader(Recipe * recipe){
    this->recipe = recipe;
}

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

enum string_code{
    //Borrowed from stack overflow user D. Shawley
    //http://stackoverflow.com/questions/650162/why-switch-statement-cannot-be-applied-on-strings
    NAME,
    MASHSTEP,
    SKIP
};

string_code hashit (QStringRef inString){
    if (inString == "NAME") return NAME;
    if (inString == "MASH STEP") return MASHSTEP;
    else return SKIP;
}

void RecipeReader::readRecipe(){
    while (xml.readNextStartElement()){
        if (xml.name() == "RECIPE"){
            while (xml.readNextStartElement()){
                switch (hashit(xml.name())){
                case NAME:
                    recipe->setRecipeName(xml.readElementText());
                    break;
                case MASHSTEP:
                    qDebug() << "Found a mash step";
                    break;
                default:
                    xml.skipCurrentElement();
                    break;
                }
//                if (xml.name() == "NAME"){
//                    recipe->setRecipeName(xml.readElementText());
//                }
//                else
//                    xml.skipCurrentElement();
            }
        }
    }
}
