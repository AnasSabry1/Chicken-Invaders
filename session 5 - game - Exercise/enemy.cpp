#include "enemy.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QFont>
#include <stdlib.h> // rand() -> to generate really large integer
#include <QTimer>
#include <QDebug>
#include "player.h"
#include<QGraphicsView>

Enemy::Enemy(Player *p) {
        // *******  Setting the size of the enemy ********
    setPixmap(QPixmap("B:/this pc/cs lab/Chicken_invaders/Chicken-Invaders/Images/chicken.png").scaled(100,100));
        direction = rand()%2;
    if(direction){
            xmove=5;}
    else{xmove =-5;}
        // *******  Setting the postion of the enemy within the view dimensions ********
    int random_number = rand() % 700;
    setPos(random_number,0);
    p1=p;
        // *******  Moving the enemies downwards automatically every 50 milli second ********
QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);

}
// Function move: move the enemy downwards untill the end of the scene then remove it and delete it
void Enemy:: move()
{
    if(x()<0||x()>700){
        if(xmove>0){
            xmove=-5;
        }
        else if(xmove<0){
            xmove=5;
        }
    }
    QList<QGraphicsItem *>colliding_items =collidingItems();
    for(int i=0,n=colliding_items.size();i<n;++i)
    {
        if(typeid(*(colliding_items[i]))== typeid(Player))
        {

            scene()->removeItem(this);
            p1->decrease_score();
            p1->decrease_heart();



            delete this;

            return;
        }
    }
    setPos(x()+xmove,y()+5);
        if(y()+pixmap().height()>600)
    {
        p1->decrease_score();
        p1->decrease_heart();
        scene()->removeItem(this);
            delete this;
    }
}

