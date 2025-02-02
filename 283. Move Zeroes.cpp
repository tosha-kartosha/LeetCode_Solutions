// the idea is to remember the very left index of 0 and swap with it
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ind_z = -1;
        for (int i = 0;  i < nums.size(); ++i) {
            if(nums[i] == 0 && ind_z == -1) {
                ind_z = i;
            } else if (nums[i] != 0 && ind_z != -1) {
                int tmp = ind_z;
                nums[ind_z] = nums[i];
                nums[i] = 0;
                ind_z = tmp + 1;
            }
        }
    }
};
