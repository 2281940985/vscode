#include<iostream>
#include<string>

using namespace std;

struct Vector
{
    float x, y;
};
int main()
{
    Vector a1 = {2, 3};
    Vector b1= a1;//��a���Ƹ���b������a��b�����������ı������洢���໥���������򡣸ı�b��ֵ��Ӱ��a

    Vector* a2 = new Vector();
    Vector* b2 = a2;//��a2���ָ��洢�ĵĵ�ַ���Ƹ�b2���޸�b2��ֵ��Ӱ��a2����a2��b2��ָ��ͬһ���ڴ�����
    b2 ->x = 3;//��ʱa2 ->xҲ���޸�Ϊ3��

}