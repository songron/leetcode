class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        /* https://oj.leetcode.com/problems/word-break/
        */
        
        if (s.empty()) return true;
        
        vector<bool> B(s.size()+1, false);
        B[0] = true;
        
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j >= 0; j--) {
                if (dict.find(s.substr(j, i-j+1)) != dict.end() && B[j]) {
                    B[i+1] = true;
                    break;
                }
            }
        }
        
        return B[s.size()];
    }
};