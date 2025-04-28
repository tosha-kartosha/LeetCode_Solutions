#include <iostream>
#include <vector>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i-1]+nums[i]) {
                nums[i] += nums[i-1];
            }
            ans = (ans < nums[i] ? nums[i] : ans);
        }
        return ans;
    }
};
