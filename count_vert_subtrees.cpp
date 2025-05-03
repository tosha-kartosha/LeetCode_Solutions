// Подсчитать кол-во вершин в каждом поддереве

#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<int>> &graph, int v, std::vector<int> &visited, std::vector<int> &size) {
    visited[v] = 1;
    for (int to : graph[v]) {
        if (!visited[to]) {
            dfs(graph, to, visited, size);
            size[v] += size[to];
        }
    }
}

int main() {
    int vertCount, edgeCount;
    int count = 0;
    std::cin >> vertCount >> edgeCount;
    std::vector<int> visited(vertCount);
    std::vector<int> size(vertCount, 1);
    std::vector<std::vector<int>> graph(vertCount);
    for (int i = 0; i < edgeCount; ++i) {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
    }
    for (int i = 0; i < vertCount; ++i) {
        dfs(graph, i, visited, size);
    }
    for (int i = 0; i < vertCount; ++i) {
        std::cout << size[i] << " ";
    }
    return 0;
}
