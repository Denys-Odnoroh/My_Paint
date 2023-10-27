#include "PaintScene.h"

using namespace std;

PaintScene::PaintScene()
{

}

PaintScene::PaintScene(PaintScene &scene)
{
    scene.setStartingPoint(this->getStartingPoint());
}

PaintScene::~PaintScene()
{

}

std::vector<DravableElementArray> PaintScene::getGraphicsItemsList()
{
    return m_graphicsItems;
}

void PaintScene::setSettings(Settings *settings)
{
    this->settings = settings;
}

void PaintScene::setStartingPoint(QPointF startingPoint)
{
    this->m_startingPoint = startingPoint;
}

void PaintScene::setLastElementIndex(int lastElementIndex)
{
    this->iLastElementIndex = lastElementIndex;
}

QPointF PaintScene::getStartingPoint()
{
    return m_startingPoint;
}

Settings *PaintScene::getSettings()
{
    return settings;
}

int PaintScene::getLastElementIndex()
{
    return iLastElementIndex;
}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    for(int i = iLastElementIndex; iLastElementIndex < m_graphicsItems.size(); ++i)
    {
        m_graphicsItems.pop_back();
    }

    this->setStartingPoint(event->scenePos());

    switch (settings->getAction())
    {
    case Settings::EraseAction:
    {
        QGraphicsEllipseItem *graphicsEllipseItem = this->addEllipse(m_startingPoint.x() - (settings->getEraserSize()/2),
               m_startingPoint.y() - (settings->getEraserSize()/2),
               settings->getEraserSize(), settings->getEraserSize(),
               QPen(Qt::NoPen), QBrush(settings->getBackgroundColor()));

        QGraphicsItem *graphicsItem = dynamic_cast <QGraphicsItem*> (graphicsEllipseItem);
        m_aDrawableElement.push_back(graphicsItem);
        break;
    }
    case Settings::BrushDrawingAction:
    {
        QGraphicsEllipseItem *graphicsEllipseItem = this->addEllipse(m_startingPoint.x() - (settings->getBrushSize()/2),
                   m_startingPoint.y() - (settings->getBrushSize()/2),
                   settings->getBrushSize(), settings->getBrushSize(),
                   QPen(Qt::NoPen), QBrush(settings->getDrawingColor()));

        QGraphicsItem *graphicsItem = dynamic_cast <QGraphicsItem*> (graphicsEllipseItem);
        m_aDrawableElement.push_back(graphicsItem);
        break;
    }
    case Settings::OvalDrawingAction:
    {
        start = new QPointF(m_startingPoint);
        auto circle = new QGraphicsEllipseItem(start->x() - (1/2), start->y() - (1/2), 1, 1);
        circle->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
        circle->setBrush(this->backgroundBrush());

        m_aDrawableElement.push_back(circle);

        m_tempCircle = circle;
        break;
    }
    case Settings::CircleDrawingAction:
    {
        start = new QPointF(m_startingPoint);

        QGraphicsEllipseItem *circle = this->addEllipse(start->x() - (1/2), start->y() - (1/2), 1, 1);
        circle->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
        circle->setBrush(this->backgroundBrush());

        m_aDrawableElement.push_back(circle);

        m_tempCircle = circle;
        break;
    }
    }
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    switch (settings->getAction())
    {
    case Settings::EraseAction:
    {
        QGraphicsLineItem *graphicsLineItem = this->addLine(m_startingPoint.x(), m_startingPoint.y(),
                event->scenePos().x(), event->scenePos().y(),
                QPen(settings->getBackgroundColor(), settings->getEraserSize(), Qt::SolidLine, Qt::RoundCap));

        m_aDrawableElement.push_back(graphicsLineItem);
        break;
    }
    case Settings::BrushDrawingAction:
    {
        QGraphicsLineItem *graphicsLineItem = this->addLine(m_startingPoint.x(), m_startingPoint.y(),
                event->scenePos().x(), event->scenePos().y(),
                QPen(settings->getDrawingColor(), settings->getBrushSize(), Qt::SolidLine, Qt::RoundCap));

        m_aDrawableElement.push_back(graphicsLineItem);
        break;
    }
    case Settings::OvalDrawingAction:
    {
        delete m_tempCircle;
        QPointF currentPoint = event->scenePos();
        auto circle = new QGraphicsEllipseItem(start->x(),
                                               start->y(),
                                               currentPoint.x() - start->x(),
                                               currentPoint.y() - start->y());
        circle->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
        circle->setBrush(this->backgroundBrush());

        m_aDrawableElement.push_back(circle);

        m_tempCircle = circle;
        break;
    }
    case Settings::CircleDrawingAction:
    {
        delete m_tempCircle;
        QPointF currentPoint = event->scenePos();
        int iBiggestcoordinate;
        int i;

        if(currentPoint.x() - start->x() >= currentPoint.y() - start->y())
        {
            iBiggestcoordinate = currentPoint.x();
            i = start->x();
        }
        else if(currentPoint.x() - start->x() < currentPoint.y() - start->y())
        {
            iBiggestcoordinate = currentPoint.y();
            i = start->y();
        }

        QGraphicsEllipseItem *circle = this->addEllipse(start->x(), start->y(),
                                                        iBiggestcoordinate - i, iBiggestcoordinate - i);
        circle->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
        circle->setBrush(this->backgroundBrush());

        m_aDrawableElement.push_back(circle);

        m_tempCircle = circle;
        break;
    }
    }
    m_startingPoint = event->scenePos();
}

void PaintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->m_graphicsItems.push_back(m_aDrawableElement);
    iLastElementIndex++;

    if(!m_aDrawableElement.empty())
        m_aDrawableElement.clear();
}
