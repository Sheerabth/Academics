#include <iostream>

using namespace std;

template <class T>
class Queue
{
    T *queue;
    int size;
    int rear;
    int front;
public:
    Queue(int);
    void enqueue(T);
    T dequeue();
    void peek();
};

template <class T>
Queue<T> :: Queue(int size)
{
    this->size = size;
    queue = new T [size];
    front = rear = -1;
}

template <class T>
void Queue<T> :: enqueue(T val)
{
     if(rear+1 == size)
    {
        cout << "Queue is FULL" << endl;
        return;
    }
    rear += 1;
    queue[rear] = val;
}

template <class T>
T Queue<T> :: dequeue ()
{
    if(rear == front)
    {
        cout << "Queue is EMPTY" << endl;
        return 0;
    }
    front += 1;
    return queue[front];
}

template <class T>
void Queue<T> :: peek()
{
    if (front == rear)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "\nThe Queue is " << endl;
    T val;
    Queue <T>s(size);
    int var = rear+1;
    for(int i = front; i < var; i++)
    {
        val = dequeue();
        s.enqueue(val);
    }
    for(int i = front; i < var; i++)
    {
        val = s.dequeue();
        cout << val <<" ";
        enqueue(val);
    }
    cout << endl << endl;
}

int main()
{
    int val;
    int size;
    int num;
    cout << "Please enter the size of the queue" << endl;
    cin >> size;
    Queue <int>a(size);
    bool out = false;
    while(!out)
    {
        cout << "1. enqueue" << endl;
        cout << "2. dequeue" << endl;
        cout << "3. peek" << endl;
        cout << "4. exit" << endl;
        cin >> num;
        switch(num)
        {
            case 1: cout << "\n\nPlease enter the value you want to push" << endl;
                    cin >> val;
                    a.enqueue(val);
                    a.peek();
                        break;
            case 2: a.dequeue();
                    a.peek();
                        break;
            case 3: a.peek();
                        break;
            case 4: out = true;
                        break;
            default: cout << "Incorrect value entered" << endl;
        }
    }
}
