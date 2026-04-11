// I - with HashMap -> O(n) search + O(n) space
class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::unordered_map<int, int> major_elems;
        int major_threshold = (nums.size() / 2) + 1;
        int ans = -1;
        for (int elem : nums) {
            major_elems[elem] ++;
            if (major_elems[elem] >= major_threshold) {
                ans = elem;
                break;
            }
        }
        return ans;
    }
};

// II - no HashMap -> Sort & O(1) space
class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return nums[(int)nums.size()/2];
    }
};
