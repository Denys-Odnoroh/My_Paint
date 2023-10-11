#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "Settings.h"

class PaintScene : public QGraphicsScene
{
    Q_OBJECT

private:
    Settings* settings;
    QPointF m_startingPoint;

public:
    PaintScene();
    PaintScene(PaintScene& scene);
    ~PaintScene();

    QPointF getStartingPoint();
    Settings* getSettings();
    void setSettings(Settings* settings);
    void setStartingPoint(QPointF startingPoint);

private:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // PAINTSCENE_H
