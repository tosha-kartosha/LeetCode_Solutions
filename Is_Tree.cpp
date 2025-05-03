//Дан неориентированный граф. Требуется определить, является ли он деревом.

#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<int>> &graph, int v, std::vector<int> &visited, bool &isCyclic, int from) {
    visited[v] = 1;
    for (int elem : graph[v]) {
        if (elem == from) {
            continue;
        } else if (visited[elem] == 0) {
            dfs(graph, elem, visited, isCyclic, v);
        } else if (visited[elem] == 1) {
            isCyclic = true;
        }
    }
    visited[v] = 2;
}

int main() {
    int n = 0, m = 0;
    bool isCyclic = false;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n);
    std::vector<int> visited(n);
    for (int i = 0; i < m; ++i) {
        int a = 0, b = 0;
        std::cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    if (n != m+1) {
        std::cout << "NO" << std::endl;
        return 0;
    }
    dfs(graph, 0, visited, isCyclic, -1);
    if (isCyclic) {
        std::cout << "NO" << std::endl;
        return 0;
    }
    for (int elem : visited) {
        if (elem != 2) {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }
    std::cout << "YES" << std::endl;
    return 0;
}

// для обработки матрицы смежности с acmp
/*int main() {
    int n = 0, m = 0;
    bool isCyclic = false;
    std::cin >> n;

    std::vector<std::vector<int>> graph(n);
    std::vector<int> visited(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int a = 0;
            std::cin >> a;
            if (a == 1) {
                m += 1;
                graph[i].push_back(j);
            }
        }
    }
    m /= 2;
    if (n != m+1) {
        std::cout << "NO" << std::endl;
        return 0;
    }
    dfs(graph, 0, visited, isCyclic, -1);
    if (isCyclic) {
        
        std::cout << "NO" << std::endl;
        return 0;
    }
    for (int elem : visited) {
        if (elem != 2) {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }
    std::cout << "YES" << std::endl;
    return 0;
}*/
