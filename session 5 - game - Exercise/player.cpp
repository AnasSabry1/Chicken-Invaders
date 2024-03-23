#include "player.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QDebug>
#include "enemy.h"

Player::Player() {

}

void Player::keyPressEvent(QKeyEvent *event)
{
        // *******  Event Handling for the Player ********
    if(event->key()== Qt::Key_Left)
    {
        if(x()>0) // to prevent the player from getting out of the screen
        {
        setPos(x()-30,y());
        }
    }
    else if(event->key()== Qt::Key_Right)

    { if(x()+100<800) // to prevent the player from getting out of the screen
        setPos(x()+30,y());
    }
    else if(event->key()== Qt::Key_Space)
    {

        Bullet * bullet = new Bullet();
        bullet->setPos(x()+25,y()-65);
        scene()->addItem(bullet);

    }


}

 // CreateEnemy function used to create the eneimes
void Player::createEnemy()
{

    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);
    // QGraphicsTextItem * r= new QGraphicsTextItem;
    // r->setPos(200,200);
    // s.addItem(r);


}

