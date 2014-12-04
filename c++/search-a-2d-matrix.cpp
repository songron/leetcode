class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        /* https://oj.leetcode.com/problems/search-a-2d-matrix/
        just simple binary search
        */
        
        if (matrix.empty() || matrix[0].empty()) return false;
        
        const int m = matrix.size(), n = matrix[0].size();
        int start = 0, end = m * n - 1;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int i = mid / n, j = mid % n;
            if (matrix[i][j] == target) return true;
            
            if (matrix[i][j] < target) start = mid + 1;
            else end = mid - 1;
        }
        
        return false;
    }
};