#include <QApplication>
#include <QQmlApplicationEngine>
#include <QXmlStreamReader>
#include <QQmlContext>
#include "recipe.h"
int main(int argc, char *argv[])
{
    // Create Qt application window
    // Manages the GUI control flow and main settings
    QApplication app(argc, argv);
    //QQmlApplication engine loads a single QML resource
    //Exposes some application functionality which a C++/QML hybrid application uses to control the application from C++
    QQmlApplicationEngine engine;

    QStringList dataList;
    dataList.append("Recipe 1");
    Recipe recipe;
    QQmlContext* ctx = engine.rootContext();
    ctx->setContextProperty("recipe", &recipe);



    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    return app.exec();
}
