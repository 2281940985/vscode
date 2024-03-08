//通过顺序表的增删改查功能实现输入奇数的乘积
#include <iostream>
using namespace std;
#define eleType int
class SequentiaList
{
    public:
        eleType* elements;
        int size;
        int capacity;
        SequentiaList(int capacity)
        {
            elements = new eleType[capacity];
            size = 0;
            this->capacity = capacity;
        }
        ~SequentiaList()
        {
            cout << "析构函数已执行" << endl;
        }
};

int Size(SequentiaList* list)
{
    return list->size;
}
bool IsEmpty(SequentiaList* list)
{
    return list->size == 0;
}
void Insert(SequentiaList* list, int index, eleType element)
{
    if (index < 0||index > list->size)
    {
        cout << "索引非法" << endl;
    }
    if (list->size == list->capacity)
    {
        int NewCapacity = list->capacity * 2;
        eleType* NewElements = new eleType[NewCapacity];
        for (int i = 0; i < list->size; ++i)
        {
            NewElements[i] = list->elements[i];
        }
        delete[] list->elements;
        list->elements = NewElements;
        list->capacity = NewCapacity;
    }
    for (int i =list->size; i > index; --i)
    {
        list->elements[i] = list->elements[i-1];
    }
    list->elements[index] = element;
    list->size++;
}
void Delete(SequentiaList* list,int index)
{
    if (index < 0||index >= list->size)
    {
        cout << "索引非法" << endl;
    }
    for(int i = index; i < list->size-1; ++i)
    {
        list->elements[i] = list->elements[i+1];
    }
    list->size--;
}
int FindElement(SequentiaList* list, eleType element)
{
    for (int i = 0; i < list->size; ++i)
    {
        if(list->elements[i] == element)
        {
            return i;
        }
    }
    return -1;
}
eleType GetElement(SequentiaList* list, int index)
{
    if (index < 0||index >= list->size)
    {
        cout << "索引非法" << endl;
    }
    else return list->elements[index];
}
void UpdateElement(SequentiaList* list, int index, eleType vaule)
{
    if (index < 0||index >= list->size)
    {
        cout << "索引非法" << endl;
    }
    else list->elements[index] = vaule;
}

int main()
{
    int n;
    int result = 1;
    while (cin >> n)
    {
        SequentiaList s(n);
        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            Insert(&s, i, x);//Size(&s) = n

        }
        for(int i =0; i < Size(&s); ++i)
        {
            int val = GetElement(&s,i);
            if (val % 2 == 1)
            {
                result = result * val;
            } 
        }
        cout << result;
        system("pause");
    }
    return 0;
}