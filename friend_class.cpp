/* �����Ԫ�����Ƕ��������ⲿ������Ȩ�����������˽�У�private����Ա�ͱ�����protected����Ա��
������Ԫ������ԭ��������Ķ����г��ֹ���������Ԫ���������ǳ�Ա������
��Ԫ������һ���������ú�������Ϊ��Ԫ������
��ԪҲ������һ���࣬���౻��Ϊ��Ԫ�࣬����������£������༰�����г�Ա������Ԫ��
���Ҫ��������Ϊһ�������Ԫ����Ҫ���ඨ���иú���ԭ��ǰʹ�ùؼ��� friend */

#include <iostream>
using namespace std;

class Box
{
    double width;
public:
    friend void printWidth(Box box);//��Ԫ����
    friend class BigBox;//��Ԫ��
    void setWidth(double wid);//��Ա����
};

class BigBox
{
public :
    void Print(int width, Box box)
    {
        // BigBox��Box����Ԫ�࣬������ֱ�ӷ���Box����κγ�Ա
        box.setWidth(width);
        cout << "Width of box : " << box.width << endl;
    }
};

// ��Ա��������
void Box::setWidth(double wid)
{
    width = wid;
}

// ��ע�⣺printWidth() �����κ���ĳ�Ա����������ֱ�Ӷ����ȫ�ֺ���
void printWidth(Box box)
{
    /* ��Ϊ printWidth() �� Box ����Ԫ��������ֱ�ӷ��ʸ�����κγ�Ա */
    cout << "Width of box : " << box.width << endl;
}

// �����������
int main()
{
    Box box;
    BigBox big;

    // ʹ�ó�Ա�������ÿ��
    box.setWidth(10.0);

    // ʹ����Ԫ����������
    printWidth(box);

    // ʹ����Ԫ���еķ������ÿ��
    big.Print(20, box);

    getchar();
    return 0;
}