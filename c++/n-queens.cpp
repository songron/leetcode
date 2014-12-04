class Solution {
private:
    int colFlag;  // column index
    int diagFlag1;  // 2*n-1 diagonals, index = i + j
    int diagFlag2;  // 2*n-1 diagonals, index = n + i - j - 1

    bool isValid(int rowIndex, int colIndex, int n) {
        if ((1 << colIndex) & colFlag) return false;
        if ((1 << (rowIndex + colIndex)) & diagFlag1) return false;
        if ((1 << (n + rowIndex - colIndex - 1)) & diagFlag2) return false;
        return true;
    }

    void setFlag(int rowIndex, int colIndex, int n) {
        colFlag |= (1 << colIndex);
        diagFlag1 |= (1 << (rowIndex + colIndex));
        diagFlag2 |= (1 << (n + rowIndex - colIndex - 1));
    }

    void unsetFlag(int rowIndex, int colIndex, int n) {
        colFlag &= ~(1 << colIndex);
        diagFlag1 &= ~(1 << (rowIndex + colIndex));
        diagFlag2 &= ~(1 << (n + rowIndex - colIndex - 1));
    }

    void queenHelper(int n, vector<string> &answer, vector<vector<string> > &result) {
        int rowIndex = answer.size();

        if (rowIndex == n) {
            result.push_back(answer);
            return;
        }

        answer.push_back(string(n, '.'));
        for (int i = 0; i < n; i++) {
            if (isValid(rowIndex, i, n)) {
                setFlag(rowIndex, i, n);
                answer.back()[i] = 'Q';
                queenHelper(n, answer, result);
                answer.back()[i] = '.';
                unsetFlag(rowIndex, i, n);
            }
        }
        answer.pop_back();
    }

public:
    vector<vector<string> > solveNQueens(int n) {
        // https://oj.leetcode.com/problems/n-queens/

        colFlag = diagFlag1 = diagFlag2 = 0;
        vector<vector<string> > result;
        vector<string> answer;

        queenHelper(n, answer, result);
        return result;
    }
};
