#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QBrush>
#include <QTimer>
#include <QWidget>

#include "Ball.h"

Ball::Ball(){
    setRect(0,0,50,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    setBrush(brush);
    this->dx = 1;
    this->dy = -1;
}

void Ball::Movement(QGraphicsScene *Scene){
    this->moveBy(dx,dy);
    
    if(this->x() > Scene->width()-50){
        dx = dx * (-1);
    }
    if(this->x() < 0){
        dx = dx * (-1);
    }
    if(this->y() > Scene->height()-50){
        dy = dy * (-1);
    }
    if(this->y() < 0){
        dy = dy * (-1);
    }
    
    update();
}

void Ball::BlockCollision(Block *CollidingBlock){
    bool VelocityChanged = false;
    //Where did the ball collide from?
    if(this->y() > CollidingBlock->y() && dy < 0 && (VelocityChanged == false)){
        dy = dy * (-1);
        VelocityChanged = true;
    }
    if(this->y() < CollidingBlock->y() && dy > 0 && (VelocityChanged == false)){
        dy = dy * (-1);
        VelocityChanged = true;
    }
    if(this->x() > CollidingBlock->x() && dx < 0 && (VelocityChanged == false)){
        dx = dx * (-1);
        VelocityChanged = true;
    }
    if(this->x() < CollidingBlock->x() && dx > 0 && (VelocityChanged == false)){
        dx = dx * (-1);
        VelocityChanged = true;
    }
}

void Ball::PlatformCollision(){
    dy = dy * (-1);
}