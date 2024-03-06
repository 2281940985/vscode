/*类的构造函数是类的一种特殊的成员函数，它会在每次创建类的新对象时执行。
构造函数的名称与类的名称是完全相同的，
并且不会返回任何类型，也不会返回 void。构造函数可用于为某些成员变量设置初始值。*/
#include <iostream>
using namespace std;
class Line
{
    public:
        void set_Length(double len);
        double get_Length(void);
        Line(double len);//构造函数,默认的构造函数没有任何参数，
        //但如果需要，构造函数也可以带有参数。这样在创建对象时就会给对象赋初始值，
        ~Line();//destructor 析构函数，每次删除所创建的对象时执行它不会返回任何值，也不能带有任何参数。
        //析构函数有助于在跳出程序（比如关闭文件、释放内存等）前释放资源。
    private:
    double length;
};
Line :: Line(double len)
{
    
    length = len;
    cout << "构造函数已经执行 length = " << length << endl;
} 
Line :: ~Line(void)
{
    cout << "析构函数已经执行,对象已删除" << endl; 
}
void Line :: set_Length(double len)
{
    length = len;

}
double Line :: get_Length(void)
{
    return length;
}
int main()
{
    Line line(10.54);//带参数的构造函数，创建对象时要给对象赋值，即传入参数
    line.set_Length(193.4);
    cout << line.get_Length() << endl;
    getchar();
    //system("pause");
    return 0;//析构函数在类执行完毕后执行
}

