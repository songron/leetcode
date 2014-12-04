class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // https://oj.leetcode.com/problems/spiral-matrix/
        
        vector<int> result;
        if (matrix.empty() || matrix[0].empty()) return result;
        
        const int m = matrix.size(), n = matrix[0].size();
        int k = 0, i = 0, j = 0;
        
        while (k < n / 2 && k < m / 2) {  // make sure at least one "frame" remained (not a single line)
            i = j = k;
            for ( ; j < n - k - 1; j++) result.push_back(matrix[i][j]);
            for ( ; i < m - k - 1; i++) result.push_back(matrix[i][j]);
            for ( ; j > k; j--) result.push_back(matrix[i][j]);
            for ( ; i > k; i--) result.push_back(matrix[i][j]);
            k++;
        }
        
        if (k * 2 < n && k * 2 < m) {  // some elements remained
            i = j = k;
            if (k < n / 2) {  // a horizontal line remained
                for ( ; j < n - k; j++) result.push_back(matrix[i][j]);
            }
            else {
                for ( ; i < m - k; i++) result.push_back(matrix[i][j]);
            }
        }
        
        return result;
    }
};