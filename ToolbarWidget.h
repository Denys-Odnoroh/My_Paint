#ifndef TOOLBARWIDGET_H
#define TOOLBARWIDGET_H

#include <QMainWindow>
#include <QColorDialog>
#include "WorkSurfaceWidget.h"
#include "PaintScene.h"

namespace Ui {
class ToolbarWidget;
}

class ToolbarWidget : public QWidget
{
    Q_OBJECT

private:
    QCursor m_cursor;
    QPixmap m_pixmap;
    Ui::ToolbarWidget *ui;
    WorkSurfaceWidget *m_workSurfaceWidget;
    PaintScene *m_scene;
    QPalette *m_palette;
    QColorDialog *m_colorDialog;

public:
    explicit ToolbarWidget(QWidget *parent = nullptr);
    ~ToolbarWidget();

    void setWorkSurfaceWidget(WorkSurfaceWidget *workSurfaceWidget);
    void setPaintScene(PaintScene *scene);
    PaintScene getPaintScene();

private slots:
    void on_ClearButton_clicked();
    void on_EraserButton_clicked();
    void on_PaintButton_clicked();
    void on_PaintSpinBox_valueChanged(int size);
    void on_EraserSpinBox_valueChanged(int size);
    void on_ChangeColorButton_clicked();
};

#endif // TOOLBARWIDGET_H
