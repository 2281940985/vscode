#include<iostream>
#include<cstring>
#include<string>
#include<queue>
using namespace std;

int team[1000000];
int main()
{
    int t;
    int cases = 0;
    while (cin >> t && t) 
    {
        ++cases;
        memset(team, 0, sizeof(team));
        for(int i = 1; i <= t; ++i)
        {
            int n;
            cin >> n;
            while (n--)
            {
                int x;
                cin >> x;
                team[x] = i;
            }
            
        }
        queue<int> q[1001];
        int s = 0, e = 0;
        string str;
        cout << "Scenario # " << cases << endl;
        while (cin >> str)
        {
            if (str == "STOP") break;
            if (str == "ENQUEUE")
            {
                int x , i;
                cin >> x; 
                for ( i = s; i < e; ++i)
                {
                    if (team[q[i].front()] == team[x])
                    {
                        break;
                    }
                    
                }
                q[i].push(x);
                if (i == e)
                {
                    ++e;
                }
                      
            }
            else
            {
                int val = q[s].front();
                q[s].pop();
                if (q[s].size() == 0)
                {
                    ++s;
                }
                cout << val << endl;
            }
            

            
        }
        cout << endl;
        
    }
    system("pause");
    


    return 0;
}