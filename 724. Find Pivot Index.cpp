class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left_ptr = 0;
        int left_sum = 0;
        int right_sum = 0;
        for (int num : nums) {
            right_sum += num;
        }
        right_sum -= nums[0];
        while (left_ptr + 1 < nums.size()) {
            if (left_sum == right_sum) {
                return left_ptr;
            }
            left_sum += nums[left_ptr];
            right_sum -= nums[left_ptr + 1];
            left_ptr += 1;
        }
        if (left_sum == right_sum) {
            return left_ptr;
        }
        return -1;
    }
};

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left_sum = 0;
        int right_sum = 0;
        for (int num : nums) {
            right_sum += num;
        }
        right_sum -= nums[0];
        for (int i = 0; i + 1 < nums.size(); ++i) {
            if (left_sum == right_sum) {
                return i;
            }
            left_sum += nums[i];
            right_sum -= nums[i + 1];
        }
        if (left_sum == right_sum) {
            return nums.size() - 1;
        }
        return -1;
    }
};
