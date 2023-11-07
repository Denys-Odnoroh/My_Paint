#ifndef RECTANGLECREATOR_H
#define RECTANGLECREATOR_H

#include "BaseCreator.h"

class RectangleCreator : public BaseCreator
{
private:
    RectangleEntity *m_rectangle;
    Settings* m_settings;
    QPointF m_startingPoint;

public:
    RectangleCreator(PaintScene* scene);
    ~RectangleCreator() override;

    void setStartingPoint(QPointF startingPoint);

    virtual RectangleEntity* getRectangle() override;
    virtual QPointF getStartingPoint() override;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // RECTANGLECREATOR_H
