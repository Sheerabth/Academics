#include<iostream>
using namespace std;

class Node
{
        int data;
        Node *link;
        public:
        Node(int);
        friend class List;
};


Node::Node(int d) {
        data=d;
        link=NULL;
}


class List {
        Node* head;
        public:
        List();
        void newMid(int, int);
        void newEnd(int);
        void delMid(int);
        void delEnd();
        void display();
        List concat(List);
        List order(List);
        void empty();
        void reverse();
        void del(int );
        int number();
        int sum();
        List copy();
        void sort();
        void del2nd();
        List uni(List);
        friend void swap(int*, int*);
};

void List::del(int n)
{
    int check = 0;
    Node* temp = head;
    if(n == 1)
    {
        Node* temp = head;
        head = temp->link;
        delete temp;
        return;
    }
    while(check != n-2)
    {
        temp = temp->link;
        check++;
    }
    //if(temp-)
    Node* y = temp->link;
    temp->link = temp->link->link;
    delete y;
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

}

void List::empty()
{
        while(head != NULL)
        {
                delEnd();
        }
}

void List :: reverse()
{
    Node* temp = head;
    int rcount = 1;
    int fcount = 1;
    while (temp->link != NULL)
    {
        rcount++;
        temp = temp->link;
    }

    int num = rcount;
    int i;
    Node* temp1;
    Node* temp2;
    int t;

    for(; rcount != (num/2); fcount++, rcount--)
    {
        temp1 = head;
        temp2 = head;
       for(i = 1; i<rcount; i++)
       {

           temp1 = temp1->link;

       }
       for(i = 1; i<=fcount-1; i++)
       {

           temp2 = temp2->link;
       }

       swap(temp1->data, temp2->data);


    }

}

List List::concat(List l2)
{
        List con;
        Node* temp;
        temp = this->head;
        while(temp->link != NULL)
        {
                con.newEnd(temp->data);
                temp = temp->link;
        }
         con.newEnd(temp->data);
        temp = l2.head;
        while(temp->link != NULL)
        {
                con.newEnd(temp->data);
                temp = temp->link;
        }
         con.newEnd(temp->data);
        //con.display();
        return con;
}

List :: List() {
        head = NULL;
}

void List::newEnd(int d) {
        Node* ins = new Node(d);
        Node* temp;
        temp = head;
        if(head == NULL)
        {
                head = ins;
        }
        else
        {
                while(temp->link != NULL)
                {
                        temp = temp->link;
                }
                ins->link = temp->link;
                temp->link = ins;
        }
}

void List::newMid(int d, int x)
{
        Node* ins = new Node(d);
        Node* temp;
        temp = head;
        if(head == NULL)
        {
                head = ins;
        }
        else
        {
                while(temp->data != x)
                {
                        temp = temp->link;
                }
                ins->link = temp->link;
                temp->link = ins;
        }
}

void List::delEnd()
{
        Node* temp = head;
         if(head == NULL)
         {
                cout<<"No nodes to delete"<<endl;
         }
        else if(head->link == NULL)
        {
                delete head;
                head = NULL;
        }
        else
        {
                while(temp->link->link != NULL)
                {
                        temp = temp->link;
                }
                Node* Y = temp->link;
                temp->link = NULL;
                delete Y;
        }
}

void List::delMid(int d) {
        Node* temp = head;
        if(head == NULL)
        {
               cout<<"No nodes to delete"<<endl;
        }
        else
        {
                while(temp->data != d)
                {
                        temp = temp->link;
                }
                if(temp -> link == NULL)
                {
                        cout<<"Deletion is not possible as the element is after the last node" << endl;
                }
                else
                {
                        Node *Y = temp->link;
                        temp->link = temp->link->link;
                        delete Y;
                }
        }
}

void List::display() {
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
                        if(temp->link ==NULL)
                                break;
                        temp = temp->link;
                }
                cout << "NULL" << endl;
        }
}

List List::order(List l)
{
    List ord;
    Node* temp1 = head;
    Node* temp2 = l.head;
    while(temp1 != NULL && temp2 != NULL)
    {
        if(temp1->data > temp2->data)
        {
            ord.newEnd(temp2->data);
            temp2 = temp2->link;
        }
        else if(temp1->data < temp2->data)
        {
            ord.newEnd(temp1->data);
            temp1 = temp1->link;
        }
        else
        {
            ord.newEnd(temp1->data);
            ord.newEnd(temp1->data);
            temp1 = temp1->link;
            temp2 = temp2->link;
        }
    }
    if(temp1 == NULL)
    {
        while(temp2 != NULL)
        {
            ord.newEnd(temp2->data);
            temp2 = temp2->link;
        }
    }
    else if(temp2 == NULL)
    {
        while(temp1 != NULL)
        {
            ord.newEnd(temp1->data);
            temp1 = temp1->link;
        }
    }
    return ord;
}

int List :: number()
{
    int i = 0;
    Node* temp = head;
    while(temp->link != NULL)
    {
        i++;
        temp = temp->link;
    }
    return i+1;
}

int List :: sum()
{
    int sum = 0;
    Node* temp = head;
    while(temp->link != NULL)
    {
        sum += temp->data;
        temp = temp->link;
    }
    sum += temp->data;
    cout << sum << endl;
    return sum;
}

List  List :: copy()
{
    List cop;
    Node* temp = head;
    while(temp->link != NULL)
    {
        cop.newEnd(temp->data);
        temp = temp->link;
    }
    cop.newEnd(temp->data);
    return cop;
}

void List :: sort()
{
    Node* temp1 = head;
    Node* temp2 = head->link;
    for(; temp1->link->link != NULL; temp1 = temp1->link)
    {
        for(temp2 = temp1->link; temp2->link != NULL; temp2 = temp2->link)
        {
            if(temp1->data > temp2->data)
            {
                swap(temp1->data, temp2->data);
            }
        }
    }
}

void List :: del2nd()
{
    int val = 2;
    int num;
    int i;
    num = number();
    for(;val != num ; val++)
    {
        del(val);
    }

}

List List :: uni(List l)
{
    List uni;
    uni = concat(l);
    Node* temp1;
    Node* temp2;
    temp1 = head;
    for(;temp1->link->link != NULL ; temp1 = temp1->link)
    {
        cout<<"IN 1"<<endl;
        cout << "Temp 1 pointing to data with " << temp1->data << endl;
        for(temp2 = temp1->link;temp2->link != NULL; temp2 = temp2->link)
        {
            cout<<"IN 2"<<endl;
            cout << "Temp 2 pointing to data with " << temp2->data << endl;
            if(temp1 -> data == temp2 -> data)
            {
                cout<<"IN 3"<<endl;
                uni.delMid(temp1->data);
                continue;
            }
        }
    }
    return uni;

}

int main()
{
        int i;
        List l1;
        l1.newEnd(60);
        l1.newEnd(50);
        l1.newEnd(70);
        l1.newEnd(100);
        l1.display();
        List l2;
        l2.newEnd(30);
        l2.newEnd(20);
        l2.newEnd(100);
        l2.display();
        List l3;
        List l4;
        l4 = l1.uni(l2);
        l4.display();
}
