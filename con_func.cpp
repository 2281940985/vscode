/*��Ĺ��캯�������һ������ĳ�Ա������������ÿ�δ�������¶���ʱִ�С�
���캯���������������������ȫ��ͬ�ģ�
���Ҳ��᷵���κ����ͣ�Ҳ���᷵�� void�����캯��������ΪĳЩ��Ա�������ó�ʼֵ��*/
#include <iostream>
using namespace std;
class Line
{
    public:
        void set_Length(double len);
        double get_Length(void);
        Line(double len);//���캯��,Ĭ�ϵĹ��캯��û���κβ�����
        //�������Ҫ�����캯��Ҳ���Դ��в����������ڴ�������ʱ�ͻ�����󸳳�ʼֵ��
        ~Line();//destructor ����������ÿ��ɾ���������Ķ���ʱִ�������᷵���κ�ֵ��Ҳ���ܴ����κβ�����
        //�����������������������򣨱���ر��ļ����ͷ��ڴ�ȣ�ǰ�ͷ���Դ��
    private:
    double length;
};
Line :: Line(double len)
{
    
    length = len;
    cout << "���캯���Ѿ�ִ�� length = " << length << endl;
} 
Line :: ~Line(void)
{
    cout << "���������Ѿ�ִ��,������ɾ��" << endl; 
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
    Line line(10.54);//�������Ĺ��캯������������ʱҪ������ֵ�����������
    line.set_Length(193.4);
    cout << line.get_Length() << endl;
    getchar();
    //system("pause");
    return 0;//������������ִ����Ϻ�ִ��
}

