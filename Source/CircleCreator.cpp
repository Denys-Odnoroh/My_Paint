#include "CircleCreator.h"

CircleCreator::CircleCreator(PaintScene* scene) : BaseCreator(scene)
{
    m_settings = m_scene->getSettings();
}

CircleCreator::~CircleCreator()
{

}

QPointF CircleCreator::getStartingPoint()
{
    return m_startingPoint;
}

void CircleCreator::setStartingPoint(QPointF startingPoint)
{
    this->m_startingPoint = startingPoint;
}

void CircleCreator::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setStartingPoint(event->scenePos());

    switch (m_settings->getAction())
    {
    case Settings::OvalDrawingAction:
    {
        QGraphicsEllipseItem *circleElem = m_scene->addEllipse(m_startingPoint.x() - (1/2), m_startingPoint.y() - (1/2), 1, 1);
        circleElem->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
        circleElem->setBrush(m_scene->backgroundBrush());

        QGraphicsItem* item = static_cast<QGraphicsItem*>(circleElem);
        CircleEntity* circle = static_cast<CircleEntity*>(item);

        circle->setPosition(m_startingPoint.x(), m_startingPoint.y());
        m_circleElem = circle;
        break;
    }
    case Settings::CircleDrawingAction:
    {
        QGraphicsEllipseItem *circleElem = m_scene->addEllipse(m_startingPoint.x() - (1/2), m_startingPoint.y() - (1/2), 1, 1);
        circleElem->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
        circleElem->setBrush(m_scene->backgroundBrush());

        QGraphicsItem* item = static_cast<QGraphicsItem*>(circleElem);
        CircleEntity* circle = static_cast<CircleEntity*>(item);

        circle->setPosition(m_startingPoint.x(), m_startingPoint.y());
        m_circleElem = circle;
        break;
    }
    }
}

void CircleCreator::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    m_scene->removeItem(m_circleElem);

    switch (m_settings->getAction())
    {
    case Settings::OvalDrawingAction:
    {
        QPointF currentPoint = event->scenePos();

        QGraphicsEllipseItem *circleElem = m_scene->addEllipse(m_startingPoint.x(),
                                          m_startingPoint.y(),
                                          currentPoint.x() - m_startingPoint.x(),
                                          currentPoint.y() - m_startingPoint.y(),
                                          QPen(m_settings->getDrawingColor()));
        circleElem->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
        circleElem->setBrush(m_scene->backgroundBrush());

        QGraphicsItem* item = static_cast<QGraphicsItem*>(circleElem);
        CircleEntity* circle = static_cast<CircleEntity*>(item);

        circle->setPosition(m_startingPoint.x(), m_startingPoint.y());
        m_circleElem = circle;
        break;
    }
    case Settings::CircleDrawingAction:
    {
        QPointF currentPoint = event->scenePos();
        int iBiggestcoordinate;
        int i;

        if(currentPoint.x() - m_startingPoint.x() >= currentPoint.y() - m_startingPoint.y())
        {
            iBiggestcoordinate = currentPoint.x();
            i = m_startingPoint.x();
        }
        else if(currentPoint.x() - m_startingPoint.x() < currentPoint.y() - m_startingPoint.y())
        {
            iBiggestcoordinate = currentPoint.y();
            i = m_startingPoint.y();
        }

        QGraphicsItem *circleElem = m_scene->addEllipse(m_startingPoint.x(), m_startingPoint.y(),
                                                        iBiggestcoordinate - i, iBiggestcoordinate - i,
                                                        QPen(m_settings->getDrawingColor()));
        circleElem->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);

        CircleEntity* circle = static_cast<CircleEntity*>(circleElem);

        circle->setPosition(m_startingPoint.x(), m_startingPoint.y());
        m_circleElem = circle;
        break;
    }
    }
}

void CircleCreator::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(m_circleElem != nullptr)
    {
        std::vector<QPointF> points;
        std::vector<BaseEntity*> base;

        base.push_back(dynamic_cast<BaseEntity*>(m_circleElem));
        base.back()->getPosition() = m_circleElem->getPosition();
        points.push_back(base.back()->getPosition());

        m_scene->getGraphicsItemsList()->push_back(base);
        m_scene->incrementLastElemIndex();

        ObjectChangeHistory *object = new ObjectChangeHistory(true, base, points);

        m_scene->getHistory()->push_back(object);
        m_scene->incrementChangeHistoryIndex();
    }
}
