class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int len = derived.size();
        if (len == 1) {
            return derived[0] == 0 ? true : false; // won't work without this check on leetcode, whilst work in vs code
        }
        int *original {new int[len]{0}};
        if (derived[len-1] != 0) {
            original[len-1] = 1;
        }
        for (int ind = 0; ind < len - 2; ++ ind) {
            if (derived[ind] != 0) {
                if (original[ind] == 0) {
                    original[ind + 1] = 1;
                }
            } else {
                if (original[ind] == 1) {
                    original[ind + 1] = 1;
                }
            }
        }
        if (derived[len-2] == 0) {
            if (original[len-2] == 0) {
                return original[len-1] == 0 ? true : false;
            } else {
                return original[len-1] == 1 ? true : false;
            }
        } else {
            if (original[len-2] == 0) {
                return original[len-1] == 1 ? true : false;
            } else {
                return original[len-1] == 0 ? true : false;
            }
        }
    }
};
