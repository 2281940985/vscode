#include<iostream>
#define eleType int
using namespace std;

class Queen_linknode
{
private:
    struct Node
    {
        eleType Data;
        Node* Next;
        Node(eleType d) : Data(d), Next(nullptr){}
    };
    Node* Front;
    Node* Rear;
    int Size;
public:
     
    Queen_linknode() : Front(nullptr), Rear(nullptr), Size(0) {}
    ~Queen_linknode(){}
    void EnQueen(eleType value);
    eleType DeQueen();
    eleType GetFront();
    int GetSize();
};
void Queen_linknode ::EnQueen(eleType value)
{
    if (Rear == nullptr)
    {
        Rear = new Node(value);
        Front = Rear;
    }
    else
    {
        Rear ->Next = new Node(value);
        Rear = Rear ->Next;
    }
    ++Size;

}
eleType Queen_linknode ::DeQueen()
{
    if(Front == nullptr)
    {
        cout << "Queen is empty" << endl;
    }
    eleType value = Front ->Data;
    Node* temp = Front;
    Front = Front ->Next;
    delete temp;
    Size--; 
    return value;

}
eleType Queen_linknode ::GetFront()
{
    if(Front == nullptr)
    {
        cout << "Queen is empty" << endl;
    }
    return Front ->Data;
}
int Queen_linknode ::GetSize()
{
    return Size;
}

int main()
{
    Queen_linknode q;
    q.EnQueen(3);
    q.EnQueen(4);
    cout << q.GetFront() << endl;
    q.EnQueen(5);
    q.DeQueen();
    cout << q.GetFront() << endl;
    cout << q.GetSize() << endl;
    system("pause");
    return 0;
}