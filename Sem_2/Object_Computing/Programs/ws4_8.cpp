#include <iostream>
#include <string>
using namespace std;

class Painting
{
protected:
    string name;
    string artist;
    int value;
public:
    Painting(string name, string artist){value = 400; this->name = name; this->artist = artist;}
    virtual void display()
    {
        cout << "Title: " << name << endl;
        cout << "Artist: " << artist << endl;
        cout << "Value: " << value << endl;
    }
};

class FamousPainting : public Painting
{
public:
    FamousPainting(string name, string artist) : Painting(name, artist){value = 25000; }
    void display()
    {
        cout << "Title: " << name << endl;
        cout << "Artist: " << artist << endl;
        cout << "Value: " << value << endl;
    }
};

int main()
{
    Painting *p[10];
    string artist, name;
    for(int i = 0; i < 10; i++)
    {
        cout << "Please enter Title and Artist name" << endl;
        cin >> name >> artist;
        if(artist == "Degas" || artist == "Monet" || artist == "Picasso" || artist == "Rembrandt")
        {

            p[i] = new FamousPainting(name, artist);
        }
        else
        {
            p[i] = new Painting(name, artist);
        }
    }
    for(int i = 0; i < 10; i++)
    {
        p[i]->display();
    }

}
