class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        /* https://oj.leetcode.com/problems/triangle/
        */
        
        if (triangle.empty()) return 0;
        
        int result = 0;
        const int n = triangle.size();
        vector<int> row = triangle[n-1];
        
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                row[j] = min(row[j], row[j+1]) + triangle[i][j]; 
            }
        }
        
        return row[0];
    }
};