#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsEllipseItem>
#include <list>
#include <vector>
#include <memory>
#include "Settings.h"

typedef std::vector<QGraphicsItem*> DravableElementArray;


class PaintScene : public QGraphicsScene
{
    Q_OBJECT

private:
    Settings* settings;
    QPointF m_startingPoint;
    QPointF *start;
    QGraphicsEllipseItem *m_tempCircle;
    std::vector<DravableElementArray> m_graphicsItems;
    DravableElementArray m_aDrawableElement;
    int iLastElementIndex = 0;

public:
    PaintScene();
    PaintScene(PaintScene& scene);
    ~PaintScene();

    std::vector<DravableElementArray> getGraphicsItemsList();
    QPointF getStartingPoint();
    Settings* getSettings();
    int getLastElementIndex();
    void setSettings(Settings* settings);
    void setStartingPoint(QPointF startingPoint);
    void setLastElementIndex(int lastElementIndex);

private:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // PAINTSCENE_H
