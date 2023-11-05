#ifndef WORKSURFACEWIDGET_H
#define WORKSURFACEWIDGET_H

#include <QOpenGLWidget>
#include <QPainter>
#include <QTimer>
#include "PaintScene.h"
#include "Settings.h"
#include "BaseCreator.h"
#include "CircleCreator.h"
#include "CurveCreator.h"
#include "RectangleCreator.h"
namespace Ui
{
class WorkSurfaceWidget;
}

class WorkSurfaceWidget : public QWidget
{
    Q_OBJECT

private:
    BaseCreator* m_creator;
    Settings *m_settings;
    QTimer *timer;
    PaintScene *scene;
    Ui::WorkSurfaceWidget *ui;

public:
    explicit WorkSurfaceWidget(QWidget *parent);
    ~WorkSurfaceWidget();

public:
    Ui::WorkSurfaceWidget getUI();
    PaintScene* getScene();
    Settings* getSettings();
    BaseCreator *getCreator();
    void setCreator();

private:
    virtual void resizeEvent(QResizeEvent *resizeEvent) override;  

public:
    virtual void resize(int weight, int height);

private slots:
    void slotTimer();
};

#endif // WORKSURFACEWIDGET_H
