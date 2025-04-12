// Дан неориентированный невзвешенный граф. Для него вам необходимо найти количество вершин, лежащих в одной компоненте связности с данной вершиной (считая эту вершину).

#include <iostream>
#include <vector>

void count_vert(std::vector<std::vector<int>> &graph, int v, std::vector<int> &visited, int &count) {
    visited[v] = 1;
    for (int elem : graph[v]) {
        if (!visited[elem]) {
            count += 1;
            count_vert(graph, elem, visited, count);
        }
    }
}

int main() {
    int countVert, s, n;
    std::cin >> countVert >> s;
    s--;
    std::vector<std::vector<int>> graph(countVert);
    int count = 1;
    std::vector<int> visited(countVert);
    for (int i = 0; i < countVert; ++i) {
        for (int j = 0; j < countVert; ++j) {
            std::cin >> n;
            if (n == 1) {
                graph[i].push_back(j);
            }
        }
    }
    count_vert(graph, s, visited, count);
    std::cout << count << std::endl;
    return 0;
}
