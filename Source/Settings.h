#ifndef SETTINGS_H
#define SETTINGS_H

#include <QBrush>
#include <QColor>

class Settings
{

public:
    enum SceneActions
    {
        EraseAction,
        BrushDrawingAction,
        OvalDrawingAction,
        CircleDrawingAction
    };

private:
    QColor m_backgroundColor;
    QColor m_drawingColor;
    int m_iActionIndex;
    int m_iEraserSize;
    int m_iBrushSize;

public:
    Settings();

    QColor getDrawingColor();
    QColor getBackgroundColor();
    int getAction();
    int getBrushSize();
    int getEraserSize();
    void setBrushSize(int size);
    void setEraserSize(int size);
    void setAction(SceneActions actionType);
    void setDrawingColor(QColor color);
    void setBackgroundColor(QColor color);
};

#endif // SETTINGS_H
