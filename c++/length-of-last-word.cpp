//https://oj.leetcode.com/problems/length-of-last-word/

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if (s == NULL || *s == '\0') return 0;
        
        const char *start = NULL, *end = NULL;
        
        while (*s != '\0') {
            while (*s == ' ') ++s;
            if (*s == '\0') break;
            
            start = s;
            while (*s != ' ' && *s != '\0') ++s;
            end = s;
        }
        
        return end == NULL ? 0 : end - start;
    }
};