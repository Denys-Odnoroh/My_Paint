/********************************************************************************
** Form generated from reading UI file 'WorkSurfaceWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKSURFACEWIDGET_H
#define UI_WORKSURFACEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WorkSurfaceWidget
{
public:
    QGraphicsView *graphicsView;

    void setupUi(QWidget *WorkSurfaceWidget)
    {
        if (WorkSurfaceWidget->objectName().isEmpty())
            WorkSurfaceWidget->setObjectName("WorkSurfaceWidget");
        WorkSurfaceWidget->resize(1440, 730);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WorkSurfaceWidget->sizePolicy().hasHeightForWidth());
        WorkSurfaceWidget->setSizePolicy(sizePolicy);
        WorkSurfaceWidget->setLayoutDirection(Qt::LeftToRight);
        graphicsView = new QGraphicsView(WorkSurfaceWidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, 0, 1440, 730));
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::NoBrush);
        graphicsView->setBackgroundBrush(brush);
        graphicsView->setSceneRect(QRectF(0, 0, 0, 0));

        retranslateUi(WorkSurfaceWidget);

        QMetaObject::connectSlotsByName(WorkSurfaceWidget);
    } // setupUi

    void retranslateUi(QWidget *WorkSurfaceWidget)
    {
        WorkSurfaceWidget->setWindowTitle(QCoreApplication::translate("WorkSurfaceWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WorkSurfaceWidget: public Ui_WorkSurfaceWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKSURFACEWIDGET_H
