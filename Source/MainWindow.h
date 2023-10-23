#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QPalette>
#include "WorkSurfaceWidget.h"
#include "ToolbarWidget.h"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

private:
    QCursor m_cursor;
    QPixmap m_pixmap;
    QGridLayout *m_layout;
    Ui::MainWindow *ui;
    WorkSurfaceWidget *m_workSurface;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    virtual void resizeEvent(QResizeEvent *resizeEvent) override;
};

#endif // MAINWINDOW_H
