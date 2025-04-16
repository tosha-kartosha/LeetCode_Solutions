#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n, std::vector<int>(n));
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        graph[a][b] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            std::cout << graph[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
