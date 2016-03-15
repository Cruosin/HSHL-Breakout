
#ifndef BLOCK_H
#define	BLOCK_H

#include <QGraphicsRectItem>

class Block:public QGraphicsRectItem{
    
    
    public:
        Block(int x, int y);
        void HitByBall();
        
        
};

#endif	/* BLOCK_H */

