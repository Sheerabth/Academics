#include <iostream>

using namespace std;

template <class T>
class Stack
{
    T *stack;
    int size;
    int top;
public:
    Stack(int);
    void push(T);
    T pop();
    void peek();
};

template <class T>
Stack<T> :: Stack(int size)
{
    this->size = size;
    stack = new T [size];
    top = -1;
}

template <class T>
void Stack<T> :: push (T val)
{
    if(top+1 == size)
    {
        cout << "Stack is FULL" << endl;
        return;
    }
    top += 1;
    stack[top] = val;
}

template <class T>
T Stack<T> :: pop ()
{
    if(top == -1)
    {
        cout << "Stack is EMPTY" << endl;
        return 0;
    }
    top -= 1;
    return stack[top+1];
}

template <class T>
void Stack<T> :: peek()
{
    if (top == -1)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "\nThe stack is " << endl;
    T val;
    Stack <T>s(size);
    int var = top+1;
    for(int i = 0; i < var; i++)
    {
        val = pop();
        s.push(val);
    }
    for(int i = 0; i < var; i++)
    {
        val = s.pop();
        cout << val <<" ";
        push(val);
    }
    cout << endl << endl;
}

int main()
{
    int val;
    int size;
    int num;
    cout << "Please enter the size of the stack" << endl;
    cin >> size;
    Stack <int>a(size);
    bool out = false;
    while(!out)
    {
        cout << "1. push" << endl;
        cout << "2. pop" << endl;
        cout << "3. peek" << endl;
        cout << "4. exit" << endl;
        cin >> num;
        switch(num)
        {
            case 1: cout << "\n\nPlease enter the value you want to push" << endl;
                    cin >> val;
                    a.push(val);
                    a.peek();
                        break;
            case 2: a.pop();
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
