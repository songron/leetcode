class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        /* https://oj.leetcode.com/problems/pascals-triangle/
        */
        
        vector<vector<int> > result;

        for (int i = 1; i <= numRows; i++) {
            result.push_back(vector<int>(i, 1));
            for (int j = 1; j < i - 1; j++) {
                result[i-1][j] = result[i-2][j-1] + result[i-2][j];
            }
        }
        
        return result;
    }
};