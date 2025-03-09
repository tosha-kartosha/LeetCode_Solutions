// Solution for B. PitCraft
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int l = 0;
        int r =  height.size() - 1;
        int max_l = height[l];
        int max_r = height[r];
        while (l < r) {
            if (max_l <= max_r) {
                l += 1;
                max_l = max_l > height[l] ? max_l : height[l];
                ans += max_l - height[l];
            } else {
                r -= 1;
                max_r = max_r > height[r] ? max_r : height[r];
                ans += max_r - height[r];
            }
        }
        return ans;
    }
};
