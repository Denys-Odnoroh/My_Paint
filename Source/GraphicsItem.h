#ifndef GRAPHICSITEM_H
#define GRAPHICSITEM_H

#include <QGraphicsItem>
#include <QCursor>
#include <QGraphicsSceneEvent>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsEllipseItem>
#include <list>
#include <vector>
#include <memory>
#include "Settings.h"

class GraphicsItem;

class GraphicsItem : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    Settings* settings;
    QPointF m_startingPoint;
    QPointF *start;
    QGraphicsEllipseItem *m_tempCircle;
    QGraphicsRectItem *m_tempRectangle;
    int iLastElementIndex = 0;

public:
    GraphicsItem(Settings *settings, QPointF startingPoint, QObject *parent = 0);
    ~GraphicsItem();

    QPointF getStartingPoint();
    Settings* getSettings();
    int getLastElementIndex();
    void setSettings(Settings* settings);
    void setStartingPoint(QPointF startingPoint);
    void setLastElementIndex(int lastElementIndex);


    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // GRAPHICSITEM_H
