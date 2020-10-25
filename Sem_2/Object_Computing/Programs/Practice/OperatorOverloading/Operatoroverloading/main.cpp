#include <iostream>
#include "overload.h"
//using namespace std;




int main()
{
    Point p1(3, 1);
    Point p2(2, 1);
    Point p3(4, 1);
    Point p4;
    p4 = p1 - p2 - p3;
    p4.display();
    //cin >> p4;
    //cout << p4;
    return 0;
}
