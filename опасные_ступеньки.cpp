/* Вася каждый день поднимается по одной и той же лестнице. Одним шагом он может встать на следующую ступеньку или перешагнуть через одну ступеньку. Он уже знает, сколькими способами он может подняться на верхнюю ступеньку.
Но недавно он обнаружил, что некоторые ступеньки обветшали, и ступать на них небезопасно. Он составил список таких ступенек, и теперь интересуется, сколькими способами можно подняться по лестнице, не наступая на эти ступеньки. */

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n = 0, k = 0;
    std::cin >> n >> k;
    std::vector<int> dp(n+1);
    dp[0] = 1;
    std::vector<int> dangerous_steps;
    for (int i = 0; i < k; ++i) {
        int elem;
        std::cin >> elem;
        dangerous_steps.push_back(elem);
    }
    for (int i = 1; i <= n; ++i) {
        if (std::find(dangerous_steps.begin(), dangerous_steps.end(), i) == dangerous_steps.end()) {
            dp[i] = dp[i-1];
            if (i-2 >= 0) {
                dp[i] += dp[i-2];
            }
        }
    }
    std::cout << dp[n] << std::endl;
    return 0;
}
