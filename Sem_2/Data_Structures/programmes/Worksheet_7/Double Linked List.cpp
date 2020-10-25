#include <iostream>
using namespace std;

class Node
{
        int data;
        Node *next;
        Node *prev;
        static Node *head;
        public:
        Node(int);
        void newBegin(int);
        void newMidAfter(int, int);
        void newMidBefore(int, int);
        void newEnd(int);
        void delBegin();
        void delMid(int);
        void delMidAfter(int);
        void delMidBefore(int);
        void delEnd();
        void display();
};

Node* Node::head=NULL;

Node::Node(int d)
{
        data = d;
        prev = NULL;
        next = NULL;
}

void Node::newBegin(int val)
{
        Node *ins = new Node(val);
        if(head == NULL)
        {
                head = ins;
        }
        else
        {
                Node* temp = head;
                ins->next = temp;
                temp->prev = ins;
                head = ins;
        }
}

void Node::newMidAfter(int val, int d)
{
        Node* ins = new Node(val);
        if(head == NULL)
        {
                head = ins;
        }
        else
        {
                Node* temp = head;
               while(temp->data != d)
                {
                        temp = temp->next;
                }
                ins->prev = temp;
                ins->next = temp->next;
                temp->next->prev = ins;
                temp->next = ins;
        }
}

void Node::newMidBefore(int val, int d)
{
        Node* ins = new Node(val);
        if(head == NULL)
        {
                head = ins;
        }
        else
        {
                Node* temp = head;
                while(temp->next->data != d)
                {
                        temp = temp->next;
                }
                ins->prev = temp;
                ins->next = temp->next;
                temp->next->prev = ins;
                temp->next = ins;
        }
}

void Node::newEnd(int val)
{
        Node* ins = new Node(val);
        if(head == NULL)
        {
                head = ins;
        }
        else

        {
                Node *temp = head;
                while(temp->next != NULL)
                {
                        temp = temp->next;
                }
                temp->next = ins;
                ins->prev = temp;
        }
}

void Node::delBegin()
{
        if(head == NULL)
        {
                cout<<"No nodes left to delete"<<endl;
        }
        else
        {
                Node *temp = head;
                temp->next->prev = NULL;
                head = temp->next;
                delete temp;
        }
}

void Node::delMid(int d)
{
         if(head == NULL)
        {
                cout<<"No nodes left to delete"<<endl;
        }
        else if(head->data == d)
        {
                Node *temp = head;
                head = temp->next;
                temp->next->prev = NULL;
                delete temp;
        }
        else
        {
                Node *temp = head;
                while(temp->data != d)
                {
                        temp = temp->next;
                }
                if(temp->next == NULL)
                {
                    temp->prev->next = NULL;
                    delete temp;
                    return;
                }
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                delete temp;
        }
}

void Node::delMidAfter(int d)
{
        int flag = 0;
        if(head == NULL)
        {
                cout<<"No nodes left to delete"<<endl;
        }
        else if(head->next == NULL && head->data == d)
        {
            cout << "No Node to delete"<<endl;
        }
        else if(head->data == d)
        {

                Node *temp = head->next;
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
        }
        else
        {
                Node *temp = head;
                while(temp->data != d)
                {
                        temp = temp->next;
                }
                temp->next = temp->next->next;
                temp->next->next->prev = temp->next->prev;
                //temp->prev->next = temp->next;
                //temp->next->prev = temp->prev;
                delete temp->next;
        }
}

void Node::delMidBefore(int d)
{
        if(head == NULL)
        {
                cout<<"No nodes left to delete"<<endl;
        }
        else if(head->data == d)
        {
                cout<<"NO node is PRESENT before the given data"<<endl;
        }
        else if(head->next->data == d)
        {
                Node *temp = head;
                head = temp->next;
                temp->next->prev = NULL;
                delete temp;
        }
        else
        {
                Node *temp = head;
                while(temp->next->data != d)
                {
                        temp = temp->next;
                }
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                delete temp;
        }
}

void Node::delEnd()
{
        if(head == NULL)
        {
                cout<<"No nodes left to delete"<<endl;
        }
        else
        {
                Node *temp = head;
                while(temp->next != NULL)
                {
                        temp = temp->next;
                }
                temp->prev->next = NULL;
                delete temp;
        }
}

void Node::display()
{
        Node* temp;
        if(head == NULL )
        {
                cout << "The list is empty" << endl;
        }
        else
        {
                temp = head;
                while(true)
                {
                        cout << temp->data << "->";
                        if(temp->next ==NULL)

                                break;
                        temp = temp->next;
                }
                cout << "NULL" << endl;
        }
}

int main()
{
        Node obj(10);
        obj.newEnd(10);
        obj.newEnd(20);
        obj.newEnd(30);
        obj.newEnd(40);
        obj.newEnd(50);
        obj.newEnd(60);
        obj.delMidAfter(30);
        obj.display();
}
//DEL MIDAFTER
