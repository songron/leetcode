//https://oj.leetcode.com/problems/divide-two-integers/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor < 0) {
            if (divisor == INT_MIN) {
                return dividend == INT_MIN ? 1 : 0;
            }
            return -divide(dividend, -divisor);
        }
        
        if (dividend < 0) {
            if (dividend == INT_MIN) {
                dividend += divisor;
                return -1 - divide(-dividend, divisor);
            }
            return -divide(-dividend, divisor);
        }
        
        int result = 0;
        while (dividend >= divisor) {
            int shift = 1;
            while (dividend >> shift >= divisor) {
                shift++;
            } 
            result += 1 << (shift - 1);
            dividend -= divisor << (shift - 1);
        }
        
        return result;
    }
};