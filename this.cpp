/* this��һ�����ص�ָ�룬��������ĳ�Ա������ʹ�ã�����������ָ����ö���
��Ԫ����û�� this ָ�룬��Ϊ��Ԫ������ĳ�Ա��ֻ�г�Ա�������� this ָ�롣
ʹ�� this ָ�������õ�ǰ����ĳ�Ա���� v�������������βδ����ֵ��������
����������ȷ�ظ��߱�����������Ҫ���ʵ�ǰ����ĳ�Ա�����������Ǻ���������ֲ����� */
//�Ƚϳ�����������
#include <iostream>
using namespace std;
class Box
{
    public:
        Box(double l, double w ,double h );//���캯��������������ʼ��
        double volume ();
        bool compare(Box box);
        ~Box();//������������
    private:
    double length;
    double width;
    double height;
};
Box :: Box(double l, double w ,double h )
{
    length = l;width = w;height = h;//��ʼ�������
}
Box :: ~Box()//��ִ����ɺ��ͷſռ�
{
    cout << "����������ִ��" << endl;
}
double Box :: volume ()
{
    return length * width * height;
}
bool Box :: compare(Box box)
{
    return this->volume() > box.volume();//thisָ����õ�ǰ������Ա����volume()
} //��compare()���������BOX���͵�volume()�������бȽϡ������ʹ��thisָ�룬��������ͻ��
int main()
{
    Box box1(3.4, 5.6, 7.79);
    Box box2(5.6, 3.7, 6.9);
    if (box1.compare(box2))
    {
        cout << "box1���������box2" << endl;
    }
    else 
    {
        cout << "box2���������box1" << endl;
    }
    system("pause");
    return 0;
}

