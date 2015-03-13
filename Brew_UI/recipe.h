#ifndef RECIPE_H
#define RECIPE_H
using namespace std;
#include <QObject>
#include <QString>
class Recipe : public QObject
{
    Q_OBJECT
public:
    explicit Recipe(QObject *parent = 0);

signals:
    void getName();
public slots:
    void setName(QString recipeName);
private:
    QString recipeName;
};

#endif // RECIPE_H
