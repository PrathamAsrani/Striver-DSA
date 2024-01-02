#include <bits/stdc++.h>

using namespace std;

class Stack
{
    int top, size;

public:
    int *data;
    Stack(int size)
    {
        this->top = -1;
        this->size = size;
        data = new int[size];
    }
    bool isFull();
    bool isEmpty();
    bool push(int data);
    int pop();
    int peek();
};

int main()
{
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << "\nThe peeked element: " << s.peek() << endl;

    cout << "\nThe poped element: " << s.pop() << endl;

    cout << "\nThe peeked element after poping: " << s.peek() << endl;
}

bool Stack::isFull()
{
    if (this->top < this->size - 1)
        return false;
    return true;
}

bool Stack::isEmpty()
{
    if (this->top != -1)
        return false;
    return true;
}

bool Stack::push(int data)
{
    if (this->isFull())
    {
        cout << "Stack Overflow\n";
        return false;
    }
    this->data[++this->top] = data;
    return true;
}

int Stack::pop()
{
    if (this->isEmpty())
    {
        cout << "Stack UNderflow\n";
        return false;
    }
    return this->data[this->top--];
}

int Stack::peek()
{
    if (this->isEmpty())
    {
        cout << "Stack UNderflow\n";
        return false;
    }
    return this->data[this->top];
}