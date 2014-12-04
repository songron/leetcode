class Solution {
public:
    int numTrees(int n) {
        /* https://oj.leetcode.com/problems/unique-binary-search-trees/
        f(n) = f(0)*f(n-1) + f(1)*f(n-2) + ... + f(n-1)*f(0)
        
        Think more: Catalan Number.
        f(n) = C(2n, n) / (n + 1) = (2n)!/(n!*(n+1)!)
        */
        
        vector<int> U(n+1, 1);
        for (int i = 2; i <= n; i++) {
            U[i] = 0;
            for (int j = 0; j < i; j++) {
                U[i] += U[j] * U[i-j-1];
            }
        }
        return U[n];
    }
};