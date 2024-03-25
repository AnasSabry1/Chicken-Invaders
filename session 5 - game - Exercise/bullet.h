#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsItem>
#include <QObject>
#include "player.h"

class Bullet: public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT
public:
    Bullet(Player*);
private:
    Player *p1;

public slots:
    void move();
};

#endif // BULLET_H
