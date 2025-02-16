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

//with unordered_set
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

// best time and memory
class Solution {
public:
    bool isNumberInRow(std::vector<std::vector<char>>& board, int row, int col, char num) {
        for (int i = 0; i < 9; ++i) {
            if (i != row && board[i][col] == num) {
                return true;
            }
        }
        return false;
    }

    bool isNumberInCol(std::vector<std::vector<char>>& board, int row, int col, char num) {
        for (int i = 0; i < 9; ++i) {
            if (i != col && board[row][i] == num) {
                return true;
            }
        }
        return false;
    }

    bool isNumberInSqr(std::vector<std::vector<char>>& board, int row, int col, char num) {
        int block_row = row - row % 3;
        int block_col = col - col % 3;
        for (int i = block_row; i < block_row + 3; ++i) {
            for (int j = block_col; j < block_col + 3; ++j) {
                if (i != row && j != col && board[i][j] == num) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isInvalid(std::vector<std::vector<char>>& board, int row, int col, char num) {
        return (isNumberInRow(board, row, col, num) || isNumberInCol(board, row, col, num) || isNumberInSqr(board, row, col, num));
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] != '.') {
                    if (isInvalid(board, r, c, board[r][c])) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
