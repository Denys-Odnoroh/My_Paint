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
        aCircleElem.push_back(circle);

        m_tempCircle = circle;
        break;
    }
    case Settings::CircleDrawingAction:
    {
        QGraphicsEllipseItem *circleElem = m_scene->addEllipse(m_startingPoint.x() - (1/2), m_startingPoint.y() - (1/2), 1, 1);
        circleElem->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
        circleElem->setBrush(m_scene->backgroundBrush());

        QGraphicsItem* item = static_cast<QGraphicsItem*>(circleElem);
        CircleEntity* circle = static_cast<CircleEntity*>(item);
        aCircleElem.push_back(circle);

        m_tempCircle = circle;
        break;
    }
    }
}

void CircleCreator::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    switch (m_settings->getAction())
    {
    case Settings::OvalDrawingAction:
    {
        delete m_tempCircle;
        QPointF currentPoint = event->scenePos();

        QGraphicsEllipseItem *circleElem = m_scene->addEllipse(m_startingPoint.x(),
                                          m_startingPoint.y(),
                                          currentPoint.x() - m_startingPoint.x(),
                                          currentPoint.y() - m_startingPoint.y());
        circleElem->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
        circleElem->setBrush(m_scene->backgroundBrush());

        QGraphicsItem* item = static_cast<QGraphicsItem*>(circleElem);
        CircleEntity* circle = static_cast<CircleEntity*>(item);

        circle->setPosition(m_startingPoint.x(), m_startingPoint.y());
        aCircleElem.push_back(circle);

        m_tempCircle = circle;
        break;
    }
    case Settings::CircleDrawingAction:
    {
        delete m_tempCircle;
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

        QGraphicsEllipseItem *circleElem = m_scene->addEllipse(m_startingPoint.x(), m_startingPoint.y(),
                                                           iBiggestcoordinate - i, iBiggestcoordinate - i);
        circleElem->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
        circleElem->setBrush(m_scene->backgroundBrush());

        QGraphicsItem* item = static_cast<QGraphicsItem*>(circleElem);
        CircleEntity* circle = static_cast<CircleEntity*>(item);

        circle->setPosition(m_startingPoint.x(), m_startingPoint.y());
        aCircleElem.push_back(circle);

        m_tempCircle = circle;
        break;
    }
    }
}

void CircleCreator::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(!aCircleElem.empty())
    {
        std::vector<BaseEntity*> base;
        base.reserve(aCircleElem.size());

        for (int i = 0; i < aCircleElem.size(); ++i)
        {
            base.push_back(dynamic_cast<BaseEntity*>(aCircleElem[i]));
            base.back()->getPosition() = aCircleElem[i]->getPosition();
        }

        m_scene->getGraphicsItemsList()->push_back(base);
        m_scene->setLastElemIndex(1);
        aCircleElem.clear();
    }
}
