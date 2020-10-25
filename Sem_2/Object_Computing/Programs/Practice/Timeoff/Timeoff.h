#ifndef TIMEOFF_H_INCLUDED
#define TIMEOFF_H_INCLUDED
#include<string>
class Timeoff
{
    std::string name;
    int idn_num;
    int maxsick;
    int sicktaken;
    int maxvac;
    int vactaken;
    int maxunpaid;
    int unpaidtaken;
    public:
    Timeoff(std::string, int, int, int, int);
    //void setMaxSick(int);
    //void setmaxVactaion(int);
    //void setmaxunpaid(int);
    void addSick();
    void addVac();
    void addUnpaid();
    void showDetails();
};


#endif // TIMEOFF_H_INCLUDED
