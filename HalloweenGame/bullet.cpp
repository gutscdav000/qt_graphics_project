
#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>

extern Game *game; // there is an external global object called game

Bullet::Bullet(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    //draw graphic
    setPixmap(QPixmap(":/sprites/Missile.png"));
    //setTransformOriginPoint(); //rotation point
    //setRotation(); // degrees

    //connect
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);

}

void Bullet::move()
{
 // if collision, destroy bullet and enemy
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0; i < colliding_items.size(); i++) {
        if(typeid(*(colliding_items[i])) == typeid(Enemy)) {
            //increase score
            game->score->increase();
            //remove
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // deallocate memory
            delete colliding_items[i];
            delete this;
            return;
        }
    }

 // move bullet up
    setPos(x(), y() - 10);

    // destroy object
    // previous cond: if(pos().y() + rect().height() < 0)
    if(pos().y() < 0) {
        scene()->removeItem(this);
        delete this;
        qDebug() << "bullet removed";
    }
}
