
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

    // *******  Create the Player ********

    QPixmap playericon("C:/Users/anass/OneDrive/Desktop/QT Assigment 2/Chicken-Invaders/Images/Spaceship.png");
    playericon = playericon.scaledToWidth(100);
    playericon = playericon.scaledToHeight(100);
    Player * p = new Player();
    p->setPixmap(playericon);

    // *******  Setting the foucs to the Player ********
     p->setFlag(QGraphicsItem::ItemIsFocusable);
     p->setFocus();
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

    view.setScene(&scene);

    return a.exec();
}
