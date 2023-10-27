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
    ui->OvalButton->setAutoFillBackground(true);
    ui->CircleButton->setAutoFillBackground(true);
    ui->ColorIndIcator->setAutoFillBackground(true);
    ui->UnDoButton->setAutoFillBackground(true);
    ui->ReDoButton->setAutoFillBackground(true);
    ui->BackgroundColorIndIcator->setAutoFillBackground(true);

    ui->BackgroundColorIndIcator->setPalette(Qt::white);

    m_palette->setColor(QPalette::Button, Qt::black);
    ui->PaintButton->setPalette(*m_palette);

    m_colorDialog = new QColorDialog();

    QAction* SaveAsAction = new QAction("Save as...", this);
    QAction* LoadAction = new QAction("Load...", this);

    QObject::connect(SaveAsAction, SIGNAL(triggered()),
                     this, SLOT(saveAs()));
    QObject::connect(LoadAction, SIGNAL(triggered()),
                     this, SLOT(load()));

    QMenu *menu = new QMenu();
    menu->addAction(SaveAsAction);
    menu->addAction(LoadAction);
    this->ui->FileOperationButton->setMenu(menu);
    this->ui->FileOperationButton->setPopupMode(QToolButton::InstantPopup);
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

void ToolbarWidget::getOpenedImage(QPixmap &img)
{
    int iFrameThickness = 1;
    QPixmap temp = m_workSurfaceWidget->getUI().graphicsView->grab();
    QPoint position = m_workSurfaceWidget->getUI().graphicsView->pos();
    QSize size = temp.size();
    img = temp.copy(position.x() + iFrameThickness, position.y() + iFrameThickness,
                    size.width() - (iFrameThickness * 2), size.height() - (iFrameThickness * 2));
}

QPixmap ToolbarWidget::getSavedImage()
{
    QPixmap img;
    QString path = QFileDialog::getOpenFileName(this, "Save", QDir::rootPath(),
                                                "All supported file (*.jpg *.jpeg *png *bmp);;"
                                                "(*.jpg);;"
                                                "(*.jpeg);;"
                                                "(*.png);;"
                                                "(*.bmp)");
    img.load(path);

    return img;
}

void ToolbarWidget::saveAs()
{
    QPixmap img;
    this->getOpenedImage(img);
    QString path = QFileDialog::getSaveFileName(this, "Save", QDir::rootPath(), "(*.jpg);;"
                                                                                "(*.jpeg);;"
                                                                                "(*.png);;"
                                                                                "(*.bmp)");

    QString extencion = this->getfileExtencion(path);
    const char *cExtencion = extencion.toStdString().c_str();
    img.save(path, cExtencion);
}

QString ToolbarWidget::getfileExtencion(QString path)
{
    int pathSybmolsCount = path.size();
    int extencionSymbolsCount = 0;
    wchar_t* wcharArray = new wchar_t[pathSybmolsCount];
    path.toWCharArray(wcharArray);

    for(pathSybmolsCount -= 1; wcharArray[pathSybmolsCount] != '.'; pathSybmolsCount--)
        extencionSymbolsCount += 1;

    path.erase(path.begin(), path.end() - extencionSymbolsCount);
    QString extencion = path;

    return extencion;
}

void ToolbarWidget::load()
{
    QPixmap img = getSavedImage();
    m_workSurfaceWidget->getScene()->addPixmap(img);
}

void ToolbarWidget::on_ClearButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::warning(this, "Warning", "Do you want to clear the sheet?",
                                                             QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes)
    {
        m_workSurfaceWidget->getUI().graphicsView->scene()->clear();
    }
}

void ToolbarWidget::on_EraserButton_clicked()
{
    m_palette->setColor(QPalette::Button, Qt::white);
    ui->PaintButton->setPalette(*m_palette);
    ui->CircleButton->setPalette(*m_palette);
    ui->OvalButton->setPalette(*m_palette);

    m_palette->setColor(QPalette::Button, Qt::black);
    ui->EraserButton->setPalette(*m_palette);

    m_pixmap = QPixmap(":/image/Images/EraserCursor.png");
    m_cursor = QCursor(m_pixmap);
    m_workSurfaceWidget->setCursor(m_cursor);

    m_scene->getSettings()->setAction(Settings::EraseAction);
}

void ToolbarWidget::on_PaintButton_clicked()
{
    m_palette->setColor(QPalette::Button, Qt::white);
    ui->EraserButton->setPalette(*m_palette);
    ui->CircleButton->setPalette(*m_palette);
    ui->OvalButton->setPalette(*m_palette);

    m_palette->setColor(QPalette::Button, Qt::black);
    ui->PaintButton->setPalette(*m_palette);

    m_pixmap = QPixmap(":/image/Images/BrushCursor.png");
    m_cursor = QCursor(m_pixmap);
    m_workSurfaceWidget->setCursor(m_cursor);

    m_scene->getSettings()->setAction(Settings::BrushDrawingAction);
}


void ToolbarWidget::on_PaintSpinBox_valueChanged(int size)
{
    m_scene->getSettings()->setBrushSize(size);
}


void ToolbarWidget::on_EraserSpinBox_valueChanged(int size)
{
    m_scene->getSettings()->setEraserSize(size);
}

void ToolbarWidget::on_ChangeColorButton_clicked()
{
    QColor color = QColorDialog::getColor(Qt::black, this);
    ui->ColorIndIcator->setPalette(QPalette(color));
    m_scene->getSettings()->setDrawingColor(color);
}

void ToolbarWidget::on_ChangeBackgroundColorButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::warning(this, "Warning",
                                                             "Before changing background color, you need to clean the sheet. Confirm?",
                                                             QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes)
    {
        m_workSurfaceWidget->getUI().graphicsView->scene()->clear();
        QColor color = QColorDialog::getColor(Qt::white, this);
        ui->BackgroundColorIndIcator->setPalette(QPalette(color));
        m_scene->getSettings()->setBackgroundColor(color);
        m_scene->setBackgroundBrush(color);
    }
}

void ToolbarWidget::on_OvalButton_clicked()
{
    m_palette->setColor(QPalette::Button, Qt::white);
    ui->EraserButton->setPalette(*m_palette);
    ui->PaintButton->setPalette(*m_palette);
    ui->CircleButton->setPalette(*m_palette);

    m_palette->setColor(QPalette::Button, Qt::black);
    ui->OvalButton->setPalette(*m_palette);

    m_pixmap = QPixmap(":/image/Images/BrushCursor.png");
    m_cursor = QCursor(m_pixmap);
    m_workSurfaceWidget->setCursor(m_cursor);

    m_scene->getSettings()->setAction(Settings::OvalDrawingAction);
}

void ToolbarWidget::on_CircleButton_clicked()
{
    m_palette->setColor(QPalette::Button, Qt::white);
    ui->EraserButton->setPalette(*m_palette);
    ui->PaintButton->setPalette(*m_palette);
    ui->OvalButton->setPalette(*m_palette);

    m_palette->setColor(QPalette::Button, Qt::black);
    ui->CircleButton->setPalette(*m_palette);

    m_pixmap = QPixmap(":/image/Images/BrushCursor.png");
    m_cursor = QCursor(m_pixmap);
    m_workSurfaceWidget->setCursor(m_cursor);

    m_scene->getSettings()->setAction(Settings::CircleDrawingAction);
}

void ToolbarWidget::on_ReDoButton_clicked()
{
    if(!m_scene->getGraphicsItemsList().empty() && m_scene->getLastElementIndex() != m_scene->getGraphicsItemsList().size())
    {
        m_scene->setLastElementIndex(m_scene->getLastElementIndex() + 1);
        DravableElementArray aDrawableElem = m_scene->getGraphicsItemsList().at(m_scene->getLastElementIndex() - 1);

        for(QGraphicsItem* pGraphicsItem : aDrawableElem)
        {
            m_scene->addItem(pGraphicsItem);
        }
    }
}

void ToolbarWidget::on_UnDoButton_clicked()
{
    if(!m_scene->getGraphicsItemsList().empty() && m_scene->getLastElementIndex() != 0)
    {
        DravableElementArray aDrawableElem = m_scene->getGraphicsItemsList().at(m_scene->getLastElementIndex() - 1);

        for(QGraphicsItem* pGraphicsItem : aDrawableElem)
        {
            m_scene->removeItem(pGraphicsItem);
        }
        m_scene->setLastElementIndex(m_scene->getLastElementIndex() - 1);
    }
}
