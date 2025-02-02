class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int el_parity = nums[0] % 2;
        for(int i = 1; i < nums.size(); ++i) {
            int cur_el_parity = nums[i] % 2;
            if (el_parity == cur_el_parity) {
                return false;
            }
            el_parity = cur_el_parity;
        }
        return true;
    }
};
