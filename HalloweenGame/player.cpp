
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>

Player::Player(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    //set graphic
    setPixmap(QPixmap(":/sprites/putin_head.jpg"));

}


void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left) {
        if(pos().x() > 0)
            setPos(x() - 10, y());
    }
    else if(event->key() == Qt::Key_Right) {
        if(pos().x() + 100 < 800)
            setPos(x() + 10, y());
    }
    else if(event->key() == Qt::Key_Space) {
        // create a bullet
        Bullet *bullet = new Bullet();
        bullet->setPos(x(), y());
        scene()->addItem(bullet);
    }
}

void Player::spawn()
{
    //create an enemy
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}
