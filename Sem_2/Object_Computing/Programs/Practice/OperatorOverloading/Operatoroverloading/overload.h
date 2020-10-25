#ifndef OVERLOAD_H_INCLUDED
#define OVERLOAD_H_INCLUDED
using namespace std;
class Point
{
    int x;
    int y;
public:
    Point();
    Point(int, int);
    Point& operator ++();
    Point operator ++(int);
    Point operator +(const Point&);
    Point operator - (const Point&);
    void display();
    friend istream& operator >> (istream& in, Point &p);

    friend ostream& operator << (ostream& out, Point &p);
};
#endif // OVERLOAD_H_INCLUDED
