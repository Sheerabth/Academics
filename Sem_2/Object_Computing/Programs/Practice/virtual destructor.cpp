#include <iostream>

using namespace std;

class B
{
    char* ptrb;
    public:
    B()
    {
        ptrb = new char[5];
        cout << "B allocates 5 bytes" << endl;
    }
    ~B()
    {
        delete [] ptrb;
        cout << "B frees 5 bytes" << endl;
    }
};

class D : public B
{
    char* ptrd;
    public:
    D():B()
    {
        ptrd = new char[1000];
        cout << "D allocates 1000 bytes" << endl;
    }
    ~D()
    {
        delete [] ptrd;
        cout << "D frees 1000 bytes" << endl;
    }
};

void f()
{
    B* p = new D;
    delete p;
}

int main()
{
    const int forever = 1;
    while(forever)
    {
        f();
    }
    return 0;
}


