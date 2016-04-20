#ifndef FAULT_H
#define FAULT_H

#include <QListWidget>
#include <QFile>
#include <QTextStream>
#include <Qstring>
#include <QVector>
#include <QProcess>
#include <RandC.h>

#include <QDebug>
#include <qdebug.h>
#include <QDataStream>

// Структура описания тестового резистора

struct Res
{
    Res(QString res_name="",QString node1="", QString node2="",QString nominal="")
    {

        this->res_name=res_name;
        this->node1=node1;
        this->node2=node2;
        this->nominal=nominal;

    }
    QString res_name,node1,node2,nominal;
};

enum TYPE_ELEMENT
{
    TE_STRING, TE_RESISTOR
};

struct netlist_string
{
    TYPE_ELEMENT type;
    netlist_string(QString net_string)
    {
        this->net_string=net_string;
        type=TE_STRING;
    }
    netlist_string(Res res)
    {
        this->res=res;
        type=TE_RESISTOR;
    }

    QString net_string;
    Res res;
};

class fault : public QListWidget
{
    Q_OBJECT
public:
    explicit fault(QWidget *parent = 0);
    bool model();             // Моделировать что и куда

protected:
    QFile src_netlist;                   // Исходный нетлист
    QFile test_netlist;                  // Тестовый нетлист
    QFile temp_result;                   // Файл с временными результатами моделирования

    QStringList faults;             // Наименования неисправностей


signals:
        void right_open(bool);          // Открытие правильное

public slots:

        void analys_file(QString filename);         // Первое открытие файла

        void res_fault(int number1);



private:
        QList<netlist_string> netlist;
};

#endif // FAULT_H
