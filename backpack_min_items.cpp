// Дано N предметов массой m1, …, mN. Ими наполняют рюкзак, который выдерживает вес не более M. Как набрать вес в точности M, используя как можно меньше предметов? Выведите наименьшее необходимое число предметов или 0, если набрать данный вес невозможно.

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
            if (j - weights[i] >= 0 && dp[j - weights[i]] > 0) {
                if (j == weights[i]) {
                    dp_tmp[j] = 1;
                } else {
                    if (dp_tmp[j] == 0) {
                        dp_tmp[j] = dp[j - weights[i]] + 1;
                    } else {
                        dp_tmp[j] = (dp[j - weights[i]] + 1 < dp[j] ? dp[j - weights[i]] + 1 : dp[j]);
                    }       
                }
            }
        }
        dp = dp_tmp;
    }
    std::cout << dp[w];
    return 0;
}
