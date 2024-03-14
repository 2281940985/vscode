#include <iostream>
using namespace std;
#define eleType int
class Node
{
    public:
        eleType Data;
        Node* Next;
        Node(eleType d) : Data(d), Next(nullptr);
        ~Node(){};

};
class Stack
{
    private:
        int Size;
    public:
        Node* Head;
        Stack() : Size(0), Head(nullptr);
        ~Stack(){};
        void Push(eleType value);
        eleType Pop();
        eleType Top();
        int GetSize();

};

void Stack ::Push(eleType value)
{
    Node* NewNode = new Node(value);
    NewNode
}
eleType Stack ::Pop()
{

}
eleType Stack ::Top()
{

}
int Stack ::GetSize()
{

}

int main()
{


    return 0
}
