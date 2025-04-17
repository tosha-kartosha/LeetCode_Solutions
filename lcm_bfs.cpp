// Дано число X и множество цифр D. Требуется дописать к X минимальное количество цифр из D, чтобы получившееся число делилось на k. При этом получившееся число должно быть минимально возможным.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main() {
    std::string X;
    int k, d;
    std::cin >> X >> k >> d;
    std::vector<int> numbers(d);
    for (int i = 0 ; i < d; ++i) {
        std::cin >> numbers[i];
    }
    std::sort(numbers.begin(), numbers.end());
    int r = 0;
    for (char c : X) {
        r = (r * 10 + (c - '0')) % k;
    }
    std::vector<std::vector<int>> graph(k);
    for (int i = 0; i < k; ++i) {
        for (int digit : numbers) {
            int elem = (i * 10 + digit) % k;
            graph[elem].push_back(i);
        }
    }
    const int UNDEF = -1;
    std::vector<int> dlini(k, UNDEF);
    std::queue<int> q;
    dlini[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int m : graph[curr]) {
            if (dlini[m] == UNDEF) {
                dlini[m] = dlini[curr] + 1;
                q.push(m);
            }
        }
    }
    if (dlini[r] == UNDEF) {
        std::cout << "-1";
        return 0;
    }
    std::cout << X;
    while (r != 0) {
        for (int d : numbers) {
            int r2 = (r * 10 + d) % k;
            if (dlini[r2] == dlini[r] - 1) {
                r = r2;
                std::cout << d;
                break;
            }
        }
    }
    return 0;
}
