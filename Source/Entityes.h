#ifndef BASEENTITY_H
#define BASEENTITY_H

#include "QGraphicsItem"

class BaseEntity : public QGraphicsItem
{
protected:
    QPoint m_position;

public:
    BaseEntity();

    void setPosition(int x, int y) { m_position = QPoint(x, y); };
    QPoint getPosition() { return m_position; };
};

class CircleEntity : public BaseEntity
{
public:
    CircleEntity();
};

class LineEntity : public BaseEntity
{
public:
    LineEntity();
};

class RectangleEntity : public BaseEntity
{
public:
    RectangleEntity();
};

#endif // BASEENTITY_H
