#include <QApplication>
#include <QQmlApplicationEngine>
#include <QXmlStreamReader>
#include <QQmlContext>
#include <QtQml>
#include "recipe.h"
#include "RecipeReader.h"

int main(int argc, char *argv[])
{
    // Create Qt application window
    // Manages the GUI control flow and main settings
    QApplication app(argc, argv);
    //QQmlApplication engine loads a single QML resource
    //Exposes some application functionality which a C++/QML hybrid application uses to control the application from C++
    QQmlApplicationEngine engine;

    //Instantiate a single instance of the recipe class for testing purposes
    Recipe recipe;
    //Timer timer;

    QQmlContext* ctx = engine.rootContext();
    ctx->setContextProperty("recipe", &recipe);
    qmlRegisterType<MashStep>("MashStep", 1, 0, "MashStep");
    //ctx->setContextProperty("timer", &timer);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
