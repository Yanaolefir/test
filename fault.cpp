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
    //lst_wgt2->

    QProcess prc;   // ���������� netlist
    prc.start("scad3.exe -run -b -ascii "+test_netlist.fileName());
    return prc.waitForFinished(60000);
}

void fault::setLstWgt2(QListWidget *lstwgt2)
{
    this->lst_wgt2=lstwgt2;
}


// ��������� ���������

void  fault::make_sign(QString filename)
{
  QFile in(filename);
    if (!in.open(QIODevice::ReadOnly | QIODevice::Text))
    {throw "�� ������� ������� ���� ����������� ������������� ��� ������.";}
    QMap<QString,QVector<double> > map;
    QMap<QString,QVector<double> >::iterator it = map.begin();

    QVector<double> vec1;
    QVector<double> vec2;
    QVector<double> vec3;
    QVector<double> vec4;
    QVector<double> vec5;

    QString line;

    QString name_in="";
    QString name_1="";
    QString name_2="";
    QString name_3="";
    QString name_4="";


    int pos_in=0;
    int pos_1=0;
    int pos_2=0;
    int pos_3=0;
    int pos_4=0;

    int no_var=1;

    int i=0;
    int k=1;
    int m=0;
    int type_an=0;

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

// ���������� ����� ������ �������
        if (type_an==3 && l2=="0")
        {
            pos_in=l2.toInt();
            name_in=l3;
        }

        if (type_an==3 && l3=="V(out1)")
        {
            pos_1=l2.toInt();
            name_1=l3;
        }
        if (type_an==3 && l3=="V(out2)")
        {
            pos_2=l2.toInt();
            name_2=l3;
        }
        if (type_an==3 && l3=="V(out3)")
        {
            pos_3=l2.toInt();
            name_3=l3;
        }
        if (type_an==3 && l3=="V(out4)")
        {
            pos_4=l2.toInt();
            name_4=l3;
        }

// ������� �� ������� (���������� ����� ������ � �����)
        int q1=(i+1-m)%no_var;
// ������� ������ � �������
        if(q1==pos_in && m>0)
            vec1.append(l3.toDouble());

        if (q1==pos_1 && m>0 )       
            vec2.append(l2.toDouble());        

        if (q1==pos_2 && m>0)       
             vec3.append(l2.toDouble());

        if (q1==pos_3 && m>0)        
             vec4.append(l2.toDouble());      

        if (q1==pos_4 && m>0)        
              vec5.append(l2.toDouble());
       i++;
    }

// ���������, �� ������� �� ������
    double v1=0;
    double v2=0;
    double v3=0;
    double v4=0;
    double v5=0;

    for(int i=0; i<vec1.size();i++)
        v1+=vec1[i];
    for(int i=0; i<vec2.size();i++)
        v2+=vec2[i];
    for(int i=0; i<vec3.size();i++)
        v3+=vec3[i];
    for(int i=0; i<vec4.size();i++)
        v4+=vec4[i];
    for(int i=0; i<vec5.size();i++)
        v5+=vec5[i];

// ������� � map
    if (v1!=0)
      map.insert(name_in,vec1);

    if (v2!=0)
      map.insert(name_1,vec2);

    if (v3!=0)
      map.insert(name_2,vec3);

    if  (v4!=0)
      map.insert(name_3,vec4);

    if  (v5!=0)
      map.insert(name_4,vec5);


// ������ map
        it=map.begin();
        while(it != map.end())
        {
           qDebug() << it.key() << " : " << it.value();
           ++it;
        }

    }

