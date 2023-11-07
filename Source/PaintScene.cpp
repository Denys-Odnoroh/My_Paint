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

void PaintScene::setLastElementIndex(int lastElementIndex)
{
    this->iLastElementIndex = lastElementIndex;
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

    switch (settings->getAction())
    {
    case Settings::DraggingObjectAction:
    {
        ((WorkSurfaceWidget*)this->parent())->setCursor(Qt::ClosedHandCursor);
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
                int startX = tempRect->getPosition().x();
                int startY = tempRect->getPosition().x();

                pGraphicsItem->setPos(startX + vector.x(), startY + vector.y());
                pGraphicsItem->setPosition(startX + vector.x(), startY + vector.y());
            }
        }
    }
    }
}

void PaintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (((WorkSurfaceWidget*)this->parent())->getCreator() != NULL)
        ((WorkSurfaceWidget*)this->parent())->getCreator()->mouseReleaseEvent(event);

    switch (settings->getAction())
    {
    case Settings::DraggingObjectAction:
    {
        ((WorkSurfaceWidget*)this->parent())->setCursor(Qt::OpenHandCursor);
    }
    }
}
