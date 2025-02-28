class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> pref(n, 1);
        std::vector<int> suf(n, 1);
        std::vector<int> ans(n, 1);
        for (int i = 0; i < n - 1; ++i) {
            pref[i+1] = pref[i]*nums[i];
            suf[n-i-2] = suf[n-i-1]*nums[n-i-1];
            ans[i+1] *= pref[i+1];
            ans[n-i-2] *= suf[n-i-2];
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans(n, 1);
        for (int i = 0; i < n - 1; ++i) {
            ans[i+1] *= ans[i]*nums[i];
        }
        int pref = 1;
        for (int i = n - 2; i >= 0; --i) {
            pref *= nums[i+1];
            ans[i] *= pref;
        }
        return ans;
    }
};
