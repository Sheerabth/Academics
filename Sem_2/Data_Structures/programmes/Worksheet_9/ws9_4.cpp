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
    void delMid(int d);
    List shuffleMerge(List);
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

List List :: shuffleMerge(List l)
{
    List merge;
    if(head == NULL || l.head == NULL)
    {
        cout << "One of the list is empty";
    }

    else
    {
        Node* temp1 = head;
        Node* temp2 = l.head;
        int num = 1;
        while(temp2 != NULL)
        {
            if(num%2 == 1)
            {
                merge.newEnd(temp1->data);
                temp1 = temp1->link;
            }
            else
            {
                merge.newEnd(temp2->data);
                temp2 = temp2->link;
            }
            num++;
        }
    }
    return merge;
}

int main()
{
    List l1;
    l1.newEnd(10);
    l1.newEnd(30);
    l1.newEnd(50);
    l1.display();
    List l2;
    l2.newEnd(20);
    l2.newEnd(40);
    l2.newEnd(60);
    l2.display();
    List l3;
    l3 = l1.shuffleMerge(l2);
    l3.display();
}
