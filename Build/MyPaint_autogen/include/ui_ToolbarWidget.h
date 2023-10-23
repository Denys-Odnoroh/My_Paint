/********************************************************************************
** Form generated from reading UI file 'ToolbarWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLBARWIDGET_H
#define UI_TOOLBARWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToolbarWidget
{
public:
    QPushButton *EraserButton;
    QPushButton *ClearButton;
    QPushButton *PaintButton;
    QSpinBox *EraserSpinBox;
    QSpinBox *PaintSpinBox;
    QPushButton *ChangeColorButton;
    QWidget *ColorIndIcator;
    QToolButton *FileOperationButton;
    QWidget *BackgroundColorIndIcator;
    QPushButton *ChangeBackgroundColorButton;

    void setupUi(QWidget *ToolbarWidget)
    {
        if (ToolbarWidget->objectName().isEmpty())
            ToolbarWidget->setObjectName("ToolbarWidget");
        ToolbarWidget->setEnabled(true);
        ToolbarWidget->resize(1440, 95);
        ToolbarWidget->setFocusPolicy(Qt::StrongFocus);
        ToolbarWidget->setLayoutDirection(Qt::RightToLeft);
        ToolbarWidget->setAutoFillBackground(false);
        EraserButton = new QPushButton(ToolbarWidget);
        EraserButton->setObjectName("EraserButton");
        EraserButton->setEnabled(true);
        EraserButton->setGeometry(QRect(100, 10, 51, 41));
        EraserButton->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/Images/EraserCursor.png"), QSize(), QIcon::Normal, QIcon::Off);
        EraserButton->setIcon(icon);
        ClearButton = new QPushButton(ToolbarWidget);
        ClearButton->setObjectName("ClearButton");
        ClearButton->setEnabled(true);
        ClearButton->setGeometry(QRect(1270, 10, 51, 41));
        ClearButton->setCursor(QCursor(Qt::PointingHandCursor));
        PaintButton = new QPushButton(ToolbarWidget);
        PaintButton->setObjectName("PaintButton");
        PaintButton->setEnabled(true);
        PaintButton->setGeometry(QRect(20, 10, 51, 41));
        PaintButton->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/Images/BrushCursor.png"), QSize(), QIcon::Normal, QIcon::Off);
        PaintButton->setIcon(icon1);
        EraserSpinBox = new QSpinBox(ToolbarWidget);
        EraserSpinBox->setObjectName("EraserSpinBox");
        EraserSpinBox->setGeometry(QRect(100, 60, 51, 25));
        EraserSpinBox->setValue(10);
        PaintSpinBox = new QSpinBox(ToolbarWidget);
        PaintSpinBox->setObjectName("PaintSpinBox");
        PaintSpinBox->setGeometry(QRect(20, 60, 51, 25));
        PaintSpinBox->setValue(3);
        ChangeColorButton = new QPushButton(ToolbarWidget);
        ChangeColorButton->setObjectName("ChangeColorButton");
        ChangeColorButton->setEnabled(true);
        ChangeColorButton->setGeometry(QRect(510, 10, 105, 41));
        ChangeColorButton->setCursor(QCursor(Qt::PointingHandCursor));
        ColorIndIcator = new QWidget(ToolbarWidget);
        ColorIndIcator->setObjectName("ColorIndIcator");
        ColorIndIcator->setGeometry(QRect(510, 60, 105, 21));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush2(QColor(255, 255, 220, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        QBrush brush3(QColor(255, 255, 255, 127));
        brush3.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        QBrush brush4(QColor(0, 0, 0, 127));
        brush4.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        ColorIndIcator->setPalette(palette);
        ColorIndIcator->setContextMenuPolicy(Qt::NoContextMenu);
        ColorIndIcator->setAutoFillBackground(true);
        FileOperationButton = new QToolButton(ToolbarWidget);
        FileOperationButton->setObjectName("FileOperationButton");
        FileOperationButton->setGeometry(QRect(1350, 10, 51, 41));
        FileOperationButton->setCursor(QCursor(Qt::PointingHandCursor));
        BackgroundColorIndIcator = new QWidget(ToolbarWidget);
        BackgroundColorIndIcator->setObjectName("BackgroundColorIndIcator");
        BackgroundColorIndIcator->setGeometry(QRect(650, 60, 105, 21));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        BackgroundColorIndIcator->setPalette(palette1);
        BackgroundColorIndIcator->setContextMenuPolicy(Qt::NoContextMenu);
        BackgroundColorIndIcator->setAutoFillBackground(true);
        ChangeBackgroundColorButton = new QPushButton(ToolbarWidget);
        ChangeBackgroundColorButton->setObjectName("ChangeBackgroundColorButton");
        ChangeBackgroundColorButton->setEnabled(true);
        ChangeBackgroundColorButton->setGeometry(QRect(650, 10, 105, 41));
        ChangeBackgroundColorButton->setCursor(QCursor(Qt::PointingHandCursor));

        retranslateUi(ToolbarWidget);

        QMetaObject::connectSlotsByName(ToolbarWidget);
    } // setupUi

    void retranslateUi(QWidget *ToolbarWidget)
    {
        ToolbarWidget->setWindowTitle(QCoreApplication::translate("ToolbarWidget", "Form", nullptr));
        EraserButton->setText(QCoreApplication::translate("ToolbarWidget", "Erase", nullptr));
        ClearButton->setText(QCoreApplication::translate("ToolbarWidget", "Clean", nullptr));
        PaintButton->setText(QCoreApplication::translate("ToolbarWidget", "Paint", nullptr));
        ChangeColorButton->setText(QCoreApplication::translate("ToolbarWidget", "Select color", nullptr));
        FileOperationButton->setText(QCoreApplication::translate("ToolbarWidget", "File", nullptr));
        ChangeBackgroundColorButton->setText(QCoreApplication::translate("ToolbarWidget", "Background color", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ToolbarWidget: public Ui_ToolbarWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLBARWIDGET_H
