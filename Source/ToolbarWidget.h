#ifndef TOOLBARWIDGET_H
#define TOOLBARWIDGET_H

#include <QMainWindow>
#include <QColorDialog>
#include <QCursor>
#include <QMenu>
#include <QScreen>
#include <QFileDialog>
#include <QMessageBox>
#include <vector>
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

private:
    void getOpenedImage(QPixmap &img);
    QPixmap getSavedImage();
    QString getfileExtencion(QString path);

public slots:
    void saveAs();
    void load();

private slots:
    void on_ClearButton_clicked();
    void on_EraserButton_clicked();
    void on_PaintButton_clicked();
    void on_PaintSpinBox_valueChanged(int size);
    void on_EraserSpinBox_valueChanged(int size);
    void on_ChangeColorButton_clicked();
    void on_ChangeBackgroundColorButton_clicked();
    void on_CircleButton_clicked();
    void on_OvalButton_clicked();
    void on_ReDoButton_clicked();
    void on_UnDoButton_clicked();
};

#endif // TOOLBARWIDGET_H
