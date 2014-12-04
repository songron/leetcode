class Solution {
private:
    int combinatorial(int n, int k) {
        if (k > n - k) return combinatorial(n, n-k);
        
        long long result = 1;
        for (int i = 1; i <= k; i++) {
            result *= n - i + 1;
            result /= i;
        }
        
        return (int)result;
    }

public:
    int uniquePaths(int m, int n) {
        // https://oj.leetcode.com/problems/unique-paths/
        /*
        f(m, n) = C(m+n-2, m-1) = (m+n-2)! / ((m-1)! * (n-1)!)
        */
        if (m == 0 || n == 0) return 0;
        
        return combinatorial(m+n-2, n-1);
    }
};