#include"bullet.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <QGraphicsPixmapItem>
#include <enemy.h>
#include <player.h>

Bullet::Bullet(Player *p):QObject(), QGraphicsPixmapItem() {

        // *******  Setting the bullets' size ********
    setPixmap(QPixmap("B:/this pc/cs lab/Chicken_invaders/Chicken-Invaders/Images/bullet.png").scaled(50,75));
    p1=p;
        // *******  Generating the Bullets automatically ********
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);
}

// Move function is used to 1-  move the bullet upwards
                         // 2- Handle the collision of the bullets with enemies
void Bullet:: move()
{
        // *******  Getting the colliding items with the Bullet ********
    QList<QGraphicsItem *>colliding_items =collidingItems();
        for(int i=0,n=colliding_items.size();i<n;++i)
    {
        if(typeid(*(colliding_items[i]))== typeid(Enemy))
            {
                scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
                p1->increase_score();
                delete colliding_items[i];
            delete this;
                return;
            }
    }

        // *******  Moving the bullets upward ********
    setPos(x(),y()-10);
    if(pos().y()+pixmap().height() <0)
    {
        scene()->removeItem(this);
        delete this;
    }

}
