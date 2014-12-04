class Solution {
private:
    vector<int> row, col, box;

    bool isValid(int num, int i, int j) {
        return  !((row[i] & (1 << num) || col[j] & (1 << num) || box[i/3*3+j/3] & (1 << num)));
    }
    
    void setFlags(int num, int i, int j) {
        row[i] |= 1 << num;
        col[j] |= 1 << num;
        box[i/3*3+j/3] |= 1 << num;
    }

public:
    bool isValidSudoku(vector<vector<char> > &board) {
        /* https://oj.leetcode.com/problems/valid-sudoku/
        */
        
        if (board.size() != 9 || board[0].size() != 9) return false;
        
        row = vector<int>(9, 0);
        col = vector<int>(9, 0);
        box = vector<int>(9, 0);
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                if (board[i][j] < '1' || board[i][j] > '9') return false;
                if (!isValid(board[i][j]-'1', i, j)) return false;
                setFlags(board[i][j]-'1', i, j);
            }
        }
        
        return true;
    }
};