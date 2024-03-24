#include<iostream>
#include<string>
using namespace std;
template<typename T>
void Print(T value)
{
    cout << value << endl;
}

template< typename T, int N>//模板指定了两个参数，类型T、整数N，T用来指定m_Arry的类型：int,float,string ...
class Arry                 //N用来指定数组的大小，
{
private:
    T m_Arry[N];
public:
    int GetSize() const { return N; }
};

int main()
{
    Print(5);//Print<int>(5)，<>里的内容就是模板的指定的类型
    Print("Hello,InitialZ");
    Print(5.5f);

    Arry<std :: string, 5> arry;//<>里指定模板的参数，第一个为类型，第二个为整数
    cout << arry.GetSize() << endl;

    system("pause");
    return 0;
}