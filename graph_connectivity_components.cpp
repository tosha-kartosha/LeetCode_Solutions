#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<int>> &graph, int v, std::vector<int> &visited) {
    visited[v] = 1;
    for (int elem : graph[v]) {
        if (!visited[elem]) {
            dfs(graph, elem, visited);
        }
    }
}

int main() {
    int countVert, countEdges;
    std::cin >> countVert >> countEdges;
    std::vector<std::vector<int>> graph(countVert);
    std::vector<int> visited(countVert);
    int count = 0; // for number of connectivity components
    for (int i = 0; i < countEdges; ++i) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 0; i < countVert; ++i) {
        if (!visited[i]) {
            count += 1;
            dfs(graph, i, visited);
        }
    }
    std::cout << count << std::endl;
}
