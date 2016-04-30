#include "fault.h"


Res resistor1;
Cap capacitor1;
QString list;

fault::fault(QWidget *parent) :
    QListWidget(parent)
{

}

// Чтение и модификация исходного нетлиста
void fault::analys_file(QString filename)
{
    // Определимся с директорией и именем файла
    QString t_filename=filename.section('/',-1);
    QString dir=filename.left(filename.lastIndexOf('/')+1);
    src_netlist.setFileName(filename);
    test_netlist.setFileName(dir+"mod_"+t_filename);

    qDebug()<<src_netlist.fileName();

    // Открыть, проверить
    QFile in(filename);
    if (!in.open(QIODevice::ReadOnly | QIODevice::Text))
    {throw "Ошибка. Не удалось открыть файл "+filename+" для чтения.";}

    // Модифицированный файл
    if (!test_netlist.open(QIODevice::WriteOnly|QIODevice::Truncate|QIODevice::Text))
    {throw "Ошибка. Не удалось записать модифицированный нетлист.";}


    QString line;               // Очередная строка
    QStringList strl;           // Для узлов, с которыми необходимо поработать
    QString field1;             // С чем работаем
    QString first_letter;       // Первая буква
    int num_of_line=0;          // Номер текущей линии




    while (!in.atEnd())
    {
             line = in.readLine();
             num_of_line++;
             strl.clear();
             field1=line.section(' ',0,0);                             // Поле с названием элемента
             first_letter=field1.mid(0,1);                             // Первая буква

         // Выделить и переименовать узлы

            if(first_letter=="R")
            {


                QString field2=line.section(' ',1,1);                   // Поле узел 1
                QString field3=line.section(' ',2,2);                   // Поле узел 2
                QString field4=line.section(' ',3,3);                   // Поле номинал с приставкой

                int sizer=field4.size();                                // Кол-во символов в номинале

                QString zifr=field4.mid(0,sizer-2);                     // Численная часть номинала
                QString bukv=field4.data()[sizer-1];                    // Буквенная часть номинала

                //Печать неисправностей на экран
                faults.push_back("Резистор " +field1+ " =1 kОм " );
                faults.push_back("Резистор " +field1+ " =1 МОм " );



    // Занесение в структуру

                resistor1.res_name=field1;
                resistor1.node1=field2;
                resistor1.node2=field3;
                resistor1.nominal=field4;

    // Занесение структуры в список
                netlist.append(netlist_string(resistor1));

                continue;
               }

            else if(first_letter=="C")
            {
                QString field2=line.section(' ',1,1);                   // Поле узел 1
                QString field3=line.section(' ',2,2);                   // Поле узел 2
                QString field4=line.section(' ',3,3);                   // Поле номинал с приставкой

                int sizer=field4.size();                                // Кол-во символов в номинале

                QString zifr=field4.mid(0,sizer-2);                     // Численная часть номинала
                QString bukv=field4.data()[sizer-1];                    // Буквенная часть номинала

                //Печать неисправностей на экран
                faults.push_back("Конденсатор " +field1+ " =1 пФ " );
                faults.push_back("Конденсатор " +field1+ " =1 Ф " );



    // Занесение в структуру

                capacitor1.cap_name=field1;
                capacitor1.node1=field2;
                capacitor1.node2=field3;
                capacitor1.nominal=field4;

    // Занесение структуры в список
                netlist.append(netlist_string(capacitor1));

                continue;

            }

           else
            {
                netlist.append(netlist_string(line));
            }
          }

    in.close();
    this->addItems(faults);
    temp_result.setFileName("temp_result.txt");
    emit right_open(true);      // Все хорошо
}

void fault::res_fault(int number1)

{
    int tmp1=0;
    int tmp2=1;
    test_netlist.open(QIODevice::WriteOnly);

    for (int i = 0;i<netlist.count();i++)
    {
        if(netlist.at(i).type==0)
        {
            test_netlist.write(netlist.at(i).net_string.toAscii());
        }

        else if(netlist.at(i).type==1){

            if (number1==tmp1)
            {
                test_netlist.write(netlist.at(i).res.res_name.toAscii()+" ");
                test_netlist.write(netlist.at(i).res.node1.toAscii()+" ");
                test_netlist.write(netlist.at(i).res.node2.toAscii()+" ");
                test_netlist.write("1k\n");

            }

           else if (number1==tmp2)
            {
                test_netlist.write(netlist.at(i).res.res_name.toAscii()+" ");
                test_netlist.write(netlist.at(i).res.node1.toAscii()+" ");
                test_netlist.write(netlist.at(i).res.node2.toAscii()+" ");
                test_netlist.write("1m\n");
            }
            else
            {
                test_netlist.write(netlist.at(i).res.res_name.toAscii()+" ");
                test_netlist.write(netlist.at(i).res.node1.toAscii()+" ");
                test_netlist.write(netlist.at(i).res.node2.toAscii()+" ");
                test_netlist.write(netlist.at(i).res.nominal.toAscii());
            }

            tmp1+=2;
            tmp2+=2;
          }
        else if (netlist.at(i).type==2)
        {
            if (number1==tmp1)
            {
                test_netlist.write(netlist.at(i).cap.cap_name.toAscii()+" ");
                test_netlist.write(netlist.at(i).cap.node1.toAscii()+" ");
                test_netlist.write(netlist.at(i).cap.node2.toAscii()+" ");
                test_netlist.write("1p\n");

            }

           else if (number1==tmp2)
            {
                test_netlist.write(netlist.at(i).cap.cap_name.toAscii()+" ");
                test_netlist.write(netlist.at(i).cap.node1.toAscii()+" ");
                test_netlist.write(netlist.at(i).cap.node2.toAscii()+" ");
                test_netlist.write("1u\n");
            }
            else
            {
                test_netlist.write(netlist.at(i).cap.cap_name.toAscii()+" ");
                test_netlist.write(netlist.at(i).cap.node1.toAscii()+" ");
                test_netlist.write(netlist.at(i).cap.node2.toAscii()+" ");
                test_netlist.write(netlist.at(i).cap.nominal.toAscii());
            }

            tmp1+=2;
            tmp2+=2;

        }
      }
    test_netlist.close();
}


// Моделирование
bool fault::model()
{

    QProcess prc;   // Моделируем netlist
    prc.start("scad3.exe -run -b -ascii "+test_netlist.fileName());
    return prc.waitForFinished(60000);
}



