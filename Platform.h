
#ifndef PLATFORM_H
#define	PLATFORM_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>

class Platform:public QGraphicsRectItem{
    
    public:
        Platform();
        void MovementLeft();
        void MovementRight(QGraphicsScene *Scene);
};

#endif	/* PLATFORM_H */

