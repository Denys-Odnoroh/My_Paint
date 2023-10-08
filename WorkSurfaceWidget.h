#ifndef WORKSURFACEWIDGET_H
#define WORKSURFACEWIDGET_H

#include <QOpenGLWidget>
#include <QPainter>
#include <QTimer>
#include "PaintScene.h"
#include "Settings.h"

namespace Ui
{
class WorkSurfaceWidget;
}

class WorkSurfaceWidget : public QOpenGLWidget
{
    Q_OBJECT

private:
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

private:
    virtual void resizeEvent(QResizeEvent *resizeEvent) override;  

protected:
    virtual void initializeGL() override;
    virtual void resizeGL(int weight, int height) override;
    virtual void paintGL() override;

private slots:
    void slotTimer();
};

#endif // WORKSURFACEWIDGET_H
