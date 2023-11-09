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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToolbarWidget
{
public:
    QToolButton *FileOperationButton;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QWidget *ColorIndIcator;
    QWidget *BackgroundColorIndIcator;
    QPushButton *ChangeBackgroundColorButton;
    QPushButton *ChangeColorButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *ObectsSelectionButton;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *ReDoButton;
    QPushButton *UnDoButton;
    QPushButton *ClearButton;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *gridLayout_2;
    QPushButton *EraserButton;
    QPushButton *PaintButton;
    QSpinBox *EraserSpinBox;
    QSpinBox *PaintSpinBox;
    QGridLayout *gridLayout_3;
    QPushButton *OvalButton;
    QPushButton *CircleButton;

    void setupUi(QWidget *ToolbarWidget)
    {
        if (ToolbarWidget->objectName().isEmpty())
            ToolbarWidget->setObjectName("ToolbarWidget");
        ToolbarWidget->setEnabled(true);
        ToolbarWidget->resize(850, 104);
        ToolbarWidget->setFocusPolicy(Qt::StrongFocus);
        ToolbarWidget->setLayoutDirection(Qt::RightToLeft);
        ToolbarWidget->setAutoFillBackground(false);
        FileOperationButton = new QToolButton(ToolbarWidget);
        FileOperationButton->setObjectName("FileOperationButton");
        FileOperationButton->setGeometry(QRect(10, 20, 51, 31));
        FileOperationButton->setCursor(QCursor(Qt::PointingHandCursor));
        layoutWidget = new QWidget(ToolbarWidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(520, 20, 299, 59));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(24, 0, 0, 0);
        ColorIndIcator = new QWidget(layoutWidget);
        ColorIndIcator->setObjectName("ColorIndIcator");
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

        gridLayout->addWidget(ColorIndIcator, 1, 1, 1, 1);

        BackgroundColorIndIcator = new QWidget(layoutWidget);
        BackgroundColorIndIcator->setObjectName("BackgroundColorIndIcator");
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

        gridLayout->addWidget(BackgroundColorIndIcator, 1, 2, 1, 1);

        ChangeBackgroundColorButton = new QPushButton(layoutWidget);
        ChangeBackgroundColorButton->setObjectName("ChangeBackgroundColorButton");
        ChangeBackgroundColorButton->setEnabled(true);
        ChangeBackgroundColorButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(ChangeBackgroundColorButton, 0, 2, 1, 1);

        ChangeColorButton = new QPushButton(layoutWidget);
        ChangeColorButton->setObjectName("ChangeColorButton");
        ChangeColorButton->setEnabled(true);
        ChangeColorButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(ChangeColorButton, 0, 1, 1, 1);

        layoutWidget1 = new QWidget(ToolbarWidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(70, 10, 301, 71));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        ObectsSelectionButton = new QPushButton(layoutWidget1);
        ObectsSelectionButton->setObjectName("ObectsSelectionButton");
        ObectsSelectionButton->setEnabled(true);
        ObectsSelectionButton->setBaseSize(QSize(0, 0));
        ObectsSelectionButton->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/Images/DottedSquare.png"), QSize(), QIcon::Normal, QIcon::Off);
        ObectsSelectionButton->setIcon(icon);

        horizontalLayout_2->addWidget(ObectsSelectionButton);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(12, -1, 12, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, -1, -1, 9);
        ReDoButton = new QPushButton(layoutWidget1);
        ReDoButton->setObjectName("ReDoButton");
        ReDoButton->setEnabled(true);
        ReDoButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(ReDoButton);

        UnDoButton = new QPushButton(layoutWidget1);
        UnDoButton->setObjectName("UnDoButton");
        UnDoButton->setEnabled(true);
        UnDoButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(UnDoButton);


        verticalLayout->addLayout(horizontalLayout);

        ClearButton = new QPushButton(layoutWidget1);
        ClearButton->setObjectName("ClearButton");
        ClearButton->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ClearButton->sizePolicy().hasHeightForWidth());
        ClearButton->setSizePolicy(sizePolicy);
        ClearButton->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(ClearButton);


        horizontalLayout_2->addLayout(verticalLayout);

        layoutWidget2 = new QWidget(ToolbarWidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(380, 20, 130, 63));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        EraserButton = new QPushButton(layoutWidget2);
        EraserButton->setObjectName("EraserButton");
        EraserButton->setEnabled(true);
        EraserButton->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/Images/EraserCursor.png"), QSize(), QIcon::Normal, QIcon::Off);
        EraserButton->setIcon(icon1);

        gridLayout_2->addWidget(EraserButton, 1, 2, 1, 1);

        PaintButton = new QPushButton(layoutWidget2);
        PaintButton->setObjectName("PaintButton");
        PaintButton->setEnabled(true);
        PaintButton->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/Images/BrushCursor.png"), QSize(), QIcon::Normal, QIcon::Off);
        PaintButton->setIcon(icon2);

        gridLayout_2->addWidget(PaintButton, 0, 2, 1, 1);

        EraserSpinBox = new QSpinBox(layoutWidget2);
        EraserSpinBox->setObjectName("EraserSpinBox");
        EraserSpinBox->setValue(10);

        gridLayout_2->addWidget(EraserSpinBox, 1, 1, 1, 1);

        PaintSpinBox = new QSpinBox(layoutWidget2);
        PaintSpinBox->setObjectName("PaintSpinBox");
        PaintSpinBox->setValue(3);

        gridLayout_2->addWidget(PaintSpinBox, 0, 1, 1, 1);


        horizontalLayout_3->addLayout(gridLayout_2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(9, -1, 9, -1);
        OvalButton = new QPushButton(layoutWidget2);
        OvalButton->setObjectName("OvalButton");
        OvalButton->setEnabled(true);
        OvalButton->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/Images/Oval.png"), QSize(), QIcon::Normal, QIcon::Off);
        OvalButton->setIcon(icon3);

        gridLayout_3->addWidget(OvalButton, 1, 0, 1, 1);

        CircleButton = new QPushButton(layoutWidget2);
        CircleButton->setObjectName("CircleButton");
        CircleButton->setEnabled(true);
        CircleButton->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/Images/Circle.png"), QSize(), QIcon::Normal, QIcon::Off);
        CircleButton->setIcon(icon4);

        gridLayout_3->addWidget(CircleButton, 0, 0, 1, 1);


        horizontalLayout_3->addLayout(gridLayout_3);


        retranslateUi(ToolbarWidget);

        QMetaObject::connectSlotsByName(ToolbarWidget);
    } // setupUi

    void retranslateUi(QWidget *ToolbarWidget)
    {
        ToolbarWidget->setWindowTitle(QCoreApplication::translate("ToolbarWidget", "Form", nullptr));
        FileOperationButton->setText(QCoreApplication::translate("ToolbarWidget", "File", nullptr));
        ChangeBackgroundColorButton->setText(QCoreApplication::translate("ToolbarWidget", "Background color", nullptr));
        ChangeColorButton->setText(QCoreApplication::translate("ToolbarWidget", "Select color", nullptr));
        ObectsSelectionButton->setText(QCoreApplication::translate("ToolbarWidget", "Rect selection", nullptr));
        ReDoButton->setText(QCoreApplication::translate("ToolbarWidget", "->", nullptr));
        UnDoButton->setText(QCoreApplication::translate("ToolbarWidget", "<-", nullptr));
        ClearButton->setText(QCoreApplication::translate("ToolbarWidget", "Clean", nullptr));
        EraserButton->setText(QString());
        PaintButton->setText(QString());
        OvalButton->setText(QString());
        CircleButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ToolbarWidget: public Ui_ToolbarWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLBARWIDGET_H
