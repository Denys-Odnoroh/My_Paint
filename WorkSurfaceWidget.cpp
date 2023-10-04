#include <QOpenGLFunctions>
#include <QPalette>
#include "ui_WorkSurfaceWidget.h"
#include "WorkSurfaceWidget.h"

WorkSurfaceWidget::WorkSurfaceWidget(QWidget *parent) : QOpenGLWidget(parent), ui(new Ui::WorkSurfaceWidget)
{
    scene = new PaintScene;

    ui->setupUi(this);
    ui->graphicsView->setScene(scene);

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &WorkSurfaceWidget::slotTimer);
    timer->start(100);
}

WorkSurfaceWidget::~WorkSurfaceWidget()
{
    delete ui;
}

void WorkSurfaceWidget::resizeEvent(QResizeEvent *resizeEvent)
{
    timer->start(100);
    QOpenGLWidget::resizeEvent(resizeEvent);
    QSize size = this->size();
}

Ui::WorkSurfaceWidget WorkSurfaceWidget::getUI()
{
    if(scene != NULL)
    {
        return *ui;
    }
}

PaintScene* WorkSurfaceWidget::getScene()
{
    return scene;
}

void WorkSurfaceWidget::initializeGL()
{
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glClearColor(0.75, 0.75, 0.75, 1.0);
}

void WorkSurfaceWidget::resizeGL(int weight, int height)
{
    QOpenGLWidget::resizeGL(weight, height);
}

void WorkSurfaceWidget::paintGL()
{

}

void WorkSurfaceWidget::slotTimer()
{
    timer->stop();
    scene->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
}

