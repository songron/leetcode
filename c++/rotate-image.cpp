class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        /* https://oj.leetcode.com/problems/rotate-image/
        outside-to-inside, level by level, four by four
        */
        
        const int n = matrix.size();
        
        for (int k = 0; k < n / 2; k++) {
            for (int i = k; i < n - k - 1; i++) {
                int tmp = matrix[k][i];
                matrix[k][i] = matrix[n-1-i][k];
                matrix[n-1-i][k] = matrix[n-1-k][n-1-i];
                matrix[n-1-k][n-1-i] = matrix[i][n-1-k];
                matrix[i][n-1-k] = tmp;
            }
        }
    }
};