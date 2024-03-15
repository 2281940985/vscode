#include<iostream>
#define eleType int
using namespace std;

class Queen
{
    private:
        eleType* Data;
        int front;
        int rear;
        int capacity;
        void Resize();
    public:
        Queen() : Data(new eleType[capacity]), front(0), rear(0), capacity(10){};
        ~Queen(){};
        void EnQueen(eleType value);
        void DeQueen();
        eleType GetFront();
        int Getsize();
};
void Queen ::Resize()
{
    eleType* NewData = new eleType[capacity*2];
    for (int i = 0; i < capacity; ++i)
    {
        NewData[i] = Data[i];
    }
    delete[] Data;
    capacity = capacity*2;
    Data = NewData;
}
void Queen ::EnQueen(eleType value)
{
    if(rear == capacity)
    {
        Resize();
    }
    Data[rear] = value;
    rear++;

}
void Queen ::DeQueen()
{
    if(front == rear)
    {
        cout << "Queen is empty" << endl;
    }
    //return Data[front];
    front++;
}
eleType Queen ::GetFront()
{
    if(front == rear)
    {
        cout << "Queen is empty" << endl;
    }
    return Data[front];

}
int Queen ::Getsize()
{
    return (rear - front);
}
int main()
{
    Queen q;
    q.EnQueen(3);
    q.EnQueen(4);
    cout << q.GetFront() << endl;
    
    q.EnQueen(5);
    cout << q.GetFront() << endl;
    q.DeQueen();
    cout << q.GetFront() << endl;
    cout << q.Getsize() << endl;
    system("pause");
    return 0;
}