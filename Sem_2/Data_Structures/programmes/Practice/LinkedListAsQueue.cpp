#include<iostream>
using namespace std;

class Node
{
    int data;
    Node* link;
    public:
    Node(int);
    friend class Queue;
};

Node :: Node (int d)
{
    data = d;
    link = NULL;
}

class Queue
{
    Node* head;
    public:
    Queue();
    void enqueue(int);
    int dequeue();
    void display();
};

Queue :: Queue()
{
    head = NULL;
}

void Queue :: enqueue(int d)
{
    Node* ins = new Node (d);
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
        temp -> link = ins;
    }
}

int Queue :: dequeue()
{
    if(head == NULL)
    {
        cout << "The queue is empty" << endl;
    }
    else
    {
        Node* temp = head;
        head = head->link;
        delete temp;
    }
}

void Queue :: display()
{

    if(head == NULL)
    {
        cout << "The Queue is empty" << endl;;
    }

    else
    {

        Node* temp = head;
        while(1)
        {
            cout << temp->data << " - " ;
            temp = temp->link;
            if(temp == NULL)
                break;
        }
        cout << "NULL" << endl;
    }
}

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();
}
