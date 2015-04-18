#include <QApplication>
#include <QQmlApplicationEngine>
#include <QXmlStreamReader>
#include <QQmlContext>
#include <QtQml>
#include <QSqlDatabase>
#include <QDjango.h>
#include "recipe.h"
#include "RecipeReader.h"
#include "recipemanager.h"
#include "qthermocouple.h"
#include "qthermocouplemanager.h"
int main(int argc, char *argv[])
{
    QString db_name = "BrewDB.sql";
    // Create Qt application window
    // Manages the GUI control flow and main settings
    QApplication app(argc, argv);
    //QQmlApplication engine loads a single QML resource
    //Exposes some application functionality which a C++/QML hybrid application uses to control the application from C++
    QQmlApplicationEngine engine;

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(db_name);
    db.open();
    QDjango::setDatabase(db);
    QDjango::createTables();
    //Instantiate a single instance of the recipe class for testing purposes
    Recipe recipe;
    //Instantiate a manager for recipes, essentially holds a list of recipes
    RecipeManager manager;
    QthermocoupleManager thermoManager;
    QQmlContext* ctx = engine.rootContext();
    //Instantiate a Qthermocouple, a representation of a single thermocouple, and set a context property for it
    Qthermocouple thermocoupleHLT("Hot Liqour Tank");
    Qthermocouple thermocoupleMT("Mash Tun");
    Qthermocouple thermocoupleBK("Boil Kettle");
    thermoManager.addThermocouple(&thermocoupleHLT);
    thermoManager.addThermocouple(&thermocoupleMT);
    thermoManager.addThermocouple(&thermocoupleBK);
    ctx->setContextProperty("thermocouple", &thermocoupleHLT);
    ctx->setContextProperty("manager", &manager);
    ctx->setContextProperty("recipe", &recipe);
    ctx->setContextProperty("thermoManager", &thermoManager);
    qmlRegisterType<MashStep>("MashStep", 1, 0, "MashStep");
    qmlRegisterType<Recipe>("Recipe", 1, 0, "Recipe");
    qmlRegisterType<Qthermocouple>("thermocouple", 1, 0, "thermocouple");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
