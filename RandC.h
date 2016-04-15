#ifndef RANDC_H
#define RANDC_H
struct RandC
{
    RandC(int pos=0,double bot=0,double mid=0,double top=0,QString name="")
    {
        this->pos=pos;
        this->means[0]=bot;
        this->means[1]=mid;
        this->means[2]=top;
        this->name=name;
    }
    int pos;
    double means[3];
    QString name;
};
#endif // RANDC_H
