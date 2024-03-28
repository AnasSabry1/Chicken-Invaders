#include "player.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QDebug>
#include <QTimer>
#include "enemy.h"
#include <QMediaPlayer>
#include <QAudioOutput>

Player::Player(QGraphicsTextItem *score, QGraphicsTextItem* health) {
    this->score = score;
    this->heart = health;
    time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),this,SLOT(createEnemy()));
    time->start(2000);
}

void Player::keyPressEvent(QKeyEvent *event)
{


    if(control){
        // *******  Event Handling for the Player ********
    if(event->key()== Qt::Key_Left)
    {
        if(x()>0) // to prevent the player from getting out of the screen
        {
        setPos(x()-40,y());
        }
    }
    else if(event->key()== Qt::Key_Right)

    { if(x()+100<800) // to prevent the player from getting out of the screen
        setPos(x()+40,y());
    }
    else if(event->key()== Qt::Key_Up)

    { if(y()>0) // to prevent the player from getting out of the screen
            setPos(x(),y()-40);
    }
    else if(event->key()== Qt::Key_Down)

    { if(y()+100<600) // to prevent the player from getting out of the screen
            setPos(x(),y()+40);
    }
    else if(event->key()== Qt::Key_Space)
    {
        QAudioOutput* audioOutput = new QAudioOutput();
        QMediaPlayer* soundEffect = new QMediaPlayer();
        soundEffect->setSource(QUrl("qrc:/snd/blast.mp3"));
        soundEffect->setAudioOutput(audioOutput);
        audioOutput->setVolume(10);
        soundEffect->play();

        Bullet * bullet = new Bullet(this);
        bullet->setPos(x()+25,y()-65);
        scene()->addItem(bullet);

    }}


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
    score->setDefaultTextColor(Qt::blue);
    score->setPlainText("Score: " + QString::number(scorecount));
}
void  Player::decrease_heart(){
    if(control){
        heartcount--;}
    if(heartcount == 0){
        Gameover();
    }
    heart->setDefaultTextColor(Qt::red);
    heart->setPlainText("HP: " + QString::number(heartcount));

}
void  Player::decrease_score(){
    if(control){scorecount--;}
    score->setDefaultTextColor(Qt::red);
    score->setPlainText("Score: " + QString::number(scorecount));
}
int Player::getscore(){
    return scorecount;
}
int Player::getheart(){
    return heartcount;
}
void Player::Gameover(){
    QObject::disconnect(time, SIGNAL(timeout()),this,SLOT(createEnemy()));
    QGraphicsTextItem *gameover = new QGraphicsTextItem;
    gameover->setFont(QFont("times", 40));
    gameover->setDefaultTextColor(Qt::red);
    gameover->setPlainText("Game Over");
    gameover->setPos(250,250);
    scene()->addItem(gameover);
    QGraphicsTextItem *finalscore = new QGraphicsTextItem;
    finalscore->setFont(QFont("times", 40));
    finalscore->setDefaultTextColor(Qt::red);
    finalscore->setPlainText("Score: " + QString::number(scorecount));
    finalscore->setPos(250,350);
    scene()->addItem(finalscore);
    control=0;

}



