#include<iostream>
#include<cstring>

using namespace std;

class String
{
private:
    unsigned int m_Size;
    char* m_Buffer;
public:
    String(const char* string)
    {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, string, m_Size);
        m_Buffer[m_Size] = 0;
    }

    String(const String& Other)//c++提供的拷贝构造函数，相当于 : m_Buffer(Other.m_Buffer), m_Size(Other.m_Buffer)
//但是这样仍然是浅层拷贝，因此还需要继续完善拷贝构造函数
    {   m_Size = Other.m_Size;
        m_Buffer = new char[Other.m_Size + 1];
        memcpy(m_Buffer, Other.m_Buffer, Other.m_Size + 1);
        cout << "Copied" << endl;
    }//这才是深拷贝，在进行类复制时会自动调用class的拷贝构造函数，因此这样不会造成程序崩溃。

    ~String()
    {
        delete[] m_Buffer;
    }

    char& operator[](unsigned int index)
    {
        return m_Buffer[index];
    }
    friend ostream& operator<<(ostream& stream, const String& string);//申明函数为友元，该函数可以在类外部访问私有变量
};
//传入引用时要进可能的使用const,因为可以在函数内部决定是否要在复制，没必要在每次调用函数都要复制一遍
void PrintString(String string)//此处传入引用可以减少调用拷贝构造函数次数，因为该函数是直接传入string的一个副本，每执行一次，都要调用拷贝构造函数
{
    cout << string << endl;//重载运算符<<是类的友元函数，可以直接调用类的私有成员。因此该函数PrintString()不需要声明为友元函数
}

ostream& operator<<(ostream& stream, const String& string)
{
    stream << string.m_Buffer; 
    return stream;
}
struct Vector
{
    float x, y;
};



int main()
{
    Vector a1 = {2, 3};
    Vector b1= a1;//将a复制给了b，但是a与b是两个独立的变量，存储在相互独立的区域。改变b的值不影响a

    Vector* a2 = new Vector();
    Vector* b2 = a2;//将a2这个指针存储的的地址复制给b2，修改b2的值不影响a2，但a2与b2都指向同一块内存区域
    b2 ->x = 3;//此时a2 ->x也被修改为3；

    String s1("InitialZ");
    //Copied 1:
    PrintString(s1);//不能写cout << s1.m_Buffer,因为重载运算符时，传入的参数类型是String类，而不是类成员
    //浅拷贝：Copied 2:
    String s2 = s1;//将s1的成员打包复制给了s2，但是m_Buffer是指针，存储的是地址，因此复制过后，s1，s2的m_Buffer指向相同的地方
    //因此最后执行析构函数时，s1中的delete[]已经回收了m_Buffer的内存，而此时s2的delete[]又试图回收已经不属于程序的内存，所以崩溃
    s2[2] = 'a';
    //Copied 3:
    PrintString(s2);
    //Copied 4:
    PrintString(s1);//当改变s2的m_Buffer，同时也会改变s1的，因为二者指向同一块内容。
    system("pause");
    return 0;

}