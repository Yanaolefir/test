#include "mainwindow.h"
#include "fault.h"
#include "ui_mainwindow.h"
#include <QTextCodec> //руссификатор

//#include <QString>
//#include <QStringList>
//#include <QFile>
//#include <QMessageBox>

//#include <QFileDialog>
//#include <QTextStream>
//#include <QDesktopServices>

#include <fstream>
#include <sstream>
#include <list>

using namespace std;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTextCodec::setCodecForCStrings(QTextCodec:: codecForName("CP1251"));
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exit_activated()
{
    this->close();
}

void MainWindow::on_open_triggered()
{
   ui->listWidget->analys_file(fd.getOpenFileName(this,"Открыть файл",QDesktopServices::storageLocation(QDesktopServices::HomeLocation)+"\\\\", "Netlist (*.net);; Все файлы (*.*)"));

}

void MainWindow::on_but_open_clicked()
{
    ui->listWidget->analys_file(fd.getOpenFileName(this,"Открыть файл",QDesktopServices::storageLocation(QDesktopServices::HomeLocation)+"\\\\", "Netlist (*.net);; Все файлы (*.*)"));
}

void MainWindow::on_but_model_clicked()
{
    ui->listWidget->model();
}


void MainWindow::on_but_choose_clicked()
{



    int i=ui->listWidget->currentRow(); //Столбец нулевой
    ui->listWidget->res_fault(i);




}

void MainWindow::on_make_sign_triggered()
{
    ui->listWidget->make_sign(fd.getOpenFileName(this,"Открыть файл",QDesktopServices::storageLocation(QDesktopServices::HomeLocation)+"\\\\", "Raw (*.raw);; Все файлы (*.*)"));
}

void MainWindow::on_but_make_sign_clicked()
{
    ui->listWidget->make_sign(fd.getOpenFileName(this,"Открыть файл",QDesktopServices::storageLocation(QDesktopServices::HomeLocation)+"\\\\", "Raw (*.raw);; Все файлы (*.*)"));
}
