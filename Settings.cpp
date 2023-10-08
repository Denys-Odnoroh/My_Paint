#include "Settings.h"

Settings::Settings()
{
    m_bDrawingFlag = true;
    m_drawingColor = Qt::black;
    m_backgroundBrush = Qt::white;
    m_iBrushSize = 3;
    m_iEraserSize = 10;
}

QColor Settings::getDrawingColor()
{
    return m_drawingColor;
}

QColor Settings::getBackgroundBrush()
{
    return m_backgroundBrush;
}

int Settings::getBrushSize()
{
    return m_iBrushSize;
}

int Settings::getEraserSize()
{
    return m_iEraserSize;
}

bool Settings::getDrawingFlag()
{
    return this->m_bDrawingFlag;
}

void Settings::setBrushSize(int size)
{
    if(size > 0 && size < 100)
    {
        this->m_iBrushSize = size;
    }
}

void Settings::setEraserSize(int size)
{
    if(size > 0 && size < 100)
    {
        this->m_iEraserSize = size;
    }
}

void Settings::setDrawingFlag(bool flag)
{
    if(flag == 0 || flag == 1)
    {
        this->m_bDrawingFlag = flag;
    }
}

void Settings::setDrawingColor(QColor color)
{
    if(color != nullptr)
    {
        this->m_drawingColor = color;
    }
}

void Settings::setBackgroundBrush(QBrush brush)
{
    this->m_backgroundBrush = brush.color();
}
