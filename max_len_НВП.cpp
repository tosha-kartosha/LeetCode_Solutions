// Дана последовательность, требуется найти длину её наибольшей возрастающей подпоследовательности. Подпоследовательностью последовательности называется некоторый набор её элементов, не обязательно стоящих подряд.
// Требуется вывести длину наибольшей строго возрастающей подпоследовательности.

#include <iostream>
#include <vector>

int main() {
    int n = 0, ans = 1;
    std::cin >> n;
    std::vector<int> sequence(n);
    std::vector<int> dp(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> sequence[i];
        dp[i] = 1;
        for (int j = i-1; j >= 0; --j) {
            if (sequence[j] < sequence[i]) {
                dp[i] = (dp[i] < dp[j] + 1 ? dp[j] + 1 : dp[i]);
                ans = (ans < dp[i] ? dp[i] : ans);
            }
        }
    }
    std::cout << ans;
    return 0;
}
