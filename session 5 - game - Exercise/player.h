#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(QGraphicsTextItem* score, QGraphicsTextItem* health);
public:
    void keyPressEvent(QKeyEvent * event);
    void increase_score();
    void decrease_heart();
    void decrease_score();
    int getscore();
    int getheart();
    void createsandh();
    void Gameover();
    bool check();
private:
    QGraphicsTextItem *score = new QGraphicsTextItem;
    QGraphicsTextItem *heart = new QGraphicsTextItem;
    QTimer * time;
    int scorecount=0;
    int heartcount=3;
    bool control =1;


public slots:
    void createEnemy();

};

#endif // PLAYER_H
