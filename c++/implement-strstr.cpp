class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        /* https://oj.leetcode.com/problems/implement-strstr/
        KMP algorithm
        */
        
        if (needle == NULL || *needle == '\0') return haystack;
        if (haystack == NULL || *haystack == '\0') return NULL;
        
        vector<int> M({-1});
        int i = 0, j = 1;
        
        while (needle[j] != '\0') {
            if (needle[j] == needle[i]) {
                M.push_back(i);
                i++;
                j++;
            }
            else if (i == 0) {
                M.push_back(-1);
                j++;
            }
            else {
                i = M[i-1] + 1;  //  the part before i has been matched
            }
        }
        
        const int n = j;  // n is the length of needle
        i = j = 0;
        while (haystack[j] != '\0') {
            while (haystack[j] != '\0' && needle[i] != '\0' && haystack[j] == needle[i]) {
                i++;
                j++;
            }
            if (needle[i] == '\0') {
                return haystack + j - n;
            }
            if (i == 0) {
                j++;
            }
            else {
                i = M[i-1] + 1;
            }
        }
        
        return NULL;
    }
};