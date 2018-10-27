#include "Enemy.h"
#include "Game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>

extern Game *game;

Enemy::Enemy(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    //set random position
    int random_number = rand() % 700;
    setPos(random_number, 0);

    //draw the rect
    setPixmap(QPixmap(":/sprites/jackolantern.png"));

    //connect
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);

}

void Enemy::move()
{
 // move bullet up
    setPos(x(), y() + 5);

    // destroy object
    if(pos().y() > 600) {
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
        qDebug() << "enemy removed";
    }
}
