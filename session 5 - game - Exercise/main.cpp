
#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include<QGraphicsView>
#include "player.h"
#include <QTimer>
#include <QDebug>
#include <QBrush>
#include <QMediaPlayer>
#include <QAudioOutput>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // ******* Create the Scene ********
    QGraphicsScene scene;
    scene.setSceneRect(0,0,800,600);


    // *******  Create the View ********
    QGraphicsView view;
    view.setFixedSize(800,600);


    QPixmap bgImage(":/project/SpaceBackground.jpg");
    scene.setBackgroundBrush(bgImage.scaled(scene.width(),scene.height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    // Score and health and game over
    QGraphicsTextItem *score = new QGraphicsTextItem;
    score->setFont(QFont("times", 16));
    score->setDefaultTextColor(QColor(0xf86394));
    score->setPlainText("score : "+ QString::number(0));
    score->setPos(700,10);
    scene.addItem(score);
    QGraphicsTextItem *heart = new QGraphicsTextItem;
    heart->setFont(QFont("times", 16));
    heart->setDefaultTextColor(QColor(0xf86394));
    heart->setPlainText("HP : "+ QString::number(3));
    heart->setPos(700,30);
    scene.addItem(heart);

    // *******  Create the Player ********

    QPixmap playericon(":/project/Spaceship.png");
    playericon = playericon.scaledToWidth(100);
    playericon = playericon.scaledToHeight(100);
    Player * p = new Player(score, heart);
    p->setPixmap(playericon);

    // *******  Setting the foucs to the Player ********
     p->setFlag(QGraphicsItem::ItemIsFocusable);
     p->setFocus();


    // *******  Adjust the location of the Player (middle of the screen) ********
     p->setPos(view.width()/2,view.height()- playericon.height());
      scene.addItem(p);


     // *******  Music ********
      QAudioOutput* audioOutput = new QAudioOutput();
      QMediaPlayer* soundEffect = new QMediaPlayer();
      soundEffect->setSource(QUrl(":/snd/Theme.mp3"));
      soundEffect->setAudioOutput(audioOutput);
      audioOutput->setVolume(10);
      soundEffect->setLoops(1000);
      soundEffect->play();
   // *******   Assign scene to the view   ***************


     view.setScene(&scene);
     view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
     view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

     view.show();


    return a.exec();
}
