class Solution {
public:
    bool isPalindrome(int x) {
        /* https://oj.leetcode.com/problems/palindrome-number/
        * Negative number is not palindrome.
        * Reversing a number may cause overflow.
        */
        
        if (x < 0) return false;
        if (x < 10) return true;
        
        int fac = 1;
        while (x / 10 >= fac) {
            fac *= 10;
        }
        
        int high = 0, low = 0;
        while (fac >= 10) {  // cannot use "while(x)" here, e.g., x = 1000021
            high = x / fac;
            low = x % 10;
            if (high != low) return false;
            x = (x % fac) / 10;
            fac /= 100;
        }
        
        return true;
    }
};