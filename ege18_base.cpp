// базовая задачка ege18

#include <iostream>
#include <vector>

int max(int a, int b) {
    return (a < b ? b : a);
}

int min(int a, int b) {
    return (a < b ? a : b);
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> table(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> table[i][j];
        }
    }
    for (int i = 1; i < n; ++i) {
        table[i][0] += table[i-1][0];
        for (int j = 1; j < m; ++j) {
            table[0][j] += table[0][j-1];
            table[i][j] += min(table[i-1][j], table[i][j-1]);
        }
    }
    std::cout << table[n-1][m-1];
}
