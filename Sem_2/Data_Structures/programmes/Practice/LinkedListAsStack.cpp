#include <iostream>
using namespace std;

class Node
{
    int data;
    Node* link;
    public:
    Node(int);
    friend class Stack;
};

Node :: Node(int d)
{
    data = d;
    link = NULL;
}

class Stack
{
    Node* head;
    public:
    Stack();
    void push(int);
    int pop();
    void display();
};

Stack :: Stack()
{
    head == NULL;
}

void Stack :: push(int d)
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

int Stack :: pop()
{
    if(head == NULL)
    {
        cout << "The Stack is empty" << endl;
    }
    else
    {
        int r;
        Node* temp = head;
        while(temp->link->link != NULL)
        {
            temp = temp->link;
        }
        Node* y = temp->link;
        temp->link = NULL;
        r = y->data;
        delete y;
        return r;
    }
}

void Stack :: display()
{

    if(head == NULL)
    {
        cout << "The list is empty" << endl;;
    }

    else
    {

        Node* temp = head;
        while(1)
        {
            cout << temp->data << " <-> " ;
            temp = temp->link;
            if(temp == NULL)
                break;
        }
        cout << "NULL" << endl;
    }
}

int main()
{
    Stack s;
    cout << "Inside";
    //s.push(10);
    //s.push(20);
    s.push(13)
    cout << "Inside";;
    s.display();
    cout << "Inside";
    //s.pop();
    s.display();
}

