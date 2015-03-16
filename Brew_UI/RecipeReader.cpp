#include "RecipeReader.h"
#include <QIODevice>
#include <QDebug>
#include "mashstep.h"

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
    MASH,
    MASHSTEP,
    MASHSTEPS,
    SKIP,
    MASHTYPE
};

string_code hashit (QStringRef inString){
    if (inString == "NAME") return NAME;
    if (inString == "MASH") return MASH;
    if (inString == "MASH_STEP") return MASHSTEP;
    if (inString == "MASH_STEPS") return MASHSTEPS;
    if (inString == "TYPE") return MASHTYPE;
    else return SKIP;
}

void RecipeReader::readRecipe(){
    //The XML document has multiple NAME elements, the following flags are for determining what NAME is referring to
    bool nameIsRecipe = false;
    bool nameIsMashStep = false;
    MashStep step;
    while(!xml.atEnd() && !xml.hasError()){
        QXmlStreamReader::TokenType token = xml.readNext();

        if(token == QXmlStreamReader::StartDocument)
            continue;
        if(token == QXmlStreamReader::StartElement){
            if(xml.name() == "RECIPE"){
                nameIsRecipe = true;
                continue;
            }
            if(xml.name() == "MASH_STEP"){
                nameIsMashStep = true;
                continue;
            }
            if(xml.name() == "NAME"){
                if(nameIsRecipe){
                    recipe->setRecipeName(xml.readElementText());
                    nameIsRecipe = false;
                    continue;
                }
                if(nameIsMashStep){
                    step.setStepName(xml.readElementText());
                    qDebug() << step.getStepName();
                    continue;
                }
            }
            if(xml.name() == "STEP_TIME"){
                step.setStepTime((xml.readElementText().toDouble()));
                qDebug() << step.getStepTime();
                continue;
            }
            if(xml.name() == "STEP_TEMP"){
                step.setStepTemp(xml.readElementText().toDouble());
                qDebug() << step.getStepTemp();
                continue;
            }
        }
        if(token == QXmlStreamReader::EndElement){
            if(xml.name() == "MASH_STEP"){
                recipe->addMashStep(&step);
                qDebug() << "Step added to list";
                continue;
            }
        }
    }

//    while (xml.readNextStartElement()){
//        if (xml.name() == "RECIPE"){
//            while (xml.readNextStartElement()){
//                switch (hashit(xml.name())){
//                case NAME:
//                    recipe->setRecipeName(xml.readElementText());
//                    break;
//                case MASH:
//                    while (xml.readNextStartElement()){
//                        qDebug() << "Mash loop: " << xml.name();
//                        switch(hashit(xml.name())){
//                        case MASHSTEPS:
//                            while (xml.readNextStartElement()){
//                                qDebug() << "Mash Steps loop: " << xml.name();
//                                switch(hashit(xml.name())){
//                                case NAME:
//                                    qDebug() << xml.readElementText();
//                                    break;
//                                default:
//                                    //xml.skipCurrentElement();
//                                    break;
//                                }
//                            }
//                            break;
//                        default:
//                            qDebug() << "Skipping element";
//                            xml.skipCurrentElement();
//                            break;
//                        }
//                    }
//                    break;
//                default:
//                    xml.skipCurrentElement();
//                    break;
//                }
//            }
//        }
//    }
}
