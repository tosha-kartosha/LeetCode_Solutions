class Solution {
public:

    int mintwo(int a, int b) {
        return a < b ? a : b;
    }

    int maxArea(vector<int>& height) {
        int ans = 0;
        int tek_sum = 0;
        int l_ptr = 0;
        int r_ptr = height.size() - 1;
        while (l_ptr < r_ptr) {
            tek_sum = mintwo(height[l_ptr], height[r_ptr]) * (r_ptr - l_ptr);
            ans = ans < tek_sum ? tek_sum : ans;
            if (height[l_ptr] < height[r_ptr]) {
                l_ptr += 1;
            } else {
                r_ptr -= 1;
            }
        }
        return ans;
    }
};
