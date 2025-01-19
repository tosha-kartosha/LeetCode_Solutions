class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int cur_len = 1;
        std::vector<std::vector<int>> ans;
        std::vector<int> cur_level;
        while (cur_len <= numRows) {
            std::vector<int> cur_level(cur_len, 0);
            if (cur_len == 1) {
                cur_level[0] = 1;
            } else {
                cur_level[0] = 1;
                cur_level[cur_len-1] = 1;
                for (int i = 0; i < cur_len - 2; ++i) {
                    cur_level[i+1] = ans[cur_len-2][i] + ans[cur_len-2][i+1];
                }
                
            }
            ans.push_back(cur_level);
            cur_len += 1;
        }
        return ans;
    }
};
