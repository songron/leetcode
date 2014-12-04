class Solution {
public:
    bool isScramble(string s1, string s2) {
        /* https://oj.leetcode.com/problems/scramble-string/
        bool SC[len][i][j]: true iff s1[i:i+len] and s2[j:j+len] are scramble
        */
        
        const int n = s1.size();
        if (n != s2.size()) return false;
        if (n == 0) return true;
        
        bool SC[n][n][n];
        for (int i = 0; i < n; i++) {  // len is 1
            for (int j = 0; j < n; j++) {
                SC[0][i][j] = s1[i] == s2[j];
            }
        }
        
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                for (int j = 0; j + len <= n; j++) {
                    SC[len-1][i][j] = false;
                    for (int l = 1; l < len && !SC[len-1][i][j]; l++) {
                        SC[len-1][i][j] = ((SC[l-1][i][j] && SC[len-l-1][i+l][j+l]) || 
                            (SC[l-1][i][j+len-l] && SC[len-l-1][i+l][j]));
                    }
                }
            }
        }
        
        return SC[n-1][0][0];
    }
};