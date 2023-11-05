#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsEllipseItem>
#include <list>
#include <vector>
#include <memory>
#include "Settings.h"
#include "Entityes.h"

typedef std::vector<BaseEntity*> DravableElementArray;


class PaintScene : public QGraphicsScene
{
    Q_OBJECT

private:
    QPointF start;
    Settings* settings;
    std::vector<DravableElementArray> m_graphicsItems;
    std::vector<DravableElementArray> m_selectedObjects;
    int iLastElementIndex = 0;

public:
    PaintScene(QWidget *parent = nullptr);
    PaintScene(PaintScene& scene);
    ~PaintScene();

    std::vector<DravableElementArray> *getGraphicsItemsList();
    std::vector<DravableElementArray> *getSelectedObjects();
    Settings* getSettings();
    int getLastElementIndex();
    void setLastElemIndex(int index);
    void setSettings(Settings* settings);
    void setLastElementIndex(int lastElementIndex);

private:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // PAINTSCENE_H
