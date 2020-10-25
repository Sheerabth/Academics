#include <iostream>
#include "overload.h"

using namespace std;

Point :: Point ()
{
    x = y =0;
}

Point :: Point (int x, int y)
{
    this->x = x;
    this->y = y;
}

Point& Point :: operator ++()
{
    x += 1;
    y += 1;
    return *this;
}

Point Point :: operator ++(int)
{
    Point temp = *this;
    x += 1;
    y += 1;
    return temp;
}

Point Point :: operator + (const Point &p)
{
    Point sum;
    sum.x = x + p.x;
    sum.y = y + p.y;
    return sum;
}

Point Point :: operator - (const Point &p)
{
    Point diff;
    diff.x = x - p.x;
    diff.y = y - p.y;
    return diff;
}

void Point :: display()
{
    cout << "(" << x << ", " << y << ")" << endl;
}

istream& operator >> (istream& in, Point &p)
    {
        in >> p.x;
        in >> p.y;
        return in;
    }

ostream& operator << (ostream& out, Point &p)
    {
        out << "(" << p.x << ", " << p.y << ")" << endl;
        return out;
    }
