#include <QCursor>
#include "ToolbarWidget.h"
#include "ui_ToolbarWidget.h"
#include "ui_WorkSurfaceWidget.h"

ToolbarWidget::ToolbarWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToolbarWidget)
{
    ui->setupUi(this);

    m_palette = new QPalette();
    ui->PaintButton->setAutoFillBackground(true);
    ui->EraserButton->setAutoFillBackground(true);
    ui->ColorIndicator->setAutoFillBackground(true);

    m_palette->setColor(QPalette::Button, Qt::black);
    ui->PaintButton->setPalette(*m_palette);

    m_colorDialog = new QColorDialog();
}

ToolbarWidget::~ToolbarWidget()
{
    delete ui;
}

void ToolbarWidget::setWorkSurfaceWidget(WorkSurfaceWidget *workSurfaceWidget)
{
    this->m_workSurfaceWidget = workSurfaceWidget;
}

void ToolbarWidget::setPaintScene(PaintScene *scene)
{
    this->m_scene = scene;
}

PaintScene ToolbarWidget::getPaintScene()
{
    return *m_scene;
}

void ToolbarWidget::on_ClearButton_clicked()
{
    m_workSurfaceWidget->getUI().graphicsView->scene()->clear();
}

void ToolbarWidget::on_EraserButton_clicked()
{
    m_palette->setColor(QPalette::Button, Qt::white);
    ui->PaintButton->setPalette(*m_palette);

    m_palette->setColor(QPalette::Button, Qt::black);
    ui->EraserButton->setPalette(*m_palette);

    m_pixmap = QPixmap(":/image/Images/EraserCursor.png");
    m_cursor = QCursor(m_pixmap);
    m_workSurfaceWidget->setCursor(m_cursor);

    m_scene->setDrawingFlag(false);
}

void ToolbarWidget::on_PaintButton_clicked()
{
    m_palette->setColor(QPalette::Button, Qt::white);
    ui->EraserButton->setPalette(*m_palette);

    m_palette->setColor(QPalette::Button, Qt::black);
    ui->PaintButton->setPalette(*m_palette);

    m_pixmap = QPixmap(":/image/Images/BrushCursor.png");
    m_cursor = QCursor(m_pixmap);
    m_workSurfaceWidget->setCursor(m_cursor);

    m_scene->setDrawingFlag(true);
}


void ToolbarWidget::on_PaintSpinBox_valueChanged(int size)
{
    m_scene->setBrushSize(size);
}


void ToolbarWidget::on_EraserSpinBox_valueChanged(int size)
{
    m_scene->setEraserSize(size);
}

void ToolbarWidget::on_ChangeColorButton_clicked()
{
    QColor color = QColorDialog::getColor(Qt::black, this);
    ui->ColorIndicator->setPalette(QPalette(color));
    m_scene->setDrawingColor(color);
}

