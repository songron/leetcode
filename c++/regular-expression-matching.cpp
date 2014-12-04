class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        /* https://oj.leetcode.com/problems/regular-expression-matching/
        Regular Expression:
          '.' matches any single char
          '*' matches zero or more of the preceding char (different from the meaning in wildcard match)
        */
        
        if (s == NULL) return p == NULL;
        if (p == NULL) return false;
        if (*p == '\0') return *s == '\0';
        
        if (*(p+1) == '*') {
            if (isMatch(s, p+2)) return true;
            while (*s == *p || (*p == '.' && *s != '\0')) {
                if (isMatch(s+1, p+2)) return true;
                ++s;
            }
            return false;
        }
        
        if (*s == *p || (*p == '.' && *s != '\0')) {
            return isMatch(s+1, p+1);
        }
        
        return false;
    }
};