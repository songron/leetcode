class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        /* https://oj.leetcode.com/problems/maximal-rectangle/
        */
        
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        const int m = matrix.size(), n = matrix[0].size();
        vector<int> leftBound(n, 0), rightBound(n, n-1), height(n, 0);
        int result = 0;
    
        for (int i = 0; i < m; i++) {
            int left = 0;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') {
                    left = j + 1;
                    height[j] = 0;
                    leftBound[j] = 0;
                    rightBound[j] = n - 1;
                }
                else {
                    height[j]++;
                    leftBound[j] = max(leftBound[j], left);
                }
            }
            
            int right = n - 1;
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == '0') {
                    right = j - 1;
                }
                else {
                    rightBound[j] = min(rightBound[j], right);
                    int area = (rightBound[j] - leftBound[j] + 1) * height[j];
                    if (area > result) result = area;
                }
            }
        }
        
        return result;
    }
};