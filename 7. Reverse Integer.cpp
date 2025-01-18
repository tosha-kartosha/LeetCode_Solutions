#include <limits>

class Solution {
public:
    int reverse(int x) {
        if (x % 10 != 0 && x <= std::numeric_limits<int>::min()) {
            return 0;
        }
        int new_elem = 0;
        bool sign = x < 0;
        x = abs(x);
        
        std::string x_str = std::to_string(x);
        for (int ind = 0; ind < x_str.length(); ++ ind) {
            std::string cur_num(1, x_str[x_str.length() - 1 - ind]); 
            int digit = std::stoi(cur_num);
            if (new_elem > (std::numeric_limits<int>::max() - digit) / 10) {
                return 0;
            }
            new_elem = new_elem * 10 + digit;
        }
        return sign ? -new_elem : new_elem;
    }
};
