class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // https://oj.leetcode.com/problems/unique-paths-ii/
        
        const int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
        
        int P[m][n];
        P[0][0] = 1;
        for (int i = 1; i < m; i++) {
            P[i][0] = obstacleGrid[i][0] == 0 ? P[i-1][0] : 0;
        }
        for (int j = 1; j < n; j++) {
            P[0][j] = obstacleGrid[0][j] == 0 ? P[0][j-1] : 0;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                P[i][j] = obstacleGrid[i][j] == 0 ? P[i-1][j] + P[i][j-1] : 0;
            }
        }
        
        return P[m-1][n-1];
    }
};

/*
// Saved more space !

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // https://oj.leetcode.com/problems/unique-paths-ii/
        
        const int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
        
        int row[n];
        row[0] = 1;
        for (int i = 1; i < n; i++) {
            row[i] = obstacleGrid[0][i] == 0 ? row[i-1] : 0;
        }
        
        int first = 1;
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 1) {
                first = 0;
            }
            int last = first;
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    last = row[j] = 0;
                }
                else {
                    last = row[j] = last + row[j];  // last if from left, row[j] is from up
                }
            }
        }
        
        return row[n-1];
    }
};
*/
