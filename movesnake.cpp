#include "movesnake.h"
#include "snakepart.h"
#include <QTimer>
#include <food.h>
#include <QDebug>
#include <QFont>
MoveSnake::MoveSnake(QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    snakeHead = new SnakePart(this);
    snakeHead->setForward(NULL);
    snakeHead->setBackward(NULL);
    snakeHead->setPos(200,200);
    snakeHead->setDirection("RIGHT");
    snakeHead->part = "HEAD";
    snakeHead->setImage();
    snakeTail = snakeHead;

    t = new QTimer();
    connect(t,SIGNAL(timeout()),this,SLOT(move()));

    foodTimer = new QTimer();
    connect(foodTimer,SIGNAL(timeout()),this,SLOT(makeFood()));

    food2Timer = new QTimer();
    connect(food2Timer,SIGNAL(timeout()),this,SLOT(makeFood2()));

    direction = "RIGHT";

    addPart();
    addPart();
    addPart();

    text = new QGraphicsTextItem(this);
    text->setVisible(true);
    text->setPlainText("Press Space to continue");
    text->setPos(650,250);
    text->setFont(QFont("",14));


//  /  makeBoard();

}

void MoveSnake::keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_Down && snakeHead->getDirection() != "UP") {
      //  snake->setY(snake->y()+40);
        direction = "DOWN";
    }
    else if(event->key() == Qt::Key_Up && snakeHead->getDirection() != "DOWN") {
      //  snake->setY(snake->y()-40);
        direction = "UP";
    }
    else if(event->key() == Qt::Key_Right && snakeHead->getDirection() != "LEFT") {
      //  snake->setX(snake->x()+40);
        direction = "RIGHT";
    }
    else if(event->key() == Qt::Key_Left && snakeHead->getDirection() != "RIGHT") {
        //snake->setX(snake->x()-40);
        direction = "LEFT";
    }
    else if(event->key() == Qt::Key_Space){
        if(t->isActive()){
            foodTimer->stop();
            food2Timer->stop();
        t->stop();
        text->setVisible(true);
        }
        else{

            foodTimer->start(3000);
            food2Timer->start(7000);
            t->start(90);
            text->setVisible(false);
        }

    }
}

void MoveSnake::makeBoard()
{
    for(int i = 0 ;i <9*5;i++){
        for(int j = 0; j < 14*5; j++) {
            QGraphicsRectItem *rect= new QGraphicsRectItem(this);
            rect->setRect(j*40,i*40,40,40);
        }
    }



}

void MoveSnake::move() {
    snakeHead->setDirection(direction);
    moveSnake();

}

void MoveSnake::makeFood()
{
    food * f1 = new food(this,"APPLE");
    f1->setX(qrand() % (1400/40)* 40);
    f1->setY(qrand() % (880/40) * 40) ;

}
void MoveSnake::makeFood2()
{
    food * f1 = new food(this);
    f1->setX(qrand() % (1400/40)* 40);
    f1->setY(qrand() % (880/40) * 40) ;

}

void MoveSnake::addPart(){
    SnakePart *part = new SnakePart(this);
    SnakePart *temp = snakeHead;
    while(temp->getBackward() != NULL) {
        temp = temp->getBackward();
    }
    temp->setBackward( part);
    part->setForward( temp);
    part->setBackward(NULL);
    part->addBehind();
    part->setDirection(temp->getDirection());
    snakeTail = part;
    part->part = "TAIL";
    if(temp != snakeHead)
    temp->part = "PART";
    part->setImage();
    temp->setImage();
}

void MoveSnake::moveSnake()
{
    //qDebug() << "Entry";
   SnakePart *temp = snakeTail;

   while(temp!=NULL) {
    //   qDebug() << "Enry 2";
       temp->move();
       temp = temp->getForward();
   }
}

