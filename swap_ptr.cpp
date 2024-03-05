#include <iostream>
//using namespace std;
//构造函数swap实现两个数的交换，要求函数传入的参数是指针
void swap (double* ptr_x ,double* ptr_y );
int main()
{
    double x , y;
    std :: cin >> x >> y;
    std :: cout << "x = "<< x << "y = " << y <<std :: endl;
    swap ( &x , &y );
    std :: cout << "交换后的x = "<< x << "交换后的y = " << y << std :: endl;
    system("pause");
    return 0;
}
void swap (double* ptr_x ,double* ptr_y )
{
    double temp = 0;
    temp = *ptr_x;
    *ptr_x = *ptr_y;
    *ptr_y = temp;
    
}