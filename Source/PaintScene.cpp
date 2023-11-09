#include "PaintScene.h"
#include "WorkSurfaceWidget.h"

using namespace std;

PaintScene::PaintScene(QWidget *parent)
{

}

PaintScene::PaintScene(PaintScene &scene)
{

}

PaintScene::~PaintScene()
{

}

std::vector<ObjectChangeHistory *> *PaintScene::getHistory()
{
    return &m_history;
}

std::vector<DravableElementArray> *PaintScene::getGraphicsItemsList()
{
    return &m_graphicsItems;
}

std::vector<DravableElementArray> *PaintScene::getSelectedObjects()
{
    return &m_selectedObjects;
}

void PaintScene::setSettings(Settings *settings)
{
    this->settings = settings;
}

void PaintScene::setLastElementIndex(int index)
{
    this->iLastElementIndex += index;
}

Settings *PaintScene::getSettings()
{
    return settings;
}

int PaintScene::getLastElementIndex()
{
    return iLastElementIndex;
}

void PaintScene::setLastElemIndex(int index)
{
    this->iLastElementIndex += index;
}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && ((WorkSurfaceWidget*)this->parent())->getCreator() != NULL)
        ((WorkSurfaceWidget*)this->parent())->getCreator()->mousePressEvent(event);

    for(int i = iLastElementIndex; iLastElementIndex < m_graphicsItems.size(); ++i)
    {
        m_graphicsItems.pop_back();
    }

    for(int i = iChangeHistoryIndex; iChangeHistoryIndex < m_history.size(); ++i)
    {
        m_history.pop_back();
    }

    switch (settings->getAction())
    {
    case Settings::DraggingObjectAction:
    {
        ((WorkSurfaceWidget*)this->parent())->setCursor(Qt::ClosedHandCursor);

        break;
    }
    }
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (((WorkSurfaceWidget*)this->parent())->getCreator() != NULL)
        ((WorkSurfaceWidget*)this->parent())->getCreator()->mouseMoveEvent(event);

    switch (settings->getAction())
    {
    case Settings::DraggingObjectAction:
    {
        RectangleEntity *tempRect = ((WorkSurfaceWidget*)this->parent())->getCreator()->getRectangle();
        start = ((WorkSurfaceWidget*)this->parent())->getCreator()->getStartingPoint();
        QPointF currentPoint = event->scenePos();
        QPointF vector(currentPoint.x() - start.x(), currentPoint.y() - start.y());

        for(DravableElementArray &aDrawableElem : this->m_selectedObjects)
        {
            for (BaseEntity* pGraphicsItem : aDrawableElem)
            {
                pGraphicsItem->setPos(start.x() - 150 + vector.x(), start.y() - 50 + vector.y());
                pGraphicsItem->setPosition(start.x() - 150 + vector.x(), start.y() - 50 + vector.y());
            }
        }
        break;
    }
    }
}

void PaintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    switch (settings->getAction())
    {
    case Settings::DraggingObjectAction:
    {
        for (int i = 0; i < m_selectedObjects.size(); ++i)
        {
            std::vector<QPointF> newPoints;
            std::vector<QPointF> points;

            for (int j = 0; j < m_selectedObjects[i].size(); ++j)
            {
                newPoints.push_back(m_selectedObjects[i][j]->getPosition());
                points.push_back(QPointF(0, 0));
            }
            ObjectChangeHistory *object = new ObjectChangeHistory(false, m_selectedObjects[i], points, newPoints);
            m_history.push_back(object);
        }

        iChangeHistoryIndex++;

        ((WorkSurfaceWidget*)this->parent())->setCursor(Qt::OpenHandCursor);

        break;
    }
    }

    if (((WorkSurfaceWidget*)this->parent())->getCreator() != NULL)
        ((WorkSurfaceWidget*)this->parent())->getCreator()->mouseReleaseEvent(event);
}
