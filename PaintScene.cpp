#include "PaintScene.h"

PaintScene::PaintScene()
{
    m_bDrawingFlag = true;
    m_iEraserSize = 10;
    m_iBrushSize = 3;
}

PaintScene::PaintScene(PaintScene &scene)
{
    scene.setStartingPoint(this->getStartingPoint());
    scene.setDrawingFlag(this->getDrawingFlag());
}

PaintScene::~PaintScene()
{

}

 QColor PaintScene::getDrawingColor()
{
    return m_drawingColor;
}

bool PaintScene::getDrawingFlag()
{
    return this->m_bDrawingFlag;
}

void PaintScene::setBrushSize(int size)
{
    if(size > 0 && size < 100)
    {
        this->m_iBrushSize = size;
    }
}

void PaintScene::setEraserSize(int size)
{
    if(size > 0 && size < 100)
    {
        this->m_iEraserSize = size;
    }
}

void PaintScene::setDrawingFlag(bool flag)
{
    if(flag == 0 || flag == 1)
    {
        this->m_bDrawingFlag = flag;
    }
}

void PaintScene::setDrawingColor(QColor color)
{
    if(color != nullptr)
    {
        this->m_drawingColor = color;
    }
}

void PaintScene::setStartingPoint(QPointF startingPoint)
{
    this->m_startingPoint = startingPoint;
}

QPointF PaintScene::getStartingPoint()
{
    return m_startingPoint;
}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    m_startingPoint = event->scenePos();

    switch (m_bDrawingFlag)
    {
    case 0:
    {
        addEllipse(event->scenePos().x(), event->scenePos().y(),
                   m_iEraserSize, m_iEraserSize, QPen(Qt::NoPen), QBrush(Qt::white));
        break;
    }
    case 1:
    {
        addEllipse(event->scenePos().x(), event->scenePos().y(),
                   m_iBrushSize, m_iBrushSize, QPen(Qt::NoPen), QBrush(this->getDrawingColor()));
        break;
    }
    }
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    switch (m_bDrawingFlag)
    {
    case 0:
    {
        addLine(m_startingPoint.x(), m_startingPoint.y(),
                event->scenePos().x(), event->scenePos().y(),
                QPen(Qt::white, m_iEraserSize, Qt::SolidLine, Qt::RoundCap));
        break;
    }
    case 1:
    {
        addLine(m_startingPoint.x(), m_startingPoint.y(),
                event->scenePos().x(), event->scenePos().y(),
                QPen(this->getDrawingColor(), m_iBrushSize, Qt::SolidLine, Qt::RoundCap));
        break;
    }
    }
    m_startingPoint = event->scenePos();
}
