/*Дано прямоугольное поле и вертикальные или горизонтальные полос (улицы). Вдоль улиц расположены дома, а в клетках, не соприкасающихся с улицами - парк. Требуется подсчитать количество клеток, в которых расположены улицы, парки и дома.
 Правительство страны Ректилании решило построить новый город. По плану правительства, город должен быть построен на сетке M на N прямоугольных участков, размером 100 на 100 метров.
 Все улицы должны иметь ширину 100 метров и занимать соответственно одну горизонталь или вертикаль сетки. Вертикальные улицы должны пролегать по вертикалям с номерами X1...XV, горизонтальные – по горизонталям с номерами Y1...YH.
 При этом улицы не соприкасаются, то есть не бывает Xi = Xi-1 + 1 и соответственно Yj = Yj-1 + 1 .
 Все дома в новом городе должны занимать одну клетку сетки. Причем все дома должны находиться рядом с улицами, а в клетках, не имеющих общих сторон с улицами, будет разбит парк. Кроме того, дома не должны находиться на наружной стороне крайних улиц.
 Теперь правительство Ректилании хочет знать, сколько домов будет построено в новом городе и сколько в нем будет клеток парка. Ваша задача состоит в том, чтобы написать программу, которая рассчитает эти величины.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

void dfs(std::vector<std::vector<int>> &visit, int x, int y,  std::unordered_map<int, std::vector<int>> &map, int count, int N, int M) {
    visit[x][y] = count;
    map[count][0] = std::min(map[count][0], x); // min_x
    map[count][1] = std::max(map[count][1], x); // max_x
    map[count][2] = std::min(map[count][2], y); // min_y
    map[count][3] = std::max(map[count][3], y); // max_y

    static std::vector<int> dx = {-1, 0, 0, 1};
    static std::vector<int> dy = {0, -1, 1, 0};
    for (int i = 0; i < 4; ++i) {
        int elem_x = dx[i]+x;
        int elem_y = dy[i]+y;
        if (0 <= elem_x && elem_x < M && 0 <= elem_y && elem_y < N) {
            if (visit[elem_x][elem_y] == 0) {
                dfs(visit, elem_x, elem_y, map, count, N, M);
            }
        }
    }
}


int main() {
    int M=0, N=0, V=0, H=0, count = 0;
    std::cin >> M >> N >> V >> H;
    std::vector<std::vector<int>> visit(M, std::vector<int>(N, 0));
    std::vector<int> X(V);
    for (int i = 0; i < V; ++i) {
        std::cin >> X[i];
    }

    std::vector<int> Y(H);
    for (int i = 0; i < H; ++i) {
        std::cin >> Y[i];
    }

    std::unordered_set<int> vertical_streets(X.begin(), X.end());
    std::unordered_set<int> horizontal_streets(Y.begin(), Y.end());
    for (int elem : vertical_streets) {
        for (int i = 0; i < M; ++i) {
            visit[i][elem-1] = -1;
        }
    }
    for (int elem : horizontal_streets) {
        for (int i = 0; i < N; ++i) {
            visit[elem-1][i] = -1;
        }
    }
    std::unordered_map<int, std::vector<int>> map;
    int A = 0;
    int B = 0;
    int C = V * N + H * M - V * H;
    for(int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (visit[i][j] == 0) {
                count++;
                map[count].push_back(i);
                map[count].push_back(i);
                map[count].push_back(j);
                map[count].push_back(j);

                dfs(visit, i, j, map, count, N, M);
            }
        }
    }

    for (int i = 1; i <= map.size(); ++i) {
        if ((map[i][1] - map[i][0] + 1) <= 2 && (map[i][3] - map[i][2] + 1) <= 2) {
            A += (map[i][1] - map[i][0] + 1)*(map[i][3] - map[i][2] + 1);
        } else {
            int square = (map[i][1] - map[i][0] + 1 - 2)*(map[i][3] - map[i][2] + 1 - 2);
            B += square;
            A += ((map[i][1] - map[i][0] + 1)*(map[i][3] - map[i][2] + 1)- square);
        }
    }
    std::cout << A << " " << B << " " << C << std::endl;
    return 0;
}
