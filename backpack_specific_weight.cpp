// Дано n золотых слитков массой m1, …, mn. Ими наполняют рюкзак, который выдерживает вес не более w. Можно ли набрать вес в точности w?

#include <iostream>
#include <vector>

int main() {
    int n = 0, w = 0;
    std::cin >> n >> w;
    std::vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> weights[i];
    }
    std::vector<int> dp(w+1);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        std::vector<int> dp_tmp = dp;
        for (int j = 1; j <= w; ++j) {
            if (j - weights[i] >= 0 && dp[j - weights[i]] == 1) {
                dp_tmp[j] = 1;
            }
        }
        dp = dp_tmp;
    }
    std::cout << (dp[w] == 1 ? "yes" : "no");
    return 0;
}
