// В неориентированном графе требуется найти длину минимального пути между двумя вершинами.

#include <iostream>
#include <vector>
#include <queue>
const int INF = 1e9;

std::vector<int> bfs(std::vector<std::vector<int>> &graph, int start) {
    std::vector<int> dist(graph.size(), INF);
    std::queue<int> q;
    dist[start] = 0;
    q.push(start);
    while (!q.empty()){
        int elem = q.front();
        q.pop();
        for (int to : graph[elem]) {
            if (dist[to] > dist[elem] + 1) {
                dist[to] = dist[elem] + 1;
                q.push(to);
            }
        }
    }
    return dist;

}

int main() {
    int n, a, b;
    std::cin >> n;
    std::vector<std::vector<int>> graph(n);
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++j) {
            int elem;
            std::cin >> elem;
            if (elem == 1) {
                graph[i].push_back(j);
            }
        }
    }
    std::cin >> a >> b;
    a--;
    b--;
    std::vector<int> ans = bfs(graph, a);
    std::cout << (ans[b] == INF ? -1 : ans[b]) << std::endl;
}
