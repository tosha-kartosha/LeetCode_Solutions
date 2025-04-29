//Дано n предметов массой m1, …, mn и стоимостью c1, …, cn соответственно. Ими наполняют рюкзак, который выдерживает вес не более w. Определите набор предметов, который можно унести в рюкзаке, имеющий наибольшую стоимость.
// Выведите наибольшую стоимость набора предметов, который можно унести в рюкзаке.

#include <iostream>
#include <vector>

int main() {
    int n = 0, w = 0, ans = 0;
    std::cin >> n >> w;
    std::vector<int> weights(n);
    std::vector<int> prices(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> weights[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> prices[i];
    }
    std::vector<int> dp(w+1);
    for (int i = 0; i < n; ++i) {
        std::vector<int> dp_tmp = dp;
        for (int j = 1; j <= w; ++j) {
            if (j == weights[i]) {
                dp_tmp[j] = (dp[j] < prices[i] ? prices[i] : dp[j]);
            }
            if (j-weights[i] > 0 && dp[j-weights[i]] != 0) {
                dp_tmp[j] = (dp[j] < dp[j-weights[i]]+prices[i] ? dp[j-weights[i]]+prices[i] : dp[j]);
            }
            ans = (ans < dp_tmp[j] ? dp_tmp[j] : ans);
        }
        dp = dp_tmp;
    }
    std::cout << ans;
    return 0;
}
