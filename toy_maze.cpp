/* Игрушечный лабиринт представляет собой прозрачную плоскую прямоугольную коробку, внутри которой есть препятствия и перемещается шарик.
Лабиринт можно наклонять влево, вправо, к себе или от себя, после каждого наклона шарик перемещается в заданном направлении до ближайшего препятствия или до стенки лабиринта, после чего останавливается.
Целью игры является загнать шарик в одно из специальных отверстий  — выходов. Шарик проваливается в отверстие, если оно встречается на его пути (шарик не обязан останавливаться в отверстии).
Первоначально шарик находится в левом верхнем углу лабиринта. Гарантируется, что решение существует и левый верхний угол не занят препятствием или отверстием.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

const int INF = 1e9;

int bfs_maze(std::vector<std::vector<int>> &graph, int n, int m) {
    std::vector<std::vector<int>> dist(n, std::vector<int>(m, INF));
    std::queue<std::pair<int, int>> q;
    int ans = INF;
    int new_x, new_y;
    q.push(std::pair(0, 0));
    dist[0][0] = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        new_x = x;
        new_y = y;
        if (y != 0) {
            while (new_y - 1 != -1 && graph[new_x][new_y - 1] != 1 && graph[new_x][new_y - 1] != 2) {
                new_y--;
            }
            if (new_y - 1 != -1 && graph[new_x][new_y - 1] == 2) {
                new_y--;
            }
            if (dist[new_x][new_y] > dist[x][y] + 1) {
                dist[new_x][new_y] = dist[x][y] + 1;
                if (graph[new_x][new_y] == 2) {
                    ans = (ans > dist[new_x][new_y] ? dist[new_x][new_y] : ans);
                } else {
                    q.push(std::pair(new_x, new_y));
                }
            }
        }
        new_x = x;
        new_y = y;
        if (x != 0) {
            while (new_x - 1 != -1 && graph[new_x - 1][new_y] != 1 && graph[new_x - 1][new_y] != 2) {
                new_x--;
            }
            if (new_x - 1 != -1 && graph[new_x - 1][new_y] == 2) {
                new_x--;
            }
            if (dist[new_x][new_y] > dist[x][y] + 1) {
                dist[new_x][new_y] = dist[x][y] + 1;
                if (graph[new_x][new_y] == 2) {
                    ans = (ans > dist[new_x][new_y] ? dist[new_x][new_y] : ans);
                } else {
                    q.push(std::pair(new_x, new_y));
                }
            }
        }
        new_x = x;
        new_y = y;
        if (y != m-1) {
            while (new_y + 1 != m && graph[new_x][new_y + 1] != 1 && graph[new_x][new_y + 1] != 2) {
                new_y++;
            }
            if (new_y + 1 != m && graph[new_x][new_y + 1] == 2) {
                new_y++;
            }
            if (dist[new_x][new_y] > dist[x][y] + 1) {
                dist[new_x][new_y] = dist[x][y] + 1;
                if (graph[new_x][new_y] == 2) {
                    ans = (ans > dist[new_x][new_y] ? dist[new_x][new_y] : ans);
                } else {
                    q.push(std::pair(new_x, new_y));
                }
            }
        }
        new_x = x;
        new_y = y;
        if (x != n-1) {
            while (new_x + 1 != n && graph[new_x + 1][new_y] != 1 && graph[new_x + 1][new_y] != 2) {
                new_x++;
            }
            if (new_x + 1 != n && graph[new_x + 1][new_y] == 2) {
                new_x++;
            }
            if (dist[new_x][new_y] > dist[x][y] + 1) {
                dist[new_x][new_y] = dist[x][y] + 1;
                if (graph[new_x][new_y] == 2) {
                    ans = (ans > dist[new_x][new_y] ? dist[new_x][new_y] : ans);
                } else {
                    q.push(std::pair(new_x, new_y));
                }
            }
        }
    }
    return ans;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> graph[i][j];
        }
    }
    std::cout << bfs_maze(graph, n, m);
}
