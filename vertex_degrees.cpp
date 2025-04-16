// Неориентированный простой граф задан списком ребер. Найдите степени всех вершин графа.

#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 0; i < n; ++i) {
        std::cout << graph[i].size() << std::endl;
    }
}
