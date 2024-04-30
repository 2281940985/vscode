#include<iostream>
#include<vector>
#include<string>

using namespace std;


    void removeSpaces(string &s)
    {
        string res;
        int slow = 0;
        int fast = 1;
        while(slow <= s.size()-1)
        {
            if(s[slow] != ' ')
            {
                if(s[fast] != ' ')
                {
                    res.push_back(s[slow]);
                }
                else
                {
                    res.push_back(s[slow]);
                    res.push_back(' ');
                }

                fast++;
                slow++;
                
            }
            else
            {
                fast++;
                slow++;
            }
        }
        if(res[res.size()-1] == ' ')
        {
            res.erase(res.end()-1);
        }
        s = res;
        
    }
    void Reverse(string &s, int i, int j)
    {
        int left = i;
        int right = j;
        while(right > left)
        {
            swap(s[left], s[right]);
            right--;
            left++;
        }
    }
    string reverseWords(string &s) {
        removeSpaces(s);
        Reverse(s, 0, s.size()-1);
        int k = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i+1] == ' '|| i == s.size()-1)
            {
                Reverse(s, k, i);
                k = i+2;
            }

        }
        return s;


    }

    int main()
    {
        string s = "the sky is blue";
        //removeSpaces(s);
        //Reverse(s,0,s.size()-1);
        cout << reverseWords(s) << endl;
        system("pause");
        return 0;
    }