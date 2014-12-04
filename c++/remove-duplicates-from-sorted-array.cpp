class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/
        if (n < 2) return n;
        
        int len = 0;
        for (int i = 1; i < n; i++) {
            if (A[i] != A[len]) {
                A[++len] = A[i];
            }
        }
        
        return len+1;
    }
};