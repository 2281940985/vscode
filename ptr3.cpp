#include <iostream>
using namespace std;
 
// ��������
int ** swap(int *x, int *y);//ָ����������һ������ָ�룬��ָ������
//ָ������������Ŷ��ָ�룬����ַ���ɽ���ַ����һ�������ֵ��
//ָ�����������������ָ��������׵�ַ���൱��ָ���ָ�롣
int main ()
{
   // �ֲ���������
   int a = 100;
   int b = 200;
   int **c;
   cout << "����ǰ,a ��ֵ��" << a << endl;
   cout << "����ǰ,b ��ֵ��" << b << endl;
 
   /* ���ú���������ֵ */
   c=swap(&a, &b);
 
   cout << "������,a ��ֵ��" << **c << endl;
   cout << "������,b ��ֵ��" << **(c+1) << endl;
 
   return 0;
}
 
// ��������
int ** swap(int *x, int *y)
{
   int *temp;
    temp=NULL;
    static int *r[2];//�ں�����ָ�� ָ������Ϊ��̬����������ִ����ɺ󣬲���������ñ���
   cout << "���õĺ����еĽ���:"<<endl;
   cout  << *x <<endl;
   cout << *y <<endl;
   temp = x; /* �����ַ x ��ֵ */
   x = y;    /* �� y ��ֵ�� x */
   y = temp; /* �� x ��ֵ�� y  */
   cout  << *x <<endl;
   cout << *y <<endl;
    //cout << x <<endl;
    //cout << y <<endl;
    r[0]=x;
    r[1]=y;
   return r;
}