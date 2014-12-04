class Solution {
public:
    int climbStairs(int n) {
        /* https://oj.leetcode.com/problems/climbing-stairs/
        f(1) = 1;
        f(2) = 2;
        f(n) = f(n-1) + f(n-2), n > 2;
        */
        
        if (n <= 2) return n;
        
        int c1 = 1, c2 = 2;
        for (int i = 3; i <= n; i++) {
            int t_c2 = c2;
            c2 = c1 + c2;
            c1 = t_c2;
        }
        
        return c2;
    }
};