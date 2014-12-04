//https://oj.leetcode.com/problems/search-for-a-range/

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result({-1, -1});
        if (n == 0) return result;
        
        int i = 0, j = n - 1;
        while (i <= j) {
            int k = i + (j - i) / 2;
            if (A[k] < target) i = k + 1;
            else j = k - 1;
        }
        
        if (i > n - 1 || A[i] != target) return result;
        result[0] = i;
        
        j = n - 1;
        while (i <= j) {
            int k = i + (j - i) / 2;
            if (A[k] <= target) i = k + 1;
            else j = k - 1;
        }
        result[1] = j;
    
        return result;
    }
};