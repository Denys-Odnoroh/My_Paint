#include "GraphicsItem.h"

GraphicsItem::GraphicsItem(Settings *settings, QPointF startingPoint, QObject *parent) :
                           QObject(parent), QGraphicsItem()
{
    this->m_startingPoint = startingPoint;
    this->settings = settings;
}

GraphicsItem::~GraphicsItem()
{

}

void GraphicsItem::setSettings(Settings *settings)
{
    this->settings = settings;
}

void GraphicsItem::setStartingPoint(QPointF startingPoint)
{
    this->m_startingPoint = startingPoint;
}

void GraphicsItem::setLastElementIndex(int lastElementIndex)
{
    this->iLastElementIndex = lastElementIndex;
}

QPointF GraphicsItem::getStartingPoint()
{
    return m_startingPoint;
}

Settings *GraphicsItem::getSettings()
{
    return settings;
}

int GraphicsItem::getLastElementIndex()
{
    return iLastElementIndex;
}

QRectF GraphicsItem::boundingRect() const
{
    return QRectF (0,0,1000,900);
}

void GraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(settings->getDrawingColor());
    painter->setBrush(settings->getBackgroundColor());

    switch (settings->getAction())
    {
    case Settings::EraseAction:
    {

        break;
    }
    case Settings::BrushDrawingAction:
    {
        int iRadius = settings->getBrushSize()/2;

        QPointF p(100, 100);
        painter->drawLine(m_startingPoint.x() - iRadius,
                             m_startingPoint.y() - iRadius,
                             settings->getBrushSize(),
                             settings->getBrushSize());
        painter->drawEllipse(p, m_startingPoint.x() - iRadius,
                             m_startingPoint.y() - iRadius);

        break;
    }
    case Settings::OvalDrawingAction:
    {

        break;
    }
    case Settings::CircleDrawingAction:
    {

        break;
    }
    case Settings::RectangleDrawingAction:
    {
        painter->drawRect(-30,-30,60,60);
        break;
    }
    }

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void GraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setPos(mapToScene(event->pos()));
}

void GraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ClosedHandCursor));
}

void GraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
}

