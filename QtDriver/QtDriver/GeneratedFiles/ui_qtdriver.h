/********************************************************************************
** Form generated from reading UI file 'qtdriver.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTDRIVER_H
#define UI_QTDRIVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtDriverClass
{
public:
    QWidget *centralWidget;
    QPushButton *exit_button;
    QOpenGLWidget *openGLWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtDriverClass)
    {
        if (QtDriverClass->objectName().isEmpty())
            QtDriverClass->setObjectName(QStringLiteral("QtDriverClass"));
        QtDriverClass->resize(600, 400);
        centralWidget = new QWidget(QtDriverClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        exit_button = new QPushButton(centralWidget);
        exit_button->setObjectName(QStringLiteral("exit_button"));
        exit_button->setGeometry(QRect(520, 320, 75, 23));
        openGLWidget = new QOpenGLWidget(centralWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setGeometry(QRect(0, -1, 601, 311));
        QtDriverClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtDriverClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        QtDriverClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtDriverClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtDriverClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtDriverClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtDriverClass->setStatusBar(statusBar);

        retranslateUi(QtDriverClass);

        QMetaObject::connectSlotsByName(QtDriverClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtDriverClass)
    {
        QtDriverClass->setWindowTitle(QApplication::translate("QtDriverClass", "QtDriver", 0));
        exit_button->setText(QApplication::translate("QtDriverClass", "Exit", 0));
    } // retranslateUi

};

namespace Ui {
    class QtDriverClass: public Ui_QtDriverClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTDRIVER_H
