//非成员函数的运算符重载
//获取盒子的体积，并相加
#include <iostream>
using namespace std;
class BOX
{
    private:
        double length;double width;double height;
    public:
        double GetVolume();
        BOX(double l,double w,double h);
        friend double operator+( BOX& box1,  BOX& box2);//申明友元函数，可在类外访问类的对象
        ~BOX()//重载运算符+，返回类型为double型，传入为两个BOX的类
        {
            cout << "析构函数已执行"<< endl;
        }

};
double BOX :: GetVolume()
{
    return length * width* height;
}
BOX :: BOX(double l,double w,double h)
{
    length = l;
    width = w;
    height = h;
}
double operator+( BOX& box1,  BOX& box2)
{
    return (box1.GetVolume() + box2.GetVolume());//重载运算符的函数定义，返回两个盒子体积的和    
}
int main()
{
    BOX box1(3.4,6.9,9.654);
    BOX box2(2.3,5.7,8.46);//利用构造函数初始化类成员
    cout << box1 + box2 << endl;
    system("pause");
    return 0;
}