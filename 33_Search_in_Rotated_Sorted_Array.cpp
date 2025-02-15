class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ind_max = 0;
        int max_elem = nums[0];
        int l = 0;
        int r = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > max_elem) {
                max_elem = nums[i];
                ind_max = i;
            } else {
                break;
            }
        }
        if (target > nums[nums.size()-1] || ind_max == nums.size()-1) {
            l = 0;
            r = ind_max;
        } else {
            l = ind_max + 1;
            r = nums.size()-1;
        }
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                return mid;
            } else {
                if (nums[mid] > target) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        if (l == r) {
            if (nums[l] == target) {
                return l;
            } 
        }
        return -1;
    }
};
