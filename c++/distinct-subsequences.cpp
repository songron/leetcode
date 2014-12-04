class Solution {
public:
    int numDistinct(string S, string T) {
        /* https://oj.leetcode.com/problems/distinct-subsequences/
        */
        
        if (T.empty()) return 1;
        if (S.empty()) return 0;
        
        const int m = S.size(), n = T.size();
        int D[m+1][n+1];
        D[0][0] = 1;
        for (int i = 1; i <= m; i++) D[i][0] = 1;
        for (int j = 1; j <= n; j++) D[0][j] = 0;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                D[i][j] = D[i-1][j] + (S[i-1] == T[j-1] ? D[i-1][j-1] : 0);
            }
        }
        
        return D[m][n];
    }
};