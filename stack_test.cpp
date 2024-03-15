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
        return stk.empty();//若为return true，则若输入只有一个左括号，则压入栈后，直接跳出for循环输出true了，
    }//而实际栈中还有个元素未比较，也很明显这不符合要求，应输出false；
};//所以return stk.empty()，可以保证左括号能全部匹配完，输出true，否则左括号还剩下没被匹配，则会返回false
int main()
{
    Solution s;
    cout << s.isValid("()") << endl;
    system("pause");
    return 0;
}