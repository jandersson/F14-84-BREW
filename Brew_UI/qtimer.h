#ifndef QTIMER_H
#define QTIMER_H

#include <QObject>
#include "Timer.h"
class Qtimer : public QObject, public Timer
{
    Q_OBJECT
public:
    explicit Qtimer(QObject *parent = 0);

signals:

public slots:

};

#endif // QTIMER_H
