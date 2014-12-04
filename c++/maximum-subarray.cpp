class Solution {
public:
    int maxSubArray(int A[], int n) {
        /* https://oj.leetcode.com/problems/maximum-subarray/
        subarray containing at least one number
        */
        
        int result = INT_MIN;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum = sum > 0 ? sum + A[i] : A[i];
            if (sum > result) result = sum;
        }
        
        return result;
    }
};