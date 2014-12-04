//https://oj.leetcode.com/problems/powx-n/

class Solution {
public:
    double pow(double x, int n) {
        assert(x != 0 || n >= 0);
        
        if (n == 0) return 1;
        if (n == 1) return x;
        if (x == 0 || x == 1) return x;
        if (n < 0) {
            if (n == INT_MIN) {
                assert(x == -1);
                return 1;
            }
            return 1.0 / pow(x, -n);
        }
        
        double half = pow(x, n/2);
        if (n % 2 == 0) {
            return half * half;
        }
        return half * half * x;
    }
};