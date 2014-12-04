//https://oj.leetcode.com/problems/valid-number/

class Solution {
public:
    bool isNumber(const char *s) {
        /*
            special characters:  '.', 'e', '-', '+'
            e : only once
            -/+ : -1.4, -234e-10
            . : only once, .123, 1.123, +.12, 12.e
        */
        
        bool hasDigit = false, hasE = false, hasDot = false;
        int i = 0;
        while (s[i] == ' ') i++;
        
        for ( ; s[i] != '\0'; i++) {
            if (s[i] == '-' || s[i] == '+') {
                if ((hasDigit || hasDot) && s[i-1] != 'e') return false;
            }
            else if (s[i] == '.') {
                if (hasDot || hasE) return false;
                hasDot = true;
            }
            else if (s[i] == 'e') {
                if (!hasE && i > 0 && s[i-1] != '-' && s[i-1] != '+' && hasDigit) {
                    hasE = true;
                    hasDigit = false;
                }
                else {
                    return false;
                }
            }
            else if (s[i] >= '0' && s[i] <= '9') {
                hasDigit = true;
            }
            else break;
        }
        
        while (s[i] == ' ') i++;
        
        return hasDigit && s[i] == '\0';
    }
};