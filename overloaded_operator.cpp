//�ǳ�Ա���������������
//��ȡ���ӵ�����������
#include <iostream>
using namespace std;
class BOX
{
    private:
        double length;double width;double height;
    public:
        double GetVolume();
        BOX(double l,double w,double h);
        friend double operator+( BOX& box1,  BOX& box2);//������Ԫ�������������������Ķ���
        ~BOX()//���������+����������Ϊdouble�ͣ�����Ϊ����BOX����
        {
            cout << "����������ִ��"<< endl;
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
    return (box1.GetVolume() + box2.GetVolume());//����������ĺ������壬����������������ĺ�    
}
int main()
{
    BOX box1(3.4,6.9,9.654);
    BOX box2(2.3,5.7,8.46);//���ù��캯����ʼ�����Ա
    cout << box1 + box2 << endl;
    system("pause");
    return 0;
}