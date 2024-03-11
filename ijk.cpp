  #include <iostream>
  #include <vector>
  using namespace std;
  class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ret = 0;
        for (int i = nums.size(); i > 0; --i){
            for (int j = i-1; j > 0; --j){
                if(nums[i] - nums[j] == diff){
                    for (int k =i-2; k >= 0; --k){
                        if((nums[i] - nums[j]) == diff && (nums[j] - nums[k] == diff)) {
                        ret++;
                }
                    }
                }
            }
        }
        return ret;
    }
};
int main(){
    Solution s;
    vector<int> nums = {4,5,6,7,8,9};
    vector<int>& num = nums;
    cout << s.arithmeticTriplets(num,2) << endl;
    system("pause");
    return 0;

}


