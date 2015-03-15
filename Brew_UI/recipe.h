#ifndef RECIPE_H
#define RECIPE_H
#include <QObject>
#include <QString>
#include <QList>
class Recipe : public QObject
{
    Q_OBJECT
public:
    explicit Recipe(QObject *parent = 0);
signals:
    void recipeNameChanged();
public slots:
    QString getRecipeName();
    void setRecipeName(QString recipeName);
    void setImportPath(QString path);
    QString getImportPath();
private:
    QString recipeName;
    QString importPath;
    void importRecipe();
    QList mashSteps;
    struct mashStep{
        mashStep(QString _name, QString _type, double _temperature, double _time);
        QString name;
        QString type;
        double temperature;
        double time;
    };
};

#endif // RECIPE_H
