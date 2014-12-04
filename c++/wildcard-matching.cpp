class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        /* Wildcard: different from regular expression
        https://oj.leetcode.com/problems/wildcard-matching/
        '?' match any single char; '*' match any sequence.
        Be careful with '*'.
        */
        
        assert(s != NULL && p != NULL);
        
        // "p_star" record the last pointer witch points to a '*';
        // "s_match" record the position where the '*' match to in the last try.
        // if failed somewhere, we'll try to match one more char by the last '*'
        const char *p_star = NULL, *s_match = NULL;
        
        while (*s != '\0') {
            if (*s == *p || *p == '?') {
                ++s;
                ++p;
            }
            else if (*p == '*') {
                while (*p == '*') p++;
                if (*p == '\0') return true;
                p_star = p - 1;
                s_match = s;
            }
            else {
                if (p_star == NULL) return false;
                p = p_star + 1;
                s = ++s_match;
            }
        }
        
        while (*p == '*') ++p;
        return *p == '\0';
    }
};