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
            ret = ret + s[i];//��Ϊstring����û���ڵ����ַ�������ַ����ĺ��������Եô�ͷ��ʼ�������ҵ�
            if(s[i] == maxc)//�����������ַ�������ӡ�
            {
                ret = ret + "(max)";//ʵ���ַ���������
            }
        }
        cout << ret << endl;

    }
    
    system("pause");
    return 0;
}