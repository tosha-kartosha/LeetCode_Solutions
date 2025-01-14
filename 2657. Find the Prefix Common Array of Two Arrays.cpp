class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int len = A.size();
        std::vector<int> pre_res(len, 0);
        std::vector<int> res(len, 0);
        int count = 0;

        for (int i = 0; i < len; ++i) {
            pre_res[A[i] - 1] += 1;
            if (pre_res[A[i] - 1] == 2) {
                count += 1;
            }
            pre_res[B[i] - 1] += 1;
            if (pre_res[B[i] - 1] == 2) {
                count += 1;
            }
            res[i] += count;
        }
        return res;
    }
};
