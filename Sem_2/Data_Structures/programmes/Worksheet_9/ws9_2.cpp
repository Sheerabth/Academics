#include<iostream>

using namespace std;

class Node
{
    int data;
    Node* link;
    public:
    Node(int);
    friend class List;
};


Node::Node(int data)
{
    this->data = data;
    link = NULL;
}

class List
{
    Node* head;
    public:
    List();
    void newEnd(int d);
    void delMid(int d);
    void removeDuplicates();
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

void List :: delMid(int d)
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

void List :: removeDuplicates()
{

    Node* temp = head;
    if(head == NULL)
    {
        cout << "The list is empty" << endl;
    }
    else
    {
        while(temp->link != NULL)
        {
            int flag = 0;
            //cout << "inside while" << endl;
            //cout << "Temp pointing to " << temp->data << endl;
            if(temp->data == temp->link->data)
            {
                flag = 1;
                temp = temp->link;
                delMid(temp->data);

            }
            if(flag == 0)
                temp = temp->link;
        }
    }
}

int main()
{
    List l;
    l.newEnd(10);
    l.newEnd(20);
    l.newEnd(20);
    l.newEnd(30);
    l.newEnd(30);
    l.newEnd(30);
    l.newEnd(30);
    l.newEnd(40);
    l.newEnd(40);
    l.newEnd(40);
    l.newEnd(40);
    l.newEnd(40);
    l.newEnd(50);
    l.newEnd(50);
    l.newEnd(50);
    //l.delMid(20);
    l.display();
    l.removeDuplicates();
    l.display();
}
