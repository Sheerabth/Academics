#include <iostream>
#include "ws4_2.h"
using namespace std;

Set :: Set(int num)
{
    set = new int[num];
    size = num;
    top = -1;
}

void Set::add()
{
    int val;
    if(top == size-1)
    {
        cout << "The set is full" << endl;
        return;
    }
    cout << "Please enter the value you want to insert" << endl;
    cin >> val;

    top++;
    set[top] = val;
}

void Set::remove()
{
     int val, flag = 0;
     if(top == -1)
    {
        cout << "The set is empty" << endl;
        return;
    }
    cout << "Please enter the value you want to delete" << endl;
    cin >> val;
    int i, j;
    for(i=0; i<=top ;i++)
    {
        if(set[i] == val)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1)
    {
        for(j=i; j<top; j++)
        {
            set[j] = set[j+i];
        }
        top--;
    }
    else
    {
        cout << "Entered number does not exist in the list" << endl;
    }
}


void Set :: display()
{
    int i;
    for(i=0; i<top; i++)
    {
        cout <<"\n"<< set[i]<< ", ";
    }
    cout << "\b.";
}

Set Set::operator | (Set s)
{
    Set uni(this->size + s.size);
    int i, j;
    for(i=0; i<=this->top; i++)
    {
       uni.add(this->set[i]);
    }
    for(i=0; i<=s.top; j++)
    {
        uni.add(s.set[i]);
    }
    for(i=0; i<uni.top; i++)
    {
        for(j=1; j<=uni.top; j++)
        {
            if(uni.set[i] == uni.set[j])
            {
                uni.remove(uni.set[j]);
            }
        }
    }
    return uni;
}

Set Set::operator & (Set s)
{
    Set ins(this->size + s.size);
    int i, j;
     for(i=0; i<this->top; i++)
    {
        for(j=1; j<=s.top; j++)
        {
            if(this->set[i] == s.set[j])
            {
                ins.add(s.set[j]);
            }
        }
    }
}
