class Solution {
public:
    int maxProduct(int A[], int n) {
        /* https://oj.leetcode.com/problems/maximum-product-subarray/
        Different from "Maximum sum subarray".
        
        Bookkeeping the maximum abs(value) of positive/negative values endswith the current element.
        */
        
        if (n == 1) return A[0];
        // otherwise, the result must be larger or equal to zero;
        // no need to compare with the negative values. 
        
        int result = INT_MIN, pos = 0, neg = 0;

        for (int i = 0; i < n; i++) {
            if (A[i] == 0) {
                pos = neg = 0;
                if (result < 0) result = 0;
            }
            else if (A[i] > 0) {
                pos = pos > 0 ? pos * A[i] : A[i];
                neg = neg < 0 ? neg * A[i] : 0;
                if (pos > result) result = pos;
            }
            else {
                int t_neg = neg;
                neg = pos > 0 ? pos * A[i] : A[i];
                pos = t_neg < 0 ? t_neg * A[i] : 0;
                if (pos > 0 && pos > result) result = pos;
            }
        }
        
        return result;
        
    }
};