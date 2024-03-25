#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
    string s;
    while (cin >> s)
    {
        string ret = "";
        char maxc = 'a';
        for(int i = 0; i < s.size(); ++i)
        {
            if( s[i] > maxc)
            {
                maxc = s[i];
            }
        }
        for(int i = 0; i < s.size(); ++i)
        {
            ret = ret + s[i];//因为string类中没有在单个字符后添加字符串的函数，所以得从头开始遍历，找到
            if(s[i] == maxc)//符合条件的字符，在添加。
            {
                ret = ret + "(max)";//实现字符串的连接
            }
        }
        cout << ret << endl;

    }
    
    system("pause");
    return 0;
}