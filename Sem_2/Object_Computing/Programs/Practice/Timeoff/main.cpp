#include <iostream>
#include "Timeoff.h"
#include<string>
using namespace std;

int main()
{

    Timeoff e("Susanth", 1234, 10, 10, 10);
    char x;
    int i;
    do
    {
        cout<<"Press 1 to apply for Sick days"<<endl;
        cout<<"Press 2 to apply for Vacation days"<<endl;
        cout<<"Press 3 to apply for Unpaid days"<<endl;
      l1:  cin>>i;
        switch(i)
        {
            case 1: e.addSick();
                    break;
            case 2: e.addVac();
                    break;
            case 3: e.addUnpaid();
                    break;
            default:cout<<"Please enter a valid input\n";
                    goto l1;
        }
        cout<<"Do you want to continue"<<endl;
        cout<<"Press y to continue and n to stop"<<endl;
        cin>>x;
    }while(x!='n');

    return 0;
}
