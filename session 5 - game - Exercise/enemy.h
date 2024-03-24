#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsRectItem>
#include <QObject>
#include "player.h"

class Enemy: public QObject , public QGraphicsPixmapItem
{ Q_OBJECT
public:
    Player* p1;
    Enemy(Player*);
private:
    int xmove=5;
    bool direction;
public slots:
    void move();
};

#endif // ENEMY_H
