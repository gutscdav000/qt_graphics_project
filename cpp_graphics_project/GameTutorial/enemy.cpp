#include "Enemy.h"
#include "Game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>

extern Game *game;

Enemy::Enemy()
{
    //set random position
    int random_number = rand() % 700;
    setPos(random_number, 0);

    //drew the rect
    setRect(0, 0, 100, 100);

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
    if(pos().y() + rect().height() > 600) {
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
        qDebug() << "enemy removed";
    }
}
