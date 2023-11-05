#include <QPalette>
#include "ui_WorkSurfaceWidget.h"
#include "WorkSurfaceWidget.h"
#include "QMouseEvent"

WorkSurfaceWidget::WorkSurfaceWidget(QWidget *parent) : QWidget(parent), ui(new Ui::WorkSurfaceWidget)
{
    scene = new PaintScene(this);
    scene->setParent(this);

    scene->setSceneRect(0, 0, this->width(), this->height());
    ui->setupUi(this);


    ui->graphicsView->setScene(scene);
    ui->graphicsView->setSceneRect(this->pos().x(), this->pos().y(), this->width(), this->height());

    m_settings = new Settings();
    m_settings->setBackgroundColor(Qt::white);
    scene->setSettings(m_settings);

    m_creator = new CurveCreator(scene);

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &WorkSurfaceWidget::slotTimer);
    timer->start(100);

    QPalette palette(QColor(250, 250, 250));
    this->setAutoFillBackground(true);
    this->setPalette(palette);
}

WorkSurfaceWidget::~WorkSurfaceWidget()
{
    delete ui;
}

void WorkSurfaceWidget::resizeEvent(QResizeEvent *resizeEvent)
{
    timer->start(100);
    QWidget::resizeEvent(resizeEvent);
    QSize size = this->size();
}

Ui::WorkSurfaceWidget WorkSurfaceWidget::getUI()
{
    if(scene != nullptr)
    {
        return *ui;
    }
}

PaintScene* WorkSurfaceWidget::getScene()
{
    return scene;
}

Settings* WorkSurfaceWidget::getSettings()
{
    return m_settings;
}

BaseCreator *WorkSurfaceWidget::getCreator()
{
    return m_creator;
}

void WorkSurfaceWidget::setCreator()
{
    switch (m_settings->getAction()) {
    case Settings::EraseAction:
    {
        CurveCreator* creator = new CurveCreator(scene);
        m_creator = creator;

        break;
    }
    case Settings::BrushDrawingAction:
    {
        CurveCreator* creator = new CurveCreator(scene);
        m_creator = creator;

        break;
    }
    case Settings::CircleDrawingAction:
    {
        CircleCreator* creator = new CircleCreator(scene);
        m_creator = creator;

        break;
    }
    case Settings::OvalDrawingAction:
    {
        CircleCreator* creator = new CircleCreator(scene);
        m_creator = creator;

        break;
    }
    case Settings::ObjectsSelectionAction:
    {
        RectangleCreator* creator = new RectangleCreator(scene);
        m_creator = creator;

        break;
    }
    }
}

void WorkSurfaceWidget::resize(int weight, int height)
{
    QWidget::resize(weight, height);
    ui->graphicsView->resize(weight, height);
    scene->setSceneRect(0, 0, weight, height);
}

void WorkSurfaceWidget::slotTimer()
{
    timer->stop();
    scene->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
}
