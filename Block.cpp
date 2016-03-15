#include <QGraphicsRectItem>
#include <QBrush>

#include "Block.h"
#include "Ball.h"
#include "PlayingField.h"

Block::Block(int x, int y){
    //reference: https://github.com/MeLikeyCode/BreakoutGameDemo/blob/master/Block.cpp
    setRect(x+4,y+4,46,46);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    setBrush(brush);
}

void Block::HitByBall(){
    //Move the hit block to an irrelevant Position.
    //Program crashes if delete is used,
    //probably because of the empty space in the array.
    this->setPos(-5000,-5000);
}