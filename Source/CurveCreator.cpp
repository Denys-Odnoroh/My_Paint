#include "CurveCreator.h"


QPointF CurveCreator::getStartingPoint()
{
    return m_startingPoint;
}

void CurveCreator::setStartingPoint(QPointF startingPoint)
{
    this->m_startingPoint = startingPoint;
}

CurveCreator::CurveCreator(PaintScene* scene) : BaseCreator(scene)
{
    m_settings = m_scene->getSettings();
}

CurveCreator::~CurveCreator()
{

}

void CurveCreator::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setStartingPoint(event->scenePos());

    switch (m_settings->getAction())
    {
    case Settings::EraseAction:
    {
        QGraphicsItem *ellipse = m_scene->addEllipse(m_startingPoint.x() - (m_settings->getEraserSize()/2),
                                            m_startingPoint.y() - (m_settings->getEraserSize()/2),
                                            m_settings->getEraserSize(), m_settings->getEraserSize(),
                                            QPen(Qt::NoPen), QBrush(m_settings->getBackgroundColor()));

        ellipse->setPos(m_startingPoint.x(), m_startingPoint.y());
        LineEntity* line = static_cast<LineEntity*>(ellipse);

        line->setPosition(m_startingPoint.x(), m_startingPoint.y());

        aCurveElem.push_back(line);

        break;
    }
    case Settings::BrushDrawingAction:
    {
        QGraphicsItem *ellipse = m_scene->addEllipse(m_startingPoint.x() - (m_settings->getBrushSize()/2),
                                            m_startingPoint.y() - (m_settings->getBrushSize()/2),
                                            m_settings->getBrushSize(), m_settings->getBrushSize(),
                                            QPen(Qt::NoPen), QBrush(m_settings->getDrawingColor()));

        LineEntity* line = static_cast<LineEntity*>(ellipse);

        line->setPosition(m_startingPoint.x(), m_startingPoint.y());

        aCurveElem.push_back(line);

        break;
    }

    }
}

void CurveCreator::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF currentPos = event->scenePos();
    switch (m_settings->getAction())
    {
    case Settings::EraseAction:
    {
        QGraphicsItem *lineItem = m_scene->addLine(m_startingPoint.x(), m_startingPoint.y(),
                                      event->scenePos().x(), event->scenePos().y(),
                                      QPen(m_settings->getBackgroundColor(), m_settings->getEraserSize(),
                                      Qt::SolidLine, Qt::RoundCap));

        LineEntity* line = static_cast<LineEntity*>(lineItem);
        aCurveElem.push_back(line);

        m_startingPoint = event->scenePos();
        break;
    }
    case Settings::BrushDrawingAction:
    {
        QGraphicsItem *lineItem = m_scene->addLine(m_startingPoint.x(), m_startingPoint.y(),
                                      event->scenePos().x(), event->scenePos().y(),
                                      QPen(m_settings->getDrawingColor(), m_settings->getBrushSize(),
                                      Qt::SolidLine, Qt::RoundCap));

        LineEntity* line = static_cast<LineEntity*>(lineItem);
        aCurveElem.push_back(line);

        m_startingPoint = event->scenePos();
        break;
    }
    }
}

void CurveCreator::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(!aCurveElem.empty())
    {
        std::vector<BaseEntity*> base;
        base.reserve(aCurveElem.size());

        for (int i = 0; i < aCurveElem.size(); ++i)
        {
            base.push_back(dynamic_cast<BaseEntity*>(aCurveElem[i]));
            base.back()->getPosition() = aCurveElem[i]->getPosition();
        }

        m_scene->getGraphicsItemsList()->push_back(base);
        m_scene->setLastElemIndex(1);
        aCurveElem.clear();
    }
}
