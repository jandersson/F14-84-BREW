#ifndef RECIPE_H
#define RECIPE_H
#include <QObject>
#include <QString>
class Recipe : public QObject
{
    Q_OBJECT
public:
    explicit Recipe(QObject *parent = 0);

signals:

public slots:
    QString getRecipeName();
    void setName(QString recipeName);
    void setImportPath(QString path);
    QString getImportPath();
private:
    QString recipeName;
    QString importPath;
};

#endif // RECIPE_H
