// Дан набор гирек массой m1, …, mn. Можно ли их разложить на две чаши весов, чтобы они оказались в равновесии?

#include <iostream>
#include <vector>

int main() {
    int n = 0, sum = 0;
    std::cin >> n;
    std::vector<int> elems(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> elems[i];
        sum += elems[i];
    }
    if (sum % 2 != 0) {
        std::cout << "NO";
        return 0;
    }
    std::vector<int> dp(sum/2 + 1);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        std::vector<int> dp_tmp = dp;
        for (int j = 1; j <= sum/2; ++j) {
            if (j - elems[i] >= 0 && dp[j - elems[i]] == 1) {
                dp_tmp[j] = 1;
            }
        }
        dp = dp_tmp;
    }
    std::cout << (dp[sum/2] == 1 ? "YES" : "NO");
}
