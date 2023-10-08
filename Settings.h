#ifndef SETTINGS_H
#define SETTINGS_H

#include <QBrush>
#include <QColor>

class Settings
{
private:
    QColor m_backgroundBrush;
    QColor m_drawingColor;
    bool m_bDrawingFlag;
    int m_iEraserSize;
    int m_iBrushSize;
public:
    Settings();

    bool getDrawingFlag();
    QColor getDrawingColor();
    QColor getBackgroundBrush();
    int getBrushSize();
    int getEraserSize();
    void setBrushSize(int size);
    void setEraserSize(int size);
    void setDrawingFlag(bool flag);
    void setDrawingColor(QColor color);
    void setBackgroundBrush(QBrush brush);
};

#endif // SETTINGS_H
