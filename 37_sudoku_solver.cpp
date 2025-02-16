class Solution {
public:
    bool isNumberInRow(std::vector<std::vector<char>>& board, int col, char num) {
        for (int i = 0; i < 9; ++i) {
            if (board[i][col] == num) {
                return true;
            }
        }
        return false;
    }

    bool isNumberInCol(std::vector<std::vector<char>>& board, int row, char num) {
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == num) {
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
                if (board[i][j] == num) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isValidPlacement(std::vector<std::vector<char>>& board, int row, int col, char num) {
        return (!isNumberInRow(board, col, num) && !isNumberInCol(board, row, num) && !isNumberInSqr(board, row, col, num));
    }

    bool solveBoard(std::vector<std::vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (int num_try = 1; num_try < 10; ++num_try) {
                        char cur_val = '0'+num_try;
                        if (isValidPlacement(board, i, j, cur_val)) {
                            board[i][j] = cur_val;

                            if (solveBoard(board)) {
                                return true;
                            } else {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solveBoard(board);
    }
};
