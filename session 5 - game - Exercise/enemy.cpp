#include "enemy.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QFont>
#include <stdlib.h> // rand() -> to generate really large integer
#include <QTimer>
#include <QDebug>
#include "player.h"
#include<QGraphicsView>

Enemy::Enemy() {
        // *******  Setting the size of the enemy ********
    setPixmap(QPixmap("C:/Users/anass/OneDrive/Desktop/QT Assigment 2/Chicken-Invaders/Images/chicken.png").scaled(100,100));

        // *******  Setting the postion of the enemy within the view dimensions ********
    int random_number = rand() % 700;
    setPos(random_number,0);

        // *******  Moving the enemies downwards automatically every 50 milli second ********
QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);

}
// Function move: move the enemy downwards untill the end of the scene then remove it and delete it
void Enemy:: move()
{
    QList<QGraphicsItem *>colliding_items =collidingItems();
    for(int i=0,n=colliding_items.size();i<n;++i)
    {
        if(typeid(*(colliding_items[i]))== typeid(Player))
        {

            scene()->removeItem(this);




            delete this;

            return;
        }
    }
    setPos(x(),y()+5);
        if(y()+pixmap().height()>800)
    {
        scene()->removeItem(this);
            delete this;
    }
}

