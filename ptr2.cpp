#include <iostream>
using namespace std;
 
int main()
{
  cout << "数组指针--元素为指针变量的一维数组。" << endl;
  int* arr[3];      // 指针数组：元素为指针变量的一维数组。 等价于 int* (arr[3]);存储的是地址
  int  p[] = {1,2,3};//通过*来访问元素
  for (int i = 0; i < 3; ++i)
  {
    arr[i] = &p[i];
  }
  cout << arr << endl << endl;  //指针数组的地址
  for (int i = 0; i < 3; ++i)
  {
    cout << arr+i << endl;
    cout << *(arr+i) << endl;
    cout << arr[i] << endl;
    cout << *arr[i] << endl;
  }


  cout << endl << endl << "数组指针--指向多维数组地址的指针。" << endl;
  int pp[2][2] = {
                  {1,2},
                  {3,4}
                  };    // p是个二维数组的数组名，相当于一个二级指针常量
  int (*ptr)[2] = pp;  //  数组指针：指向多维数组地址的指针
  for (int i = 0; i < 2; ++i)
  {
    cout << ptr + i << endl;  // ptr+i 是一维数组p[i]的地址，即ptr+i==&pp[i]；
    cout << &pp[i] << endl;
    cout << **(ptr + i)<< endl; // 二级指针 **(ptr + i) = pp[i][0];
    cout << pp[i][0]<< endl; 
  }
  
  cout << *(*(ptr+1)+1) << endl; // 二级指针 *(*(ptr+1)+1) = pp[1][1];
  cout << pp[1][1] << endl;
  system("pause");
}