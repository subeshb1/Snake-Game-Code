#ifndef SNAKEPART_H
#define SNAKEPART_H

#include <QGraphicsRectItem>
class SnakePart:public QGraphicsPixmapItem
{
public:
    SnakePart(QGraphicsItem *parent = 0);

    SnakePart *getForward() ;
    void setForward(SnakePart *value);

    SnakePart *getBackward() ;
    void setBackward(SnakePart *value);

    QString getDirection() ;
    void setDirection( QString value);

    void move();
    void addBehind();
    void checkCollidingObjects();

    QString part;
    void setImage();
private:

    SnakePart *forward;
    SnakePart *backward;
    QString direction;
};

#endif // SNAKEPART_H
