#include <iostream>

using namespace std;


class Point
{
    public:
    int x;
    int y;

    Point (int a, int b)
    {
        x = a;
        y = b;
    }
};

class Rational
{
    int num;
    int den;
    public:
    Rational (int a, int b)
    {
        num = a;
        den = b;
    }
    /*Rational& operator = (Point& p)
    {
        num = p.x;
        den = p.y;
        return *this;
    }*/
    void display()
    {
        cout << "Num: " << num << endl << "Den: " << den  << endl;
    }
};


int main()
{
    //cout << sizeof(1.0f/2);
    Rational r(1, 1);
    Rational r1(1, 1);
    Point p(1, 2);
    r = r1 = p;
    r.display();
    r1.display();
    return 0;
}
