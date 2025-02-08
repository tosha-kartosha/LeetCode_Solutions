class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> arr(n + 1, 0);
        int step = 0;
        for (int i = 1; i < n+1; ++i) {
            if ((i & (i - 1)) == 0) {
                step = i;
            }
            arr[i] = arr[i-step] + 1;
        }
        return arr;
    }
};
