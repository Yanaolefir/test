#include "fault.h"


Res resistor1;
QString list;

fault::fault(QWidget *parent) :
    QListWidget(parent)
{

}

// ������ � ����������� ��������� ��������
void fault::analys_file(QString filename)
{
    // ����������� � ����������� � ������ �����
    QString t_filename=filename.section('/',-1);
    QString dir=filename.left(filename.lastIndexOf('/')+1);
    src_netlist.setFileName(filename);
    test_netlist.setFileName(dir+"mod_"+t_filename);

    qDebug()<<src_netlist.fileName();

    // �������, ���������
    QFile in(filename);
    if (!in.open(QIODevice::ReadOnly | QIODevice::Text))
    {throw "������. �� ������� ������� ���� "+filename+" ��� ������.";}

    // ���������������� ����
    if (!test_netlist.open(QIODevice::WriteOnly|QIODevice::Truncate|QIODevice::Text))
    {throw "������. �� ������� �������� ���������������� �������.";}


    QString line;               // ��������� ������
    QStringList strl;           // ��� �����, � �������� ���������� ����������
    QString field1;             // � ��� ��������
    QString first_letter;       // ������ �����
    int num_of_line=0;          // ����� ������� �����



    while (!in.atEnd())
    {
             line = in.readLine();
             num_of_line++;
             strl.clear();
             field1=line.section(' ',0,0);                             // ���� � ��������� ��������
             first_letter=field1.mid(0,1);                             // ������ �����

         // �������� � ������������� ����

            if(first_letter=="R")
            {


                QString field2=line.section(' ',1,1);                   // ���� ���� 1
                QString field3=line.section(' ',2,2);                   // ���� ���� 2
                QString field4=line.section(' ',3,3);                   // ���� ������� � ����������

                int sizer=field4.size();                                // ���-�� �������� � ��������

                QString zifr=field4.mid(0,sizer-2);                     // ��������� ����� ��������
                QString bukv=field4.data()[sizer-1];                    // ��������� ����� ��������
                //double nom=zifr.toDouble();                             // ��������� ����� � double


                faults.push_back("�������� " +field1+ " =1 �� " );
                faults.push_back("�������� " +field1+ " =1 ��� " );

    // ��������� � ���������
                resistor1.res_name=field1;
                resistor1.node1=field2;
                resistor1.node2=field3;
                resistor1.nominal=field4;

    // ��������� ��������� � ������
                netlist.append(netlist_string(resistor1));
                continue;
               }

           else
            {
                netlist.append(netlist_string(line));
            }
          }


    // ������ ������������ �������� � ���� test_netlist

      test_netlist.open(QIODevice::WriteOnly);
      //QDataStream stream(&test_netlist);
     // stream.setVersion(QDataStream::Qt_4_8);




      for (int i = 0;i<netlist.count();i++)
      {
          if(netlist.at(i).type==0){

              test_netlist.write(netlist.at(i).net_string.toAscii());
              //stream << netlist[i].net_string.toAscii();
          }
          else if(netlist.at(i).type==1){
              test_netlist.write(netlist.at(i).res.res_name.toAscii());
              test_netlist.write(netlist.at(i).res.node1.toAscii());
              test_netlist.write(netlist.at(i).res.node2.toAscii());
              test_netlist.write(netlist.at(i).res.nominal.toAscii());
             // stream<< netlist[i].res.res_name.toAscii();
             // stream<< netlist[i].res.node1.toAscii();
             // stream<< netlist[i].res.node2.toAscii();
             // stream << netlist[i].res.nominal.toAscii();
            }
        }
    in.close();
    test_netlist.close();
    this->addItems(faults);
    temp_result.setFileName("temp_result.txt");
    emit right_open(true);      // ��� ������
}


// �������� ��������
void fault::print_netlist(QString filename)
{
    // ������� ���� �����������
    QFile out(filename);
    if (!out.open(QIODevice::WriteOnly|QIODevice::Truncate|QIODevice::Text))
    {throw "������.�� ������� ������� ���� ����������� "+filename+" ��� ������.";}

    out.write("");
    foreach (QString temp, list) {
        out.write(temp.toAscii());
    }
    out.write("");
    out.close();
}

// �������������
bool fault::model()
{

    QProcess prc;   // ���������� netlist
    prc.start("scad3.exe -run -b -ascii "+src_netlist.fileName());
    return prc.waitForFinished(60000);
}



