//¶ÑÕ»

#include <iostream>
#include <stdexcept>
using namespace std;
//template<typename T>
#define Eletype int
class Stack
{
private:
    Eletype* Data;
    int Size;
    int Capacity;
    void Resize();
public:
    Stack()
    {
        Size = 0;
        Capacity = 10;
        Data = new Eletype[Capacity];
    }
    ~Stack(){}
    void Push(Eletype vaule);
    Eletype Pop();
    Eletype Top();
    int Getsize();

};
class stack_queue
{
private:
    Stack s1;
    Stack s2;
public:
    stack_queue(){}
    void push(Eletype x)
    {
        s1.Push(x);
    }
    Eletype pop()
    {
        if (s2.Getsize() == 0)
        {
            while (s1.Getsize())
            {
                s2.Push(s1.Pop());
            }
            
        }
        return s2.Pop();
        
    }
    Eletype peek()//»ñÈ¡Õ»¶¥ÔªËØ
    {
        if (s2.Getsize() == 0)
        {
            while (s1.Getsize())
            {
                s2.Push(s1.Pop());
            }
            
        }
        return s2.Top();
    }
    bool empty()
    {
        return s1.Getsize() && s2.Getsize();
    }
    ~stack_queue(){}
};



void Stack ::Resize()
{
    int NewCapacity = Capacity*2;
    Eletype* NewData = new Eletype[NewCapacity];
    for (int i = 0; i < Size; ++i)
    {
        NewData[i] = Data[i];
    }
    delete Data;
    Data = NewData;
    Capacity = NewCapacity;
}
void Stack :: Push(Eletype vaule)
{
    if (Size == Capacity)
    {
        Resize();
    }
    Data[Size] = vaule;
    ++Size;
}
Eletype Stack::Pop()
{
    if (Size == 0)
    {
        cout << "Stack is empty" << endl;
    }
    return Data[--Size];
}
Eletype Stack :: Top()
{
   if (Size == 0)
    {
        cout << "Stack is empty" << endl;
    }
    return Data[Size -1];  
}
int Stack ::Getsize()
{
    return Size;
}
int main()
{
    stack_queue sq;
    sq.push(3);
    sq.push(4);
    sq.push(5);
    sq.push(6);
    cout << sq.empty() << endl;
    cout << sq.peek() << endl;
    cout << sq.pop() << endl;

    system("pause");
    return 0;
}




