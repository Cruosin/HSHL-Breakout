
#ifndef BALL_H
#define	BALL_H

#include <QGraphicsEllipseItem>
#include <QGraphicsscene>

#include "Block.h"

class Ball:public QGraphicsEllipseItem{
    
    public:
        Ball();
        void BlockCollision(Block *CollidingBlock);
        void PlatformCollision();
        void Movement(QGraphicsScene *scene);
        
    private:
        int dx;
        int dy;
};

#endif	/* BALL_H */

