/* this是一个隐藏的指针，可以在类的成员函数中使用，它可以用来指向调用对象。
友元函数没有 this 指针，因为友元不是类的成员，只有成员函数才有 this 指针。
使用 this 指针来引用当前对象的成员变量 v，并将函数的形参传入的值赋给它，
这样可以明确地告诉编译器我们想要访问当前对象的成员变量，而不是函数参数或局部变量 */
//比较长方体的体积：
#include <iostream>
using namespace std;
class Box
{
    public:
        Box(double l, double w ,double h );//构造函数声明，包含初始化
        double volume ();
        bool compare(Box box);
        ~Box();//析构函数声明
    private:
    double length;
    double width;
    double height;
};
Box :: Box(double l, double w ,double h )
{
    length = l;width = w;height = h;//初始化类参数
}
Box :: ~Box()//类执行完成后释放空间
{
    cout << "析构函数已执行" << endl;
}
double Box :: volume ()
{
    return length * width * height;
}
bool Box :: compare(Box box)
{
    return this->volume() > box.volume();//this指针调用当前变量成员函数volume()
} //和compare()函数传入的BOX类型的volume()函数进行比较。如果不使用this指针，则函数名冲突。
int main()
{
    Box box1(3.4, 5.6, 7.79);
    Box box2(5.6, 3.7, 6.9);
    if (box1.compare(box2))
    {
        cout << "box1的体积大于box2" << endl;
    }
    else 
    {
        cout << "box2的体积大于box1" << endl;
    }
    system("pause");
    return 0;
}

