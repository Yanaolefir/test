/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun 8. May 11:53:28 2016
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
#include <QtGui/QListWidget>
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
    QAction *make_sign;
    QWidget *centralWidget;
    QPushButton *but_open;
    fault *listWidget;
    QLabel *label;
    QPushButton *but_model;
    QPushButton *but_choose;
    QListWidget *listWidget_2;
    QPushButton *but_make_sign;
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
        make_sign = new QAction(MainWindow);
        make_sign->setObjectName(QString::fromUtf8("make_sign"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        but_open = new QPushButton(centralWidget);
        but_open->setObjectName(QString::fromUtf8("but_open"));
        but_open->setGeometry(QRect(260, 40, 111, 31));
        listWidget = new fault(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 40, 221, 361));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 221, 20));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        but_model = new QPushButton(centralWidget);
        but_model->setObjectName(QString::fromUtf8("but_model"));
        but_model->setGeometry(QRect(260, 120, 111, 31));
        but_choose = new QPushButton(centralWidget);
        but_choose->setObjectName(QString::fromUtf8("but_choose"));
        but_choose->setGeometry(QRect(260, 80, 111, 31));
        listWidget_2 = new QListWidget(centralWidget);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setGeometry(QRect(395, 40, 241, 361));
        but_make_sign = new QPushButton(centralWidget);
        but_make_sign->setObjectName(QString::fromUtf8("but_make_sign"));
        but_make_sign->setGeometry(QRect(260, 160, 111, 31));
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
        menu->addAction(make_sign);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        open->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        model->setText(QApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        make_sign->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \321\201\320\270\320\263\320\275\320\260\321\202\321\203\321\200\321\203", 0, QApplication::UnicodeUTF8));
        but_open->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "              \320\241\320\277\320\270\321\201\320\276\320\272 \320\275\320\265\320\270\321\201\320\277\321\200\320\260\320\262\320\275\320\276\321\201\321\202\320\265\320\271", 0, QApplication::UnicodeUTF8));
        but_model->setText(QApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        but_choose->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200", 0, QApplication::UnicodeUTF8));
        but_make_sign->setText(QApplication::translate("MainWindow", "\320\241\320\270\320\263\320\275\320\260\321\202\321\203\321\200\320\260", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
