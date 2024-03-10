//实现顺序表的增删改查功能
#include <iostream>
#include <iomanip>  //不要忘了头文件
using namespace std;
#define eleType double
class SequentiaList
{
    public:
        eleType* elements;
        int size;
        int capacity;
        SequentiaList(int capacity)//构造函数，初始化
        {
            elements = new eleType[capacity];//分配内存空间
            size = 0;
            this->capacity = capacity;
        }
        ~SequentiaList()//析构函数
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
   while (cin >> n && (2 < n <= 100))
   {
    SequentiaList s(n);
    for (int i = 0; i < n; ++i)
    {
        eleType x;
        cin >> x;
        Insert(&s,i,x);
    }
    eleType eMax = -1000000;
    eleType eMin = 1000000;
    eleType sum;
    for (int i = 0; i < n; ++i)
    {
        if (GetElement(&s,i) > eMax)
        {
            eMax = GetElement(&s,i);
        }
        if (GetElement(&s,i) < eMin)
        {
            eMin = GetElement(&s,i);
        }
        sum+=GetElement(&s,i);
        
    }
    sum-=eMin;
    sum-=eMax;
    sum = sum/(n-2);
    cout<<setiosflags(ios::fixed)<<setprecision(2);//保留两位小数
    cout << sum << endl;
	
	

   }
    
    system("pause"); 
    return 0;
} 

