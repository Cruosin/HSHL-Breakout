
#ifndef PLAYINGFIELD_H
#define	PLAYINGFIELD_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>

#include "Block.h"
#include "Ball.h"
#include "Platform.h"

class PlayingField:public QGraphicsView{
    Q_OBJECT
    
    public:
        PlayingField();
        void AddElements();
        void AddBlocks();
        QGraphicsScene *scene;
        
    public slots:
        void BallMovement();
        void GameOver();
        void PlatformCollision();
        void BlockCollision();
        
    private:
        Ball *ball;
        Platform *platform;
        Block *block[16][5];
        bool blocksadded;
        int HitCounter;
        int BlockCounter;
        
    protected:
        void keyPressEvent(QKeyEvent *event);
};

#endif	/* PLAYINGFIELD_H */

