#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char s[500];//һ���ַ�ֻռһ���ֽڣ�����һ������ռ�����ֽ�
    int n;
    cin >> n;
    getchar();//ȥ���س�
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