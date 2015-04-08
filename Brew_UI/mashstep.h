#ifndef MASHSTEP_H
#define MASHSTEP_H

#include <QObject>
#include <QString>
#include "QDjangoModel.h"

class MashStep : public QDjangoModel
{
    Q_OBJECT

    Q_PROPERTY(QString name READ getStepName WRITE setStepName NOTIFY stepNameChanged)
    Q_PROPERTY(QString type READ getStepType WRITE setStepType NOTIFY stepTypeChanged)
    Q_PROPERTY(double temperature READ getStepTemp WRITE setStepTemp NOTIFY stepTempChanged)
    Q_PROPERTY(double time READ getStepTime WRITE setStepTime NOTIFY stepTimeChanged)

    QString name;
    QString type;
    double temperature;
    double time;

public:

//    explicit MashStep(QObject *parent = 0);

signals:

    void stepNameChanged();
    void stepTypeChanged();
    void stepTempChanged();
    void stepTimeChanged();

public slots:

    void setStepName(QString name);
    QString getStepName();
    void setStepType(QString type);
    QString getStepType();
    void setStepTemp(double temperature);
    double getStepTemp();
    void setStepTime(double time);
    double getStepTime();

};

#endif // MASHSTEP_H
