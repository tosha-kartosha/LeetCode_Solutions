#include <iostream>
#include <vector>
void dfs_cycles(std::vector<std::vector<int>> &graph, int v, std::vector<int> &visited, bool &IsCyclic) {
    visited[v] = 1;
    for (int to: graph[v]) {
        // не посещена
        if (visited[to] == 0) {
            dfs_cycles(graph, to, visited, IsCyclic);
        } else if (visited[to] == 1) {
            IsCyclic = true;
        }
    }
    visited[v] = 2;
}

int main () {
    int vertCount = 0;
    std::cin >> vertCount;
    int ans = 0;
    std::vector<int> visited(vertCount, 0);
    std::vector<std::vector<int>> graph(vertCount); // список смежности
    for (int i = 0; i < vertCount; ++i) {
        int a;
        std::cin >> a;
        a --;
        graph[a].push_back(i);
    }

    for (int i = 0; i < vertCount; ++i) {
        if(visited[i] == 0) {
            bool IsCyclic = false;
            dfs_cycles(graph, i, visited, IsCyclic);
            if (IsCyclic) {
                ans ++;
            }
        }
    }
    std::cout << ans << std::endl;
}
