#include "Settings.h"

Settings::Settings()
{
    m_iActionIndex = 1;
    m_drawingColor = Qt::black;
    m_backgroundColor = Qt::white;
    m_iBrushSize = 3;
    m_iEraserSize = 10;
}

QColor Settings::getDrawingColor()
{
    return m_drawingColor;
}

QColor Settings::getBackgroundColor()
{
    return m_backgroundColor;
}

int Settings::getBrushSize()
{
    return m_iBrushSize;
}

int Settings::getEraserSize()
{
    return m_iEraserSize;
}

int Settings::getAction()
{
    return this->m_iActionIndex;
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

void Settings::setAction(SceneActions actionType)
{
    if(actionType >= 0)
    {
        this->m_iActionIndex = actionType;
    }
}

void Settings::setDrawingColor(QColor color)
{
    if(color != nullptr)
    {
        this->m_drawingColor = color;
    }
}

void Settings::setBackgroundColor(QColor color)
{
    if(color != nullptr)
    {
        this->m_backgroundColor = color;
    }
}
