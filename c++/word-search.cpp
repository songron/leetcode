class Solution {
private:
    bool existHelper(vector<vector<char> > &board, string &word, int i, int j, int k) {
        if (k == word.size()) return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
        if (board[i][j] != word[k]) return false;

        board[i][j] = '#';
        bool result = (existHelper(board, word, i-1, j, k+1) || existHelper(board, word, i+1, j, k+1) ||
            existHelper(board, word, i, j-1, k+1) || existHelper(board, word, i, j+1, k+1));

        board[i][j] = word[k];
        return result;
    }

public:
    bool exist(vector<vector<char> > &board, string word) {
        // https://oj.leetcode.com/problems/word-search/

        if (board.empty() || board[0].empty()) return false;
        if (word.empty()) return false;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (existHelper(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};
