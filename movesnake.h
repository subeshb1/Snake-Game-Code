#ifndef MOVESNAKE_H
#define MOVESNAKE_H
#include <QKeyEvent>
#include <QGraphicsItem>
#include "snakepart.h"
class MoveSnake:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    MoveSnake(QGraphicsItem *parent = 0);
    void keyPressEvent(QKeyEvent *event);
    void makeBoard();
    void addPart();
    void moveSnake();


public slots:
    void move();
    void makeFood2();
    void makeFood();
private:
    SnakePart *snakeHead;
    SnakePart *snakeTail;
    QString direction;
    QTimer *t;
    QTimer *foodTimer;
    QTimer *food2Timer;
    QGraphicsTextItem *text;
};

#endif // MOVESNAKE_H

