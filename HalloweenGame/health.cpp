#include "Health.h"
#include <QString>
#include <QFont>
#include <QGraphicsTextItem>

Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    // init health
    health = 5;

    //draw the text
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}

void Health::decrease()
{
    --health;
    setPlainText(QString("Health: ") + QString::number(health));
}
int Health::getHealth() {return health;}
