
#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QBrush>
//#include <QMediaPlayer>
#include <QImage>
#include "Enemy.h"
#include "Score.h"

Game :: Game(QWidget *parent) {


    //instantiate scene
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0, 800, 600);
    setBackgroundBrush(QBrush(QImage(":/sprites/spooky-background.jpg.jp2")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);

    //create item to put into scene
    player = new Player();

    scene->addItem(player);
    //make rect focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    player->setPos(width()/2 , height() - 100);

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

Game :: ~Game() {

    delete scene;
    delete score;
    delete player;
    delete health;
}
