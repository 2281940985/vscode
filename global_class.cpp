#include<iostream>
using namespace std;

int year = 55;   //ȫ�ֱ���
int month = 56;
int day = 57;

void Set(int y, int m,int d)  //ȫ�ֺ���
{
    year=y;     //��ȫ�ֱ�����ֵ
    month=m;
    day=d;    
}

void PPP()  //ȫ�ֺ���
{
    cout << "*****global*****" << endl;
    cout << year << " " << month  << " " << day << endl;
}
class TimeDate
{
    public:
        void Set(int y,int m,int d)  //��Ա����
        {
            year=y;     //����Ա������ֵ
            ::month=m;  //��ȫ�ֱ�����ֵ
            day=d;
            //ʹ��::������ȫ�ֺ���
            //��ʹ��:: ���ȳ�Ա������ȫ�ֺ�����˳����Һ���
            ::PPP();  //ʹ��ȫ�ֺ����������ǳ�Ա����
            PPP();    //ʹ�ó�Ա������������ȫ�ֺ���
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
        int year;  //��Ա����
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