#ifndef MASHSTEP_H
#define MASHSTEP_H

#include <QObject>
#include <QString>

class MashStep : public QObject
{
    Q_OBJECT  
    QString name;
    QString type;
    double temperature;
    double time;

public:

    explicit MashStep(QObject *parent = 0);
    // MashStep(QString _name, QString _type, double _temperature, double _time);

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
