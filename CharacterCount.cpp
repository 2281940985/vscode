#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char s[500];//一个字符只占一个字节，但是一个汉字占两个字节
    int n;
    cin >> n;
    getchar();//去掉回车
    while (n--)
    {
        gets(s);
        int cnt = 0;
        int len = strlen(s);
        for(int i = 0; i < len; ++i)
        {
            if (s[i] < 0)
            {
                ++cnt;
            }
        }
        cout << cnt/2 <<endl;
    }
    

    system("pause");
    return 0; 
}