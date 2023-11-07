#ifndef BASECREATOR_H
#define BASECREATOR_H

#include "PaintScene.h"
#include "Entityes.h"

class BaseCreator
{
public:
    BaseCreator(PaintScene *scene) : m_scene(scene) {};
    virtual ~BaseCreator() {};
    PaintScene* m_scene;

    virtual RectangleEntity* getRectangle(){};
    virtual QPointF getStartingPoint(){};
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event){};
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event){};
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event){};
};

#endif // BASECREATOR_H
