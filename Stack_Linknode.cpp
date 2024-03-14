#include <iostream>
using namespace std;
#define eleType int
class Stack
{
    private:
        struct Node
        {
            eleType Data;
            Node *Next;
            Node(eleType d) : Data(d), Next(NULL){};
        };
        Node *Head;
        int Size;
    public:
        Stack() : Head(NULL), Size(0) {};
        ~Stack(){};
        void push(eleType element);
        eleType pop();
        eleType top();
        int GetSize(); 

};
void Stack::push(eleType element)
{
    Node *NewNode = new Node(element);
    if(NewNode == NULL)
    {
        cout << "Stack is full" << endl;
        return;
    }
    NewNode->Next = Head;
    Head = NewNode;
    Size++;
}
eleType Stack::pop()
{
    if(Head == NULL)
    {
        cout << "Stack is empty" << endl;
    }
    Node *temp = Head;
    Head = Head->Next;
    Size--;
    return temp->Data;
}
eleType Stack::top()
{
    if(Head == NULL)
    {
        cout << "Stack is empty" << endl;
    }
    return Head->Data;
}
int Stack::GetSize()
{
    return Size;
}
int main()
{
    Stack s;
    s.push(4);
    s.push(7);
    s.push(13);
    s.push(17);
    s.pop();
    s.pop();
    cout << s.GetSize() << endl;
    cout << s.top() << endl;
    system("pause");
    return 0;
}

