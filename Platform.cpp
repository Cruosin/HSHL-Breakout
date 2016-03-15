#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QBrush>

#include "Platform.h"

Platform::Platform(){
    setRect(0,0,100,20);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    setBrush(brush);
}

void Platform::MovementLeft(){
    //check if out of bounds
    if(this->x() > 0){
    this->moveBy(-6,0);
    }
}

void Platform::MovementRight(QGraphicsScene *Scene){
    //check if out of bounds
    if(this->x() < Scene->width()-100){
    this->moveBy(6,0);
    }
}
