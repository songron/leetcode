class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // https://oj.leetcode.com/problems/first-missing-positive/
        
        for (int i = 0; i < n; i++) {
            while (A[i] != i + 1 && A[i] > 0 && A[i] <= n) {
                int t = A[i];
                if (A[t-1] == t) break;
                A[i] = A[t-1];
                A[t-1] = t;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (A[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};