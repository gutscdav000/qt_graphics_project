
#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include "Score.h"

Game :: Game(QWidget *parent) {


    //instantiate scene
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0, 800, 600);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);


    //create item to put into scene
    player = new Player();
    player->setRect(0, 0, 100, 100);
    scene->addItem(player);
    //make rect focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    player->setPos(width()/2 - (player->rect().width()/2), height() - player->rect().height());

    // create the score
    score = new Score();
    scene->addItem(score);

    // create the health
    health = new Health();
    health->setPos(health->x(), health->y() + 25);
    scene->addItem(health);


    // spawn enemies
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    show();
}
