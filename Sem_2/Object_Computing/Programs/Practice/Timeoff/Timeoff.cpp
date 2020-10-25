#include<iostream>
#include<string>
#include"Timeoff.h"

using namespace std;

Timeoff::Timeoff(string name, int idn_num, int maxsick, int maxvac, int maxunpaid)
{
    this->name=name;
    this->idn_num=idn_num;
    this->maxsick=maxsick;
    this->maxvac=maxvac;
    this->maxunpaid=maxunpaid;
    this->sicktaken=0;
    this->vactaken=0;
    this->unpaidtaken=0;
}

void Timeoff::addSick()
{
    int d;
    cout<<"Please enter the amount of days you want to apply the leave for"<<endl;
    cin>>d;
    sicktaken+=d;
    if(sicktaken>maxsick)
    {
        cout<<"Sorry, but you cant apply for any more sick days\n";
        sicktaken-=d;
    }
    else
    {
        cout<<"Total sick days Taken till now "<<sicktaken<<endl;
    }

}

void Timeoff::addVac()
{
    int d;
    cout<<"Please enter the amount of days you want to apply the leave for"<<endl;
    cin>>d;
    vactaken+=d;
    if(vactaken>maxvac)
    {
        cout<<"Sorry, but you cant apply for any more Vactaion days\n";
        vactaken-=d;
    }
    else
    {
        if(d>=10)
        {
            cout<<"Sorry, but you can't apply for more than 240 hours at a time"<<endl;
            vactaken-=d;
        }
        else
        {
            cout<<"Total Vacation days taken till now "<<vactaken<<endl;
        }

    }

}

void Timeoff::addUnpaid()
{
    int d;
    cout<<"Please enter the amount of days you want to apply the leave for"<<endl;
    cin>>d;
    unpaidtaken+=d;
    if(unpaidtaken>maxunpaid)
    {
        cout<<"Sorry, but you cant apply for any more unpaid days\n";
        unpaidtaken-=d;
    }
    else
    {
        cout<<"Total unpaid days Taken till now "<<unpaidtaken<<endl;
    }

}

void showDetails()
{
    cout<<"Name: "<<name<<endl;
    cout<<"Identification Number: "<<idn_num<<endl;
    cout<<
}
