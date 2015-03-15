#include "RecipeReader.h"
#include <QIODevice>
#include <QDebug>


void RecipeReader::read(QIODevice * device){
    //read accepts a QIODevice and sets it using setDevice()
    xml.setDevice(device);
    while (!xml.atEnd()){
        xml.readNextStartElement();
        qDebug() << "Read a line\n";
    }
}
