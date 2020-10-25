#include <iostream>
using namespace std;

class Node
{
    int data;
    Node* link;
    public:
    Node(int d);
    friend class List;
};

Node :: Node(int d)
{
    data = d;
    link = NULL;
}

class List
{
    Node* head;
    public:
    List();
    void newEnd(int d);
    Node* delMid(int d);
    List alternateSplit();
    void display();
};

List :: List()
{
    head = NULL;
}

void List :: newEnd(int d)
{
   Node* ins = new Node(d);
   if(head == NULL)
   {
       head = ins;
   }
   else
   {
       Node* temp = head;
       while(temp->link != NULL)
       {
           temp = temp->link;
       }
       temp->link = ins;
   }

}

Node* List :: delMid(int d)
{
    if(head == NULL)
    {
        cout << "The list is empty" << endl;
    }
    else
    {
        Node* temp = head;
        while(temp->link->data != d)
        {
            temp = temp->link;
        }
        Node* y = temp->link;
        temp->link = temp->link->link;
        delete y;
        return temp->link;
    }
}

void List :: display()
{
    if(head == NULL)
    {
        cout << "The list is empty" << endl;
    }
    else
    {
        Node* temp = head;
        while(temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->link;
        }
        cout << "NULL" << endl;
    }
}


List List :: alternateSplit()
{
    List l;
    int num = 1;
    if(head == NULL)
    {
        cout << "The list is empty" << endl;
    }
    else
    {
        Node* temp = head;
        while(temp != NULL)
        {
            if(num%2 != 0)
            {
                temp = temp->link;
            }
            else
            {
                l.newEnd(temp->data);
                temp = delMid(temp->data);
            }
            num++;
        }
    }
    return l;
}

int main()
{
    List l1;
    l1.newEnd(10);
    l1.newEnd(20);
    l1.newEnd(10);
    l1.newEnd(20);
    l1.newEnd(10);
    l1.display();
    List l2;
    l2 = l1.alternateSplit();
    l1.display();
    l2.display();



}
