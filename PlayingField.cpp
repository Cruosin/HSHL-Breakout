#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QKeyEvent>

#include "Block.h"
#include "Ball.h"
#include "Platform.h"
#include "PlayingField.h"

PlayingField::PlayingField(){
    this->setFixedSize(810,610);
    this->blocksadded = false;
    this->HitCounter = 0;
    this->BlockCounter = 0;
    
    AddElements();
    
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(BallMovement()));
    connect(timer, SIGNAL(timeout()), this, SLOT(GameOver()));
    connect(timer, SIGNAL(timeout()), this, SLOT(PlatformCollision()));
    connect(timer,SIGNAL(timeout()),this,SLOT(BlockCollision()));
    timer->start(10);
}

void PlayingField::AddElements(){
    this->scene = new QGraphicsScene(0,0,800,600);
    setScene(scene);
    
    AddBlocks();
    
    this->ball = new Ball();
    this->ball->setPos(200,400);
    scene->addItem(ball);
    
    this->platform = new Platform;
    this->platform->setPos(350,570);
    scene->addItem(platform);
}

void PlayingField::AddBlocks(){
    if(this->blocksadded == false){
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 16; j++){
                this->block[j][i] = new Block(j*50,i*50);
                scene->addItem(block[j][i]);
                this->BlockCounter = this->BlockCounter + 1;
            }
        }
    }
    this->blocksadded = true;
}

void PlayingField::keyPressEvent(QKeyEvent* event){
    //Move Platform in pressed keys direction
    if (event->key() == Qt::Key_Left)
        platform->MovementLeft();
    
    if (event->key() == Qt::Key_Right)
        platform->MovementRight(this->scene);
}

void PlayingField::BallMovement(){
    this->ball->Movement(this->scene);
}

void PlayingField::PlatformCollision(){
    if(this->ball->collidesWithItem(this->platform)){
        this->ball->PlatformCollision();
    }
}


void PlayingField::BlockCollision(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 16; j++){
            if(this->ball->collidesWithItem(this->block[j][i])){
                this->ball->BlockCollision(this->block[j][i]);
                this->block[j][i]->HitByBall();
                this->HitCounter = HitCounter + 1;
                GameOver();
            }
        }
    }
}

void PlayingField::GameOver(){
    if(this->ball->y() == 600-50){
        this->close();
    }
    if(this->HitCounter == this->BlockCounter){
        this->close();
    }
}