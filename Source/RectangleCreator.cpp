#include "RectangleCreator.h"

RectangleCreator::RectangleCreator(PaintScene* scene) : BaseCreator(scene)
{
    m_settings = m_scene->getSettings();
}

RectangleCreator::~RectangleCreator()
{

}

QPointF RectangleCreator::getStartingPoint()
{
    return m_startingPoint;
}

RectangleEntity *RectangleCreator::getTempRectangle()
{
    return m_tempRectangle;
}

void RectangleCreator::setStartingPoint(QPointF startingPoint)
{
    this->m_startingPoint = startingPoint;
}

void RectangleCreator::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setStartingPoint(event->scenePos());

    switch (m_settings->getAction())
    {
    case Settings::ObjectsSelectionAction:
    {
        QGraphicsRectItem *rect = m_scene->addRect(m_startingPoint.x() - (1/2), m_startingPoint.y() - (1/2), 1, 1);
        rect->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
        rect->setBrush(m_scene->backgroundBrush());

        QGraphicsItem* item = static_cast<QGraphicsItem*>(rect);
        RectangleEntity* rectangle = static_cast<RectangleEntity*>(item);

        m_tempRectangle = rectangle;
        break;
    }
    }
}

void RectangleCreator::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    switch (m_settings->getAction())
    {
    case Settings::ObjectsSelectionAction:
    {
        delete m_tempRectangle;
        QPointF currentPoint = event->scenePos();
        QGraphicsRectItem *rect = m_scene->addRect(m_startingPoint.x(),
                                                   m_startingPoint.y(),
                                                   currentPoint.x() - m_startingPoint.x(),
                                                   currentPoint.y() - m_startingPoint.y());
        rect->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
        rect->setBrush(m_scene->backgroundBrush());

        QGraphicsItem* item = static_cast<QGraphicsItem*>(rect);
        RectangleEntity* rectangle = static_cast<RectangleEntity*>(item);

        m_tempRectangle = rectangle;
        break;
    }
    }
}

void RectangleCreator::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    switch (m_settings->getAction())
    {
    case Settings::ObjectsSelectionAction:
    {
        m_scene->getSelectedObjects()->clear();
        m_scene->removeItem(m_tempRectangle);

        int iStartX = m_startingPoint.x();
        int iStartY = m_startingPoint.y();
        int iFinalX = m_startingPoint.x() + m_tempRectangle->boundingRect().width();
        int iFinalY = m_startingPoint.y() + m_tempRectangle->boundingRect().height();

        for(const DravableElementArray &aDrawableElem : *m_scene->getGraphicsItemsList())
        {
            for (BaseEntity* pGraphicsItem : aDrawableElem)
            {
                int itemX = pGraphicsItem->getPosition().x();
                int itemY = pGraphicsItem->getPosition().y();

                if(iStartX < itemX
                    && itemX < iFinalX
                    && iStartY < itemY
                    && itemY < iFinalY)
                {
                    m_scene->getSelectedObjects()->push_back(aDrawableElem);
                    break;
                }
            }
        }
        this->m_settings->setAction(Settings::DraggingObjectAction);
    }
    }
}
