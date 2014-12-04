class Solution {
public:
    vector<int> getRow(int rowIndex) {
        /* https://oj.leetcode.com/problems/pascals-triangle-ii/
        0 -> [1]
        1 -> [1, 1]
        2 -> [1, 2, 1]
        */
        
        vector<int> result(rowIndex+1, 1);
        if (rowIndex <= 1) return result;
        
        for (int i = 2; i <= rowIndex; i++) {
            for (int j = i - 1; j > 0; j--) {
                result[j] = result[j] + result[j-1];
            }
        }
        
        return result;
    }
};