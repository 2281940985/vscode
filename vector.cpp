#include <iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> arr{1,2,3,4,5,6};
    
    for(int i = 0; i < 6; ++i)
    {

        cout << arr[i] << " ";
    }
    cout << endl;
    arr.erase(arr.begin() + 2);
    arr.insert(arr.end(),200183);
    for (int i = 0; i < 6; ++i)
    {
        cout << arr[i] << " ";
        
    }
    cout << endl;
    cout << arr.size() << " ";
    
    
    
    system("pause");
}

