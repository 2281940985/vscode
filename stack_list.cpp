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
    ~Stack(){};
    void Push(Eletype vaule);
    Eletype Pop();
    Eletype Top();
    int Getsize();

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
    Size--;
    return Data[Size - 1];
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
    Stack st;
    st.Push(4);
    st.Push(7);
    st.Push(13);
    cout << st.Top() << endl;
    st.Push(17);
    cout << st.Top() << endl;
    st.Pop();
    st.Pop();
    cout << st.Top() << endl;
    cout << st.Getsize() << endl;
    system("pause");
    return 0;
}




