#include "ui_MainWindow.h"
#include "MainWindow.h"
#include "QSettings"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Drawer");
    m_workSurface = new WorkSurfaceWidget(this);
    m_workSurface->setFixedSize(1440, 810);

    //QSettings regSettings("MyPaint");
    //int val = regSettings.value("testValue").toInt();
    //regSettings.setValue("testValue", 12);

    ToolbarWidget *upperToolbar = new ToolbarWidget(this);
    upperToolbar->setWorkSurfaceWidget(this->m_workSurface);
    upperToolbar->setFixedHeight(150);
    upperToolbar->setPaintScene(m_workSurface->getScene());

    QPalette palette = QPalette();
    palette.setColor(QPalette::Window, Qt::white);
    upperToolbar->setAutoFillBackground(true);
    upperToolbar->setPalette(palette);
    palette.setColor(QPalette::Window, Qt::lightGray);
    this->setAutoFillBackground(true);
    this->setPalette(palette);

    ui->horizontalLayout->addWidget(upperToolbar, 1);
    ui->verticalLayout->addWidget(m_workSurface, 1);

    m_pixmap = QPixmap("./BrushCursor.png");
    m_cursor = QCursor(m_pixmap);
    m_workSurface->setCursor(m_cursor);
}

void MainWindow::resizeEvent(QResizeEvent *resizeEvent)
{
    ui->verticalLayoutWidget->resize(this->size());

    QSize size = this->size();
    QWidget::resizeEvent(resizeEvent);
    if (m_workSurface != nullptr)
        m_workSurface->resize(this->size().width(), this->size().height());
}

MainWindow::~MainWindow()
{
    delete ui;
}
