#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int startIndex = 0;
        int ret = INT32_MAX;
        int sum = 0;
        int subLength = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            while(sum >= target)
            {
                subLength = i - startIndex + 1;
                ret = subLength < ret ? subLength : ret;
                sum -= nums[startIndex];
                startIndex++;
            }
        }
        return ret == INT32_MAX ? 0 : ret;
    }
};

int main()
{
    vector<int>nums = {5,1,3,5,10,7,4,9,2,8};
    Solution s;
    cout << s.minSubArrayLen(15, nums) << endl;
    system("pause");
    return 0;


}

