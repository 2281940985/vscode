#include <iostream>
#include<stdio.h>
#include<time.h>
#define random(x) (rand()%x)//%-取余数
using namespace std;

int main()
{
    srand((int)time(0));//部署随机种子
    for (int i = 0; i < 10; i++){
        cout << random(100) << endl;
        //输出0-100的随机数
    };
    system("pause");
    return 0;
}
