#include <iostream>
//using namespace std;
//���캯��swapʵ���������Ľ�����Ҫ��������Ĳ�����ָ��
void swap (double* ptr_x ,double* ptr_y );
int main()
{
    double x , y;
    std :: cin >> x >> y;
    std :: cout << "x = "<< x << "y = " << y <<std :: endl;
    swap ( &x , &y );
    std :: cout << "�������x = "<< x << "�������y = " << y << std :: endl;
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