class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        /* https://oj.leetcode.com/problems/minimum-path-sum/
        * Move either down or right.
        T = O(row_length * col_length)
        Space = O(row_length);
        */
        
        if (grid.empty() || grid[0].empty()) return 0;
        
        const int m = grid.size(), n = grid[0].size();
        
        int row[n];
        row[0] = grid[0][0];
        for (int i = 1; i < n; i++) row[i] = row[i-1] + grid[0][i];
        
        int first = grid[0][0];
        
        for (int i = 1; i < m; i++) {
            first += grid[i][0];
            int last = first;
            for (int j = 1; j < n; j++) {
                last = min(row[j], last) + grid[i][j];
                row[j] = last;
            }
        }
        
        return row[n-1];
    }
};