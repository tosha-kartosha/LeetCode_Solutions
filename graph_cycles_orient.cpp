// Дан ориентированный граф. Требуется определить, есть ли в нем цикл.

#include <iostream>
#include <vector>

void orient_cycle(std::vector<std::vector<int>> &graph, int v, std::vector<int> &visited, bool &isCyclic) {
    visited[v] = 1;
    for (int elem : graph[v]) {
        if(visited[elem] == 0) {
            orient_cycle(graph, elem, visited, isCyclic);
        } else if (visited[elem] == 1) {
            isCyclic = true;
        } 
    }
    visited[v] = 2;
}

int main() {
    int countVert, countEdges;
    std::cin >> countVert >> countEdges;
    std::vector<std::vector<int>> graph(countVert);
    std::vector<int> visited(countVert);
    bool isCyclic = false;
    for (int i = 0; i < countEdges; ++i) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
    }
    for (int i = 0; i < countVert; ++i) {
        if(visited[i] == 0) {
            orient_cycle(graph, i, visited, isCyclic);
        }
    }
    std::cout << isCyclic << std::endl;
    return 0;
}
