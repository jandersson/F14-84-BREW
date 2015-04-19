#ifndef RECIPE_H
#define RECIPE_H
#include <QObject>
#include <QString>
#include <QList>
#include <QQmlListProperty>
#include "mashstep.h"
#include "QDjangoModel.h"

class Recipe : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(QString recipeName READ getRecipeName WRITE setRecipeName NOTIFY recipeNameChanged)
    Q_PROPERTY(QString importPath READ getImportPath WRITE setImportPath NOTIFY importPathChanged)
    Q_PROPERTY(int mash_steps READ mash_steps NOTIFY stepsChanged)
    Q_PROPERTY(QString style READ style WRITE set_style NOTIFY style_changed)

public:
    explicit Recipe(QObject *parent = 0);
    QString getRecipeName() const {
        return m_recipeName;
    }

    int mash_steps() const;

    QString style() const;
    void set_style(const QString &style);

signals:
    void recipeNameChanged();
    void importPathChanged();
    void stepsChanged();
    void style_changed();

public slots:
    void setRecipeName(QString recipeName);
    void setImportPath(QString path);
    QString getImportPath();
private:
    QString m_recipeName;
    QString importPath;
    QString m_style;
    void importRecipe();
    int m_mash_steps;
};

#endif // RECIPE_H
