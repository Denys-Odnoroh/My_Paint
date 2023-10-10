#include "PaintScene.h"

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

void PaintScene::setSettings(Settings *settings)
{
    this->settings = settings;
}

void PaintScene::setStartingPoint(QPointF startingPoint)
{
    this->m_startingPoint = startingPoint;
}

QPointF PaintScene::getStartingPoint()
{
    return m_startingPoint;
}

Settings *PaintScene::getSettings()
{
    return settings;
}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    m_startingPoint = event->scenePos();

    switch (settings->getDrawingFlag())
    {
    case 0:
    {
        addEllipse(event->scenePos().x(), event->scenePos().y(),
                   settings->getEraserSize(), settings->getEraserSize(), QPen(Qt::NoPen), QBrush(settings->getBackgroundColor()));
        break;

    }
    case 1:
    {
        addEllipse(event->scenePos().x(), event->scenePos().y(),
                   settings->getBrushSize(), settings->getBrushSize(), QPen(Qt::NoPen), QBrush(settings->getDrawingColor()));
        break;
    }
    }
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    switch (settings->getDrawingFlag())
    {
    case 0:
    {
        addLine(m_startingPoint.x(), m_startingPoint.y(),
                event->scenePos().x(), event->scenePos().y(),
                QPen(settings->getBackgroundColor(), settings->getEraserSize(), Qt::SolidLine, Qt::RoundCap));
        break;
    }
    case 1:
    {
        addLine(m_startingPoint.x(), m_startingPoint.y(),
                event->scenePos().x(), event->scenePos().y(),
                QPen(settings->getDrawingColor(), settings->getBrushSize(), Qt::SolidLine, Qt::RoundCap));
        break;
    }
    }
    m_startingPoint = event->scenePos();
}
