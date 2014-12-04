class Solution {
private:
    int minCutHelper() {
        
    }
    
    

public:
    int minCut(string s) {
        /* https://oj.leetcode.com/problems/palindrome-partitioning-ii/
        two steps:
        1, figure out witch substrs are palindrome
        2, find the min cut
        */
        
        const int n = s.size();
        if (n <= 1) return 0;
        
        // determine witch substrs are palindrome
        vector<vector<bool> > P(n, vector<bool>(n));
        for (int i = 0; i < n; i++) P[i][i] = true;
        for (int i = 0; i < n - 1; i++) P[i][i+1] = s[i] == s[i+1];
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                P[i][j] = P[i+1][j-1] && s[i] == s[j];
            }
        }
        
        // find out the min cut
        vector<int> cut(n, 0);
        for (int i = 1; i < n; i++) {
            if (P[0][i]) {
                cut[i] = 0;
            }
            else {
                cut[i] = n;
                for (int j = i; j > 0; j--) {
                    if (P[j][i] && cut[j-1] + 1 < cut[i]) {
                        cut[i] = cut[j-1] + 1;
                    }
                }
            }
        }
        
        return cut[n-1];
    }
};