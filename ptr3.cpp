#include <iostream>
using namespace std;
 
// 函数声明
int ** swap(int *x, int *y);//指明函数返回一个二级指针，即指针数组
//指针数组用来存放多个指针，即地址，可将地址看作一种特殊的值。
//指针数组的数组名（即指针数组的首地址）相当于指针的指针。
int main ()
{
   // 局部变量声明
   int a = 100;
   int b = 200;
   int **c;
   cout << "交换前,a 的值：" << a << endl;
   cout << "交换前,b 的值：" << b << endl;
 
   /* 调用函数来交换值 */
   c=swap(&a, &b);
 
   cout << "交换后,a 的值：" << **c << endl;
   cout << "交换后,b 的值：" << **(c+1) << endl;
 
   return 0;
}
 
// 函数定义
int ** swap(int *x, int *y)
{
   int *temp;
    temp=NULL;
    static int *r[2];//在函数内指定 指针数组为静态变量，函数执行完成后，不会清理掉该变量
   cout << "调用的函数中的交换:"<<endl;
   cout  << *x <<endl;
   cout << *y <<endl;
   temp = x; /* 保存地址 x 的值 */
   x = y;    /* 把 y 赋值给 x */
   y = temp; /* 把 x 赋值给 y  */
   cout  << *x <<endl;
   cout << *y <<endl;
    //cout << x <<endl;
    //cout << y <<endl;
    r[0]=x;
    r[1]=y;
   return r;
}