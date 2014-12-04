//https://oj.leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        const int n = s.size();
        if (n <= 1) return true;
        
        int i = 0, j = n - 1;
        while (i < j) {
            while (i < j && !isAlphaNum(s[i])) i++;
            while (i < j && !isAlphaNum(s[j])) j--;
            if (toLower(s[i]) != toLower(s[j])) return false;
            i++;
            j--;
        }
        
        return true;
    }
    
    bool isAlphaNum(char c) {
        return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
    
    char toLower(char c) {
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';
        }
        return c;
    }
};