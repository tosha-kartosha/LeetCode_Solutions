class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_map<int, std::vector<char>> rows;
        std::unordered_map<int, std::vector<char>> cols;
        // pair не имеет встроенной функции хэширования
        std::unordered_map<int, std::vector<char>> squares;

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] != '.') {
                    if (std::find(rows[r].begin(), rows[r].end(), board[r][c]) != rows[r].end() ||
                        std::find(cols[c].begin(), cols[c].end(), board[r][c]) != cols[c].end() ||
                        std::find(squares[(r/3)*3+c/3].begin(), squares[(r/3)*3+c/3].end(), board[r][c]) != squares[(r/3)*3+c/3].end()) {
                            return false;
                        } else {
                            rows[r].push_back(board[r][c]);
                            cols[c].push_back(board[r][c]);
                            squares[(r/3)*3+c/3].push_back(board[r][c]);
                    }
                }
            }
        }
        return true;
    }
};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_map<int, std::unordered_set<char>> rows;
        std::unordered_map<int, std::unordered_set<char>> cols;
        // pair не имеет встроенной функции хэширования
        std::unordered_map<int, std::unordered_set<char>> squares;

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] != '.') {
                    if (rows[r].count(board[r][c]) > 0 ||
                        cols[c].count(board[r][c]) > 0 ||
                        squares[(r/3)*3+c/3].count(board[r][c]) > 0) {
                            return false;
                        } else {
                            rows[r].insert(board[r][c]);
                            cols[c].insert(board[r][c]);
                            squares[(r/3)*3+c/3].insert(board[r][c]);
                    }
                }
            }
        }
        return true;
    }
};
