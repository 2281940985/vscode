#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        queue<int> q1, q2;
        for(int i = 1; i <= n; ++i)
        {
            q1.push(i);
        }
        while (q1.size() > 3)
        {
            int cnt = 0;
            while (q1.size())
            {
                int v = q1.front();
                ++cnt;
                q1.pop();
                if(cnt % 2 == 1)
                {
                    q2.push(v);
                }
            }
            if (q2.size() <= 3)
            {
                while (q2.size())
                {
                    q1.push(q2.front());
                    q2.pop();
                }
                break; 
            }
            cnt = 0;
            while (q2.size())
            {
                int v = q2.front();
                ++cnt;
                q2.pop();
                if(cnt % 3 == 1 || cnt % 3 ==2)
                {
                    q1.push(v);
                }
            }
            
        }
        while (q1.size())
        {
            cout << q1.front() << " ";
            q1.pop();
        }
            
    }
  system("pause");
  return 0;  
    
}
