#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class PaintScene : public QGraphicsScene
{
    Q_OBJECT

private:
    QColor m_drawingColor;
    QPointF m_startingPoint;
    bool m_bDrawingFlag;
    int m_iEraserSize;
    int m_iBrushSize;

public:
    PaintScene();
    PaintScene(PaintScene& scene);
    ~PaintScene();

    bool getDrawingFlag();
    QColor getDrawingColor();
    void setBrushSize(int size);
    void setEraserSize(int size);
    void setDrawingFlag(bool flag);
    void setDrawingColor(QColor color);
    void setStartingPoint(QPointF startingPoint);
    QPointF getStartingPoint();

private:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // PAINTSCENE_H
