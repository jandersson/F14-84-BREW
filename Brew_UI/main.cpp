#include <QApplication>
#include <QQmlApplicationEngine>
#include <QXmlStreamReader>
#include <QQmlContext>
#include <QtQml>
#include "recipe.h"
#include "RecipeReader.h"
#include "recipemanager.h"
#include "qthermocouple.h"

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
    //Instantiate a manager for recipes, essentially holds a list of recipes
    RecipeManager manager;

    QQmlContext* ctx = engine.rootContext();
    //Instantiate a Qthermocouple, a representation of a single thermocouple, and set a context property for it
    Qthermocouple thermocouple;
    ctx->setContextProperty("thermocouple", &thermocouple);
    ctx->setContextProperty("manager", &manager);
    ctx->setContextProperty("recipe", &recipe);
    qmlRegisterType<MashStep>("MashStep", 1, 0, "MashStep");
    qmlRegisterType<Recipe>("Recipe", 1, 0, "Recipe");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
