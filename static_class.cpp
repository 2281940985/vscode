#include <iostream>
using namespace std;

class Cpoint{
    public:
        static int value;//��̬��Ա���������У����������ⲿ���÷�Χ�������������
        static int num;
    Cpoint(int x,int y){
        xp=x;yp=y;
        value++;
        cout << "���ù���:" << value << endl;
    }

    ~Cpoint(){num++; cout << "��������:" << num << endl;}

    private:
    int xp,yp;
};

int Cpoint::value=0;//��ʼ����̬�����
int Cpoint::num=0;
class CRect{
    public:
        CRect(int x1,int x2):mpt1(x1,x2),mpt2(x1,x2) {cout << "���ù���\n";}
        ~CRect(){cout << "��������\n";}
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