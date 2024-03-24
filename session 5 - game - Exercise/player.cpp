#include "player.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QDebug>
#include "enemy.h"

Player::Player(QGraphicsTextItem *score, QGraphicsTextItem* health) {
    this->score = score;
    this->heart = health;
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

        Bullet * bullet = new Bullet(this);
        bullet->setPos(x()+25,y()-65);
        scene()->addItem(bullet);

    }


}

 // CreateEnemy function used to create the eneimes
void Player::createEnemy()
{

    Enemy* enemy = new Enemy(this);
    scene()->addItem(enemy);
    // QGraphicsTextItem * r= new QGraphicsTextItem;
    // r->setPos(200,200);
    // s.addItem(r);


}
void  Player::increase_score(){
    scorecount++;
    score->setPlainText("Score: " + QString::number(scorecount));
}
void  Player::decrease_heart(){
    heartcount--;
    heart->setPlainText("HP: " + QString::number(heartcount));
}
void  Player::decrease_score(){
    scorecount--;
    score->setPlainText("Score: " + QString::number(scorecount));
}
int Player::getscore(){
    return scorecount;
}
int Player::getheart(){
    return heartcount;
}



