//https://oj.leetcode.com/problems/surrounded-regions/

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.empty() || board[0].empty()) return ;
        
        const int m = board.size(), n = board[0].size();
        if (m < 3 || n < 3) return ;
        
        int i = 0, j = 0;
        for ( ; j < n - 1; j++) {
            walk(board, i, j);
        }
        for ( ; i < m - 1; i++) {
            walk(board, i, j);
        }
        for ( ; j > 0; j--) {
            walk(board, i, j);
        }
        for ( ; i > 0; i--) {
            walk(board, i, j);
        }
        
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (board[i][j] == '#') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
    
    void walk(vector<vector<char> > &board, int x, int y) {
        if (x < 0 || x >= board.size() || y < 0 || y > board[0].size()) return ;
        
        if (board[x][y] == 'O') {
            board[x][y] = '#';
            walk(board, x-1, y);
            walk(board, x+1, y);
            walk(board, x, y-1);
            walk(board, x, y+1);
        }
    }
};