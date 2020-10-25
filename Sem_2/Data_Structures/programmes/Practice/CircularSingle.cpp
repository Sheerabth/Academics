#include <iostream>
using namespace std;

class Node
{
    int data;
    Node* next;
    Node* prev;
    public:
    Node(int);
    friend class List;
};

Node :: Node(int d)
{
    data = d;
    next = NULL;
    prev = NULL;
}

class CircularList
{
    Node* head;
    public:
    CircularList();
    void newBegin(int);
    void newEnd(int);

    void delBegin();

    void delEnd();
};

CircularList :: CircularList()
{
    head = NULL;
}

void CircularList :: newBegin(int d)
{
    Node* temp = head;
     if(head == NULL)
     {
         head = ins;
     }
     else
     {
         Node*  temp = head;
         while(temp->next == head)
         {
             temp = temp->next;
         }
         temp -> next = ins;
         ins->prev = temp;
         ins->next = head;
         head = ins;
     }
}

void CircularList :: new End(int d)
{

}
