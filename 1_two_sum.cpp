// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// revise hashmap
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> sums;
        std::vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            int key = target - nums[i];
            auto it = sums.find(key);
            if (it != sums.end()) {
                ans = {sums[key], i};
                break;
            } else {
                sums[nums[i]] = i;
            }
        }
        return ans;
    }
};
