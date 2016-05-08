#include "fault.h"


Res resistor1;
Cap capacitor1;
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

                //������ �������������� �� �����
                faults.push_back("�������� " +field1+ " =1 k�� " );
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

            else if(first_letter=="C")
            {
                QString field2=line.section(' ',1,1);                   // ���� ���� 1
                QString field3=line.section(' ',2,2);                   // ���� ���� 2
                QString field4=line.section(' ',3,3);                   // ���� ������� � ����������

                int sizer=field4.size();                                // ���-�� �������� � ��������

                QString zifr=field4.mid(0,sizer-2);                     // ��������� ����� ��������
                QString bukv=field4.data()[sizer-1];                    // ��������� ����� ��������

                //������ �������������� �� �����
                faults.push_back("����������� " +field1+ " =1 �� " );
                faults.push_back("����������� " +field1+ " =1 � " );



    // ��������� � ���������

                capacitor1.cap_name=field1;
                capacitor1.node1=field2;
                capacitor1.node2=field3;
                capacitor1.nominal=field4;

    // ��������� ��������� � ������
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
    emit right_open(true);      // ��� ������
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


// �������������
bool fault::model()
{

    QProcess prc;   // ���������� netlist
    prc.start("scad3.exe -run -b -ascii "+test_netlist.fileName());
    return prc.waitForFinished(60000);
}


// ��������� ���������

void  fault::make_sign(QString filename)
{
  QFile in(filename);
    if (!in.open(QIODevice::ReadOnly | QIODevice::Text))
    {throw "�� ������� ������� ���� ����������� ������������� ��� ������.";}

    QMap<double, double> map;
    QMap<double, double>::iterator it = map.begin();
    QVector<double> vec;
    QString line;

    int type_an=0;
    int pos_of_in=0;
    int pos_of_out=0;
    int no_var=1;

    int i=0;
    int k=1;
    int m=0;
    int z=0;
    double temp=0;



    while(!in.atEnd())
    {

        line=in.readLine();

// �������� ����������� ����
        QString f1=line.section(' ',0,0);
        QString f2=line.section(' ',1,1);
        QString f3=line.section(' ',2,2);
        QString f4=line.section(' ',3,3);
        QString f5=line.section(' ',4,4);

        QString l1=line.section('\t',0,0);
        QString l2=line.section('\t',1,1);
        QString l3=line.section('\t',2,2);



// �������� ����� ������ �� ���������� ���������� �������������
        if(f1!="Values:\n")
            k++;
        else
            m=k+1;


// ���������� ��� �������������
        if (f2=="Transient")
            type_an=1;
        if (f2=="AC")
            type_an=2;
        if (f2=="DC")
            type_an=3;

//�������� ���������� ����������
        if(f1=="No." && f2=="Variables:")
            no_var=f3.toInt();


// ���������� ����� ������� ����� � ������ ()
        if (type_an==3 && l2=="0")
            pos_of_in=l2.toInt();

        if (type_an==3 && l3=="V(out)")
           pos_of_out=l2.toInt();


        if(l1.toInt()==i)
            temp=l3.toDouble();

// ������� �� ������� (���������� ����� ������ � �����)
        int q1=(i+1-m)%no_var;

        if(q1==0 && m>0)
         {
             vec.append(l3.toDouble());
             qDebug()<<vec.last();

         }
         if (q1==1 && m>0)
         {
            vec.append(l2.toDouble());
            qDebug()<<vec.last();
         }
       i++;
    }

// ��������� map ���������� vec

    int vec_size=vec.size();
    //qDebug()<<vec_size;
    while (z<vec_size-2)
    {
        qDebug()<<vec.at(z)<<vec.at(z+1);  // ����� ��� ��
        map.insert(vec.at(z),vec.at(z+1)); // �� ���� �������� ���� ������ ���������
        z+=2;

    }

// ������ map (�� �������� :(  )
    while(it != map.end())
    {
       qDebug() << it.key() << " : " << it.value();
       ++it;
    }


    }


