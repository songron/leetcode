class Solution {
private:
    vector<int> row, col, box;
    
    bool isValid(int num, int i, int j) {
        return !(row[i] & (1 << num) || col[j] & (1 << num) || box[i/3*3+j/3] & (1 << num));
    }
    
    void setFlags(int num, int i, int j) {
        row[i] |= 1 << num;
        col[j] |= 1 << num;
        box[i/3*3+j/3] |= 1 << num;
    }
    
    void unsetFlags(int num, int i, int j) {
        row[i] &= ~(1 << num);
        col[j] &= ~(1 << num);
        box[i/3*3+j/3] &= ~(1 << num);
    }
    
    bool solveHelper(vector<vector<char> > &board, int i, int j) {
        if (i == 9) return true;
        if (j == 9) return solveHelper(board, i+1, 0);
        if (board[i][j] != '.')  return solveHelper(board, i, j+1);
        
        for (int num = 0; num < 9; num++) {
            if (isValid(num, i, j)) {
                board[i][j] = num + '1';
                setFlags(num, i, j);
                if (solveHelper(board, i, j+1)) {
                    return true;
                }
                unsetFlags(num, i, j);
                board[i][j] = '.';
            }
        }
        
        return false;
    }

public:
    void solveSudoku(vector<vector<char> > &board) {
        /* https://oj.leetcode.com/problems/sudoku-solver/
        Assume there is must be an unique solution.
        */
        
        row = vector<int>(9, 0);
        col = vector<int>(9, 0);
        box = vector<int>(9, 0);
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    setFlags(board[i][j]-'1', i, j);
                }
            }
        }
        
        solveHelper(board, 0, 0);
    }
};