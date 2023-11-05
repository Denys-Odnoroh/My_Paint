#ifndef BASEENTITY_H
#define BASEENTITY_H

#include "QGraphicsItem"

class BaseEntity : public QGraphicsItem
{
public:
    BaseEntity();

    void setPosition(int x, int y) { m_position = QPoint(x, y); };
    QPoint getPosition() { return m_position; };

protected:
    QPoint m_position;

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
