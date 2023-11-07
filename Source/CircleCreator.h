#ifndef CIRCLECREATOR_H
#define CIRCLECREATOR_H

#include "BaseCreator.h"
#include "QGraphicsEllipseItem"

class CircleCreator : public BaseCreator
{
private:
    CircleEntity *m_circleElem;
    Settings *m_settings;
    QPointF m_startingPoint;

public:
    CircleCreator(PaintScene* scene);
    ~CircleCreator() override;

    void setStartingPoint(QPointF startingPoint);

    virtual QPointF getStartingPoint() override;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // CIRCLECREATOR_H
