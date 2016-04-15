#ifndef RES_H
#define RES_H
#include <QString>
struct Res
{
    Res(QString res_name="", Qstring node1="", Qstring node2="", Qstring nominal="")
    {
        this->res_name=res_name;
        this->node1=node1;
        this->node2=node2;
        this->nominal=nominal;

    }
    QString res_name,node1,node2,nominal;

};


#endif // RES_H
