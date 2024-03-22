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
    Vector b1= a1;//将a复制给了b，但是a与b是两个独立的变量，存储在相互独立的区域。改变b的值不影响a

    Vector* a2 = new Vector();
    Vector* b2 = a2;//将a2这个指针存储的的地址复制给b2，修改b2的值不影响a2，但a2与b2都指向同一块内存区域
    b2 ->x = 3;//此时a2 ->x也被修改为3；

}