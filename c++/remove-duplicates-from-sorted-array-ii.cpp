class Solution {
public:
    int removeDuplicates(int A[], int n) {
        /* https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
        Duplicates are allowed at most twice
        */
        
        if (n <= 2) return n;
        
        int k = 1;
        for (int i = 2; i < n; i++) {
            if (A[i] == A[k] && A[i] == A[k-1]) continue;
            A[++k] = A[i];
        }
        
        return k + 1;
    }
};