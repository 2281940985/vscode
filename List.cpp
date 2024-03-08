//ʵ��˳������ɾ�Ĳ鹦��
#include <iostream>
using namespace std;
#define eleType int
class SequentiaList
{
    public:
        eleType* elements;
        int size;
        int capacity;
        SequentiaList(int capacity)//���캯������ʼ��
        {
            elements = new eleType[capacity];//�����ڴ�ռ�
            size = 0;
            this->capacity = capacity;
        }
        ~SequentiaList()//��������
        {
            cout << "����������ִ��" << endl;
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
        cout << "�����Ƿ�" << endl;
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
        cout << "�����Ƿ�" << endl;
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
        cout << "�����Ƿ�" << endl;
    }
    else return list->elements[index];
}
void UpdateElement(SequentiaList* list, int index, eleType vaule)
{
    if (index < 0||index >= list->size)
    {
        cout << "�����Ƿ�" << endl;
    }
    else list->elements[index] = vaule;
}

int main()
{
    SequentiaList MyList(10);
    for (int i = 0; i < 10; i++)
    {
        Insert(&MyList, i, i*10);
    }
    cout << "˳����С��" << Size(&MyList) << endl;
    cout << "�Ƿ�Ϊ�գ�" << IsEmpty(&MyList) << endl;
    for(int i = 0; i < Size(&MyList); ++i)
    {
        cout << GetElement(&MyList,i) << " ";
    }
    cout << endl;
    Delete(&MyList,5);
    UpdateElement(&MyList, 1, 1314);
    for(int i = 0; i < Size(&MyList); ++i)
    {
        cout << GetElement(&MyList,i) << " ";
    }
    cout << endl;
    cout << FindElement(&MyList, 90) << endl;
    system("pause"); 
    return 0;
} 

