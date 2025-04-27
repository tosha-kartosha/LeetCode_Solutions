#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> pref(n+1);
    std::vector<int> dp(n+1);
    pref[1] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = pref[i-1];
        if (i-k-1 >= 0) {
            dp[i] -= pref[i-k-1];
        }
        pref[i] = pref[i-1] + dp[i];
    }
    std::cout << dp[n];
    return 0;
}
