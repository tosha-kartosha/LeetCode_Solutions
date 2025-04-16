// Напомним, что вершина ориентированного графа называется истоком, если в нее не входит ни одно ребро, и стоком, если из нее не выходит ни одного ребра. 
// Ориентированный граф задан матрицей смежности. Найдите все вершины графа, которые являются истоками, и все его вершины, которые являются стоками.

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> graph(n, std::vector<int>(n));
    std::vector<int> ist;
    std::vector<int> stok;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int a;
            std::cin >> a;
            graph[i][j] = a;
        }
        ist.push_back(i+1);
    }
    for (int i = 0; i < n; ++i) {
        bool check_stol = true;
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] == 1) {
                check_stol = false;
                auto elem = std::find(ist.begin(), ist.end(), j+1);
                if (elem != ist.end())
                    ist.erase(elem);
            }
        }
        if (check_stol) {
            stok.push_back(i+1);
        }
    }
    std::cout << ist.size() << std::endl;
    for (int elem : ist) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    std::cout << stok.size() << std::endl;
    for (int elem : stok) {
        std::cout << elem << " ";
    }
}
