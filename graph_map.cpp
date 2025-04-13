//Из прямоугольного листа клетчатой бумаги (m строк, m столбцов) удалили некоторые клетки. На сколько кусков распадётся оставшаяся часть листа? Две клетки не распадаются, если они имеют общую сторону.
#include <iostream>
#include <vector>

void dfs_map(std::vector<std::string> &map, int x, int y, std::vector<std::vector<int>> &visitik, int n, int m) {
    visitik[x][y] = 1;
    static std::vector<int> dx = {-1, 0, 0, 1};
    static std::vector<int> dy = {0, -1, 1, 0};
    for (int i = 0; i < 4; ++ i) {
        int elem_x = x+dx[i];
        int elem_y = y+dy[i];
        if (0 <= elem_x && elem_x < n && 0 <= elem_y && elem_y < m) {
            if (map[elem_x][elem_y] == '#' && !visitik[elem_x][elem_y]) {
                dfs_map(map, elem_x, elem_y, visitik, n, m);
            }
        }
    }
}


int main() {
    int n, m;
    int count = 0;
    std::cin >> n >> m;
    std::vector<std::string> map(n);
    std::vector<std::vector<int>> visitik(n, std::vector<int>(m));
    for (std::string &row : map) {
        std::cin >> row;
    }
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            if (map[x][y] == '#' && !visitik[x][y]) {
                count++;
                dfs_map(map, x, y, visitik, n, m);
            }
        }
    }
    std::cout << count << std::endl;
}
