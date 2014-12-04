class Solution {
public:
    int atoi(const char *str) {
        /* https://oj.leetcode.com/problems/string-to-integer-atoi/
        * May contain leading whitespaces;
        * May contain additional characters after the digits in the tail;
        * If the first non-whitespace-sequence is not a valid integer, return 0;
        * If the value is out of range, INT_MAX or INT_MIN is returned.
        */
        
        if (str == NULL) return 0;
        
        int result = 0;
        while (*str == ' ') str++;
        
        int sign = 1;
        if (*str == '+') {
            str++;
        }
        else if (*str == '-') {
            sign = -1;
            str++;
        }
        
        while (*str >= '0' && *str <= '9') {
            if (result > INT_MAX / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            if (result == INT_MAX / 10) {
                if (sign == 1) {
                    return *str >= '7' ? INT_MAX : result * 10 + (*str - '0'); 
                }
                else {
                    return *str >= '8' ? INT_MIN : -result * 10 - (*str - '0');
                }
            }
            
            result = result * 10 + (*str - '0');
            str++;
        }
        
        return sign * result;
    }
};