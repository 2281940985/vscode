#include <iostream>
using namespace std;
 
int main()
{
  cout << "����ָ��--Ԫ��Ϊָ�������һά���顣" << endl;
  int* arr[3];      // ָ�����飺Ԫ��Ϊָ�������һά���顣 �ȼ��� int* (arr[3]);�洢���ǵ�ַ
  int  p[] = {1,2,3};//ͨ��*������Ԫ��
  for (int i = 0; i < 3; ++i)
  {
    arr[i] = &p[i];
  }
  cout << arr << endl << endl;  //ָ������ĵ�ַ
  for (int i = 0; i < 3; ++i)
  {
    cout << arr+i << endl;
    cout << *(arr+i) << endl;
    cout << arr[i] << endl;
    cout << *arr[i] << endl;
  }


  cout << endl << endl << "����ָ��--ָ���ά�����ַ��ָ�롣" << endl;
  int pp[2][2] = {
                  {1,2},
                  {3,4}
                  };    // p�Ǹ���ά��������������൱��һ������ָ�볣��
  int (*ptr)[2] = pp;  //  ����ָ�룺ָ���ά�����ַ��ָ��
  for (int i = 0; i < 2; ++i)
  {
    cout << ptr + i << endl;  // ptr+i ��һά����p[i]�ĵ�ַ����ptr+i==&pp[i]��
    cout << &pp[i] << endl;
    cout << **(ptr + i)<< endl; // ����ָ�� **(ptr + i) = pp[i][0];
    cout << pp[i][0]<< endl; 
  }
  
  cout << *(*(ptr+1)+1) << endl; // ����ָ�� *(*(ptr+1)+1) = pp[1][1];
  cout << pp[1][1] << endl;
  system("pause");
}