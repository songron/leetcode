class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // https://oj.leetcode.com/problems/spiral-matrix-ii/
        
        vector<vector<int> > result(n, vector<int>(n));
        if (n == 0) return result;
        
        int k = 0, value = 1;
        while (k < n / 2) {
            int i = k, j = k;
            for ( ; j < n - k - 1; j++) result[i][j] = value++;
            for ( ; i < n - k - 1; i++) result[i][j] = value++;
            for ( ; j > k; j--) result[i][j] = value++;
            for ( ; i > k; i--) result[i][j] = value++;
            k++;
        }
        
        if (n % 2 != 0) result[n/2][n/2] = value;
        
        return result;
    }
};