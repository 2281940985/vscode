#include <iostream>
using namespace std;
#define eleType int
class Node
{
    public:
        eleType Data;
        Node* Next;
        Node(eleType d) : Data(d), Next(nullptr){};
        ~Node(){};

};
class Stack
{
    private:
        int Size;
    public:
        Node* Head;
        Stack() : Size(0), Head(nullptr){};
        ~Stack(){};
        void Push(eleType value);
        eleType Pop();
        eleType Top();
        int GetSize();

};

void Stack ::Push(eleType value)
{
    Node* NewNode = new Node(value);
    NewNode ->Next = Head;
    Head = NewNode;
    Size++;
}
eleType Stack ::Pop()
{
    if (Size == 0)
    {
        cout << "Stack is empty" << endl;
    }
    eleType ret = Head ->Data;
    Head = Head ->Next;
    Size--;
    return ret;
}
eleType Stack ::Top()
{
    if (Size == 0)
    {
        cout << "Stack is empty" << endl;
    }
    return Head ->Data;
}
int Stack ::GetSize()
{
    if (Size == 0)
    {
        cout << "Stack is empty" << endl;
    }
    return Size;
}

int main()
{
    Stack s;
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);
    cout << s.Top() << endl;
    s.Pop();
    s.Pop();
    cout << s.Top() << endl;
    cout << s.GetSize() << endl;
    system("pause");
    return 0;
}
