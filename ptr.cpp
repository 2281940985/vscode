#include <iostream>
 
using namespace std;
const int MAX = 3;
 
int main ()
{
   int  var[MAX] = {10, 100, 200};
 
   for (int i = 0; i < MAX; i++)
   {
      *var = i;    // 这是正确的语法
      //var++;       // 这是不正确的,数组名是指向数组开头的常量
    *(var+1) = 4004;
    cout << var[i] << endl;
   }
   system("pause");
   //如果说数组名 a 是 a[0] 的地址，(a+n) 是指 a[0] 的地址加上一个值， 
   //& 表示取地址， * 表示取值，那么 a[i] 等价于 *(a+i)，&a[i] 等价于 (a+i)。
}