#include<iostream>
using namespace std;

int year = 55;   //全局变量
int month = 56;
int day = 57;

void Set(int y, int m,int d)  //全局函数
{
    year=y;     //给全局变量赋值
    month=m;
    day=d;    
}

void PPP()  //全局函数
{
    cout << "*****global*****" << endl;
    cout << year << " " << month  << " " << day << endl;
}
class TimeDate
{
    public:
        void Set(int y,int m,int d)  //成员函数
        {
            year=y;     //给成员变量赋值
            ::month=m;  //给全局变量赋值
            day=d;
            //使用::表明是全局函数
            //不使用:: 按先成员函数后全局函数的顺序查找函数
            ::PPP();  //使用全局函数，而不是成员函数
            PPP();    //使用成员函数，而不是全局函数
        }
        void PPP()
        {
            cout << "*****local*****" << endl;
            cout << year << " " << month  << " " << day << endl;
        }
        void PPP1()
        {
            cout << "*****local->global*****" << endl;
            cout << ::year << " " << ::month  << " " << ::day << endl;
        }
    private:
        int year;  //成员变量
        int month;
        int day;
};

int main(int argc, const char** argv) {
    TimeDate t;
    cout << "origin value" << endl;
    t.PPP();
    t.PPP1();
    PPP();
    cout << "after global function Set  work" << endl;
    Set(1,2,3);
    t.PPP();
    PPP();
    cout << "after member function Set work" << endl;
    t.Set(4,5,6);
    t.PPP();
    PPP();
    cout << "program end" << endl;
    return 0;
}