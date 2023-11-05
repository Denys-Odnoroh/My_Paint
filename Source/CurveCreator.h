#ifndef ELLIPSEENTITY_H
#define ELLIPSEENTITY_H

#include "BaseCreator.h"
#include "QGraphicsEllipseItem"

class CurveCreator : public BaseCreator
{
private:
    std::vector<LineEntity*> aCurveElem;
    Settings* m_settings;
    QPointF m_startingPoint;

public:
    CurveCreator(PaintScene* scene);
    ~CurveCreator() override;

    void setStartingPoint(QPointF startingPoint);

    virtual QPointF getStartingPoint() override;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

};

#endif // ELLIPSEENTITY_H
