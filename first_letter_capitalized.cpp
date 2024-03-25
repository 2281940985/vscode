#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main()
{
    char s[120];
    while(gets(s))
    {
        int len = strlen(s);
        for (int i = 0; i < len; ++i)
        {
            if(i == 0 || s[i - 1] == ' ')
            {
                if(s[i] != ' ')
                {
                    if( s[i] >= 'a' && s[i] <= 'z')
                    {
                        s[i] -= 'a';
                        s[i] += 'A';
                    }
                }
            }
        }
        cout << s;
    }

}