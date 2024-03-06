#include <iostream>
using namespace std;

class Cpoint{
    public:
        static int value;//静态成员声明在类中，定义在类外部，用范围解析运算符：：
        static int num;
    Cpoint(int x,int y){
        xp=x;yp=y;
        value++;
        cout << "调用构造:" << value << endl;
    }

    ~Cpoint(){num++; cout << "调用析构:" << num << endl;}

    private:
    int xp,yp;
};

int Cpoint::value=0;//初始化静态类变量
int Cpoint::num=0;
class CRect{
    public:
        CRect(int x1,int x2):mpt1(x1,x2),mpt2(x1,x2) {cout << "调用构造\n";}
        ~CRect(){cout << "调用析构\n";}
    private:
        Cpoint mpt1,mpt2;
};

int main()
{
    CRect p(10,20);
    cout << "Hello, world!" << endl;
    system("pause");
    return 0;
}