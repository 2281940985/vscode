#include<iostream>
#include<string>
using namespace std;
template<typename T>
void Print(T value)
{
    cout << value << endl;
}

template< typename T, int N>//ģ��ָ������������������T������N��T����ָ��m_Arry�����ͣ�int,float,string ...
class Arry                 //N����ָ������Ĵ�С��
{
private:
    T m_Arry[N];
public:
    int GetSize() const { return N; }
};

int main()
{
    Print(5);//Print<int>(5)��<>������ݾ���ģ���ָ��������
    Print("Hello,InitialZ");
    Print(5.5f);

    Arry<std :: string, 5> arry;//<>��ָ��ģ��Ĳ�������һ��Ϊ���ͣ��ڶ���Ϊ����
    cout << arry.GetSize() << endl;

    system("pause");
    return 0;
}