// На шахматной доске N × N в клетке (x1,y1) стоит голодный шахматный конь. Он хочет попасть в клетку (x2,y2), где растет вкусная шахматная трава. Какое наименьшее количество ходов он должен для этого сделать?

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

const int INF = 1e9;

int bfs(int n, int start_x, int start_y, int dest_x, int dest_y) {
    static std::vector<int> shift_x = {-2, -2, -1, 1, 2, 2, 1, -1};
    static std::vector<int> shift_y = {-1, 1, 2, 2, 1, -1, -2, -2};
    std::vector<std::vector<int>> graph(n, std::vector<int>(n)); // visited
    std::vector<std::vector<int>> dist(n, std::vector<int>(n, INF));
    dist[start_x][start_y] = 0;
    std::queue<std::pair<int, int>> q;
    q.push(std::make_pair(start_x, start_y));
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; ++i) {
            int sh_x = x+shift_x[i];
            int sh_y = y+shift_y[i];
            if (0 <= sh_x && sh_x < n && 0 <= sh_y && sh_y < n) {
                if (dist[sh_x][sh_y] > dist[x][y] + 1) {
                    dist[sh_x][sh_y] = dist[x][y] + 1;
                    q.push(std::make_pair(sh_x, sh_y));
                }
            }
        }
    }
    return dist[dest_x][dest_y];
}

int main() {
    int n, x1, y1, x2, y2;
    std::cin >> n >> x1 >> y1 >> x2 >> y2;
    x1--;
    y1--;
    x2--;
    y2--;
    std::cout << bfs(n, x1, y1, x2, y2);
}
