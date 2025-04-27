/*На шахматной доске (8x8) стоит одна белая шашка. Сколькими способами она может пройти в дамки?*/

#include <iostream>
#include <vector>

int main() {
    int column = 0, row = 0;
    std::cin >> column >> row;
    std::vector<std::vector<int>> field(9, std::vector<int> (9));
    field[row][column] = 1;
    int sum = 0;
    if (row == 8) {
        std::cout << 1;
        return 0;
    }
    for (int i = row+1; i < 9; ++i) {
        for (int j = 1; j < 9; ++j) {
            if (j == 8) {
                field[i][j] = field[i-1][j-1];
            } else {
                field[i][j] = field[i-1][j+1] + field[i-1][j-1];
            }
            if (i == 8) {
                sum += field[i][j];
            }
        }
    }
    std::cout << sum;
    return 0;
}
