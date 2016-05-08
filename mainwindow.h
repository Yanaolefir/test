#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include <QMainWindow>
//#include <QMessageBox>
//#include <QApplication>
//#include <QFileDialog>
//#include <QListWidget>
#include <QtGui>
//#include "fault.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_open_triggered();
    void on_exit_activated();
    void on_but_open_clicked();
    void on_but_model_clicked();


    void on_but_choose_clicked();

    void on_make_sign_triggered();

    void on_but_make_sign_clicked();

private:
    Ui::MainWindow *ui;
    QFileDialog fd;
};

#endif // MAINWINDOW_H
