class Solution {
public:
    int singleNumber(int A[], int n) {
        /* https://oj.leetcode.com/problems/single-number/
        *  Every element appears twice except for one. Find that single one.
        * a ^ a = 0;  a ^ 0 = a
        */
        
        int result = 0;
        for (int i = 0; i < n; i++) {
            result ^= A[i];
        }
        
        return result;
    }
};