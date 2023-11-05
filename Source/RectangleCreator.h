#ifndef RECTANGLECREATOR_H
#define RECTANGLECREATOR_H

#include "BaseCreator.h"
#include "QGraphicsEllipseItem"

class RectangleCreator : public BaseCreator
{
private:
    std::vector<std::shared_ptr<RectangleEntity*>> aRectElem;
    Settings* m_settings;
    RectangleEntity *m_tempRectangle;
    QPointF m_startingPoint;

public:
    RectangleCreator(PaintScene* scene);
    ~RectangleCreator() override;

    void setStartingPoint(QPointF startingPoint);

    virtual RectangleEntity* getTempRectangle() override;
    virtual QPointF getStartingPoint() override;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // RECTANGLECREATOR_H
