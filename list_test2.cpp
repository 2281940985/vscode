//数值统计，n个数中，统计负数，0，正数的个数
#include <iostream>
using namespace std;
#define eleType double
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
    int pcnt = 0, zcnt = 0, mcnt = 0;
    int n;
while (cin >> n&&n)
{
    SequentiaList s(1);
    for (int i =0; i < n; ++i)
    {
        eleType x;
        cin >> x;
        Insert(&s, i, x);
    }
    
    for (int i =0; i < Size(&s); ++i)
    {
        if (GetElement(&s,i) > 1e-8)
        {
            pcnt++;
        }
        else if(GetElement(&s,i) < -1e-8)
        {
            zcnt++;
        }
        else
        {
            mcnt++;
        }
    }

}
cout << "正数："<< pcnt << endl;
cout << "负数："<< zcnt << endl;
cout << "0: " << mcnt << endl;
    
    system("pause"); 
    return 0;
} 

