//https://oj.leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pos[256];
        for (int i = 0; i < 256; i++) pos[i] = -1;
        
        int last = -1, result = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (pos[c] > last) last = pos[c];
            pos[c] = i;
            result = max(result, i - last);
        }
        
        return result;
    }
};