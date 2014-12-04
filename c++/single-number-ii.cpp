class Solution {
public:
    int singleNumber(int A[], int n) {
        /* https://oj.leetcode.com/problems/single-number-ii/
        count[0..31]: Bookkeeping the number of occurences of every bit.
        (for a int, totally 32 bits)
        If count[i] % 3 != 0, then the ith bit beblongs to the single number.
        */
        
        int count[32];
        memset(count, 0, sizeof(int)*32);
        
        for (int i = 0; i < n; i++) {
             for (int j = 0; j < 32; j++) {
                 if ((A[i] >> j) & 1) {
                     count[j]++;
                 }
             }
        }
        
        int result = 0;
        for (int i = 0; i < 32; i++) {
            if (count[i] % 3) result |= (1 << i);
        }
        
        return result;
    }
};