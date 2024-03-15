#include <iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
    bool isLeft(char c)
        {
           return c == '(' || '[' || '{';
        }
    bool ismatch(char l, char c)
        {
            return l == '(' && c ==')' ||
            l == '[' && c == ']' ||
            l == '{' && c == '}';
        }
public:
    bool isValid(string s){
        stack<char> stk;
         for (int i = 0; i < s.size(); ++i)
        {
            if (isLeft(s[i]))
            {
                stk.push(s[i]);
            }
            else
            {
                if(stk.empty())
                {
                    return false;
                }
                else
                {
                    if(ismatch(stk.top(),s[i]))
                    {
                        stk.pop();
                        continue;
                    }
                    return false;
                    
                }
                
            }
        }
        return stk.empty();//��Ϊreturn true����������ֻ��һ�������ţ���ѹ��ջ��ֱ������forѭ�����true�ˣ�
    }//��ʵ��ջ�л��и�Ԫ��δ�Ƚϣ�Ҳ�������ⲻ����Ҫ��Ӧ���false��
};//����return stk.empty()�����Ա�֤��������ȫ��ƥ���꣬���true�����������Ż�ʣ��û��ƥ�䣬��᷵��false
int main()
{
    Solution s;
    cout << s.isValid("()") << endl;
    system("pause");
    return 0;
}