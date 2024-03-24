
#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include<QGraphicsView>
#include "player.h"
#include <QTimer>
#include <QDebug>
#include <QBrush>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // ******* Create the Scene ********
    QGraphicsScene scene;
    scene.setSceneRect(0,0,800,600);

    // *******  Create the View ********
    QGraphicsView view;
    view.setFixedSize(800,600);
    view.setBackgroundBrush(Qt::white);

    // Score and health and game over
    QGraphicsTextItem *score = new QGraphicsTextItem;
    score->setFont(QFont("times", 16));
    score->setDefaultTextColor(Qt::black);
    score->setPlainText("score : "+ QString::number(0));
    score->setPos(700,10);
    scene.addItem(score);
    QGraphicsTextItem *heart = new QGraphicsTextItem;
    heart->setFont(QFont("times", 16));
    heart->setDefaultTextColor(Qt::black);
    heart->setPlainText("HP : "+ QString::number(3));
    heart->setPos(700,30);
    scene.addItem(heart);

    // *******  Create the Player ********

    QPixmap playericon("B:/this pc/cs lab/Chicken_invaders/Chicken-Invaders/Images/Spaceship.png");
    playericon = playericon.scaledToWidth(100);
    playericon = playericon.scaledToHeight(100);
    Player * p = new Player(score, heart);
    p->setPixmap(playericon);

    // *******  Setting the foucs to the Player ********
     p->setFlag(QGraphicsItem::ItemIsFocusable);
     p->setFocus();
    // ********** add score and hearts **************

    // *******  Adjust the location of the Player (middle of the screen) ********
     p->setPos(view.width()/2,view.height()- playericon.height());
      scene.addItem(p);
   // *******   Assign scene to the view   ***************

     view.setScene(&scene);
     view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
     view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
     view.show();

    // *******  Create the Enemies automatically ********

QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),p,SLOT(createEnemy()));
    time->start(2000);

    return a.exec();
}
