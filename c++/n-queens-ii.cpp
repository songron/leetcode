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
    
    int queenHelper(int rowIndex, int n) {
        if (rowIndex == n) return 1;
        
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (isValid(rowIndex, i, n)) {
                setFlag(rowIndex, i, n);
                result += queenHelper(rowIndex+1, n);
                unsetFlag(rowIndex, i, n);
            }
        }
        
        return result;
    }

public:
    int totalNQueens(int n) {
        /* https://oj.leetcode.com/problems/n-queens-ii/
        */
        
        colFlag = diagFlag1 = diagFlag2 = 0;
        return queenHelper(0, n);
    }
};