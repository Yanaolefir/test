/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed 13. Apr 18:28:58 2016
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include "fault.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *open;
    QAction *model;
    QWidget *centralWidget;
    QPushButton *but_open;
    fault *listWidget;
    QLabel *label;
    QPushButton *but_model;
    QPushButton *save_netlist;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(662, 494);
        open = new QAction(MainWindow);
        open->setObjectName(QString::fromUtf8("open"));
        model = new QAction(MainWindow);
        model->setObjectName(QString::fromUtf8("model"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        but_open = new QPushButton(centralWidget);
        but_open->setObjectName(QString::fromUtf8("but_open"));
        but_open->setGeometry(QRect(530, 10, 111, 31));
        listWidget = new fault(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(30, 50, 221, 341));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 221, 20));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        but_model = new QPushButton(centralWidget);
        but_model->setObjectName(QString::fromUtf8("but_model"));
        but_model->setGeometry(QRect(530, 50, 111, 31));
        save_netlist = new QPushButton(centralWidget);
        save_netlist->setObjectName(QString::fromUtf8("save_netlist"));
        save_netlist->setGeometry(QRect(530, 90, 111, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 662, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(open);
        menu->addAction(model);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        open->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        model->setText(QApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        but_open->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "              \320\241\320\277\320\270\321\201\320\276\320\272 \320\275\320\265\320\270\321\201\320\277\321\200\320\260\320\262\320\275\320\276\321\201\321\202\320\265\320\271", 0, QApplication::UnicodeUTF8));
        but_model->setText(QApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        save_netlist->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 neltist", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
