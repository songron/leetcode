class Solution {
public:
    int reverse(int x) {
        /* https://oj.leetcode.com/problems/reverse-integer/
        123 -> 321
        -123 -> -321
        100 -> 1
        */
      
        
        int result = 0;
        
        while (x ！＝ 0) {
           if (result != 0 && INT_MAX / result < 10
                   && INT_MAX / result > -10)
               return 0;
            
            result = result * 10 + x % 10;
            x /= 10;
        }
        
        return result;
    }
};