/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QListWidget *listWidget;
    QPushButton *connectBtn;
    QLineEdit *lineEdit;
    QPushButton *sendBtn;
    QPushButton *qb;
    QPushButton *wb;
    QPushButton *eb;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(794, 562);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(250, 160, 261, 192));
        connectBtn = new QPushButton(centralWidget);
        connectBtn->setObjectName(QString::fromUtf8("connectBtn"));
        connectBtn->setGeometry(QRect(340, 110, 80, 21));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(250, 360, 171, 21));
        sendBtn = new QPushButton(centralWidget);
        sendBtn->setObjectName(QString::fromUtf8("sendBtn"));
        sendBtn->setGeometry(QRect(430, 360, 81, 21));
        qb = new QPushButton(centralWidget);
        qb->setObjectName(QString::fromUtf8("qb"));
        qb->setGeometry(QRect(560, 210, 89, 25));
        wb = new QPushButton(centralWidget);
        wb->setObjectName(QString::fromUtf8("wb"));
        wb->setGeometry(QRect(560, 240, 89, 25));
        eb = new QPushButton(centralWidget);
        eb->setObjectName(QString::fromUtf8("eb"));
        eb->setGeometry(QRect(560, 270, 89, 25));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 794, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        connectBtn->setText(QCoreApplication::translate("MainWindow", "CONNECT", nullptr));
        sendBtn->setText(QCoreApplication::translate("MainWindow", "SEND !", nullptr));
        qb->setText(QCoreApplication::translate("MainWindow", "Q", nullptr));
        wb->setText(QCoreApplication::translate("MainWindow", "W", nullptr));
        eb->setText(QCoreApplication::translate("MainWindow", "E", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
