class Solution {
public:
    int reverse(int x) {
        /* https://oj.leetcode.com/problems/reverse-integer/
        123 -> 321
        -123 -> -321
        100 -> 1
        */
        
        if (x < 0) {
            return x == INT_MIN ? 0 : -reverse(-x);
        }
        
        int result = 0;
        
        while (x > 0) {
            if (result > INT_MAX / 10) {  // will overflow
                return 0;
            }
            if (result == INT_MAX / 10 && (x % 10) > 7) {  // will overflow
                return 0;
            }
            
            result = result * 10 + x % 10;
            x /= 10;
        }
        
        return result;
    }
};