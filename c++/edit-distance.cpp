class Solution {
public:
    int minDistance(string word1, string word2) {
        /* https://oj.leetcode.com/problems/edit-distance/
        Find the minimum number of steps to convert word1 to word2
            * insert
            * delete
            * replace
        */

        const int m = word1.size(), n = word2.size();
        if (n == 0) return m;
        if (m == 0) return n;
        
        int E[m+1][n+1];
        E[0][0] = 0;
        for (int i = 1; i <= m; i++) E[i][0] = i;
        for (int j = 1; j <= n; j++) E[0][j] = j;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) {
                    E[i][j] = E[i-1][j-1];
                }
                else {
                    E[i][j] = E[i-1][j-1] + 1;  // replace
                    if (E[i][j-1] + 1 < E[i][j]) { // insert word2[j-1] to word1
                        E[i][j] = E[i][j-1] + 1;
                    }
                    if (E[i-1][j] + 1 < E[i][j]) {  // delete word1[i-1] from word1
                        E[i][j] = E[i-1][j] + 1;
                    }
                }
            }
        }
        
        return E[m][n];
    }
};

/*
// More efficient in space (less memory cost)

class Solution {
public:
    int minDistance(string word1, string word2) {
        const int m = word1.size(), n = word2.size();
        if (n == 0) return m;
        if (m == 0) return n;
        
        vector<int> edit(n+1);
        for (int i = 0; i <= n; i++) edit[i] = i;
        
        for (int i = 1; i <= m; i++) {
            vector<int> temp(n+1);
            temp[0] = i;
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) {
                    temp[j] = edit[j-1];
                }
                else {
                    temp[j] = edit[j-1] + 1;
                    if (edit[j] + 1 < temp[j]) { // delete word1[i-1] from word1
                        temp[j] = edit[j] + 1;
                    }
                    if (temp[j-1] + 1 < temp[j]) { // insert word2[j-1] to word1
                        temp[j] = temp[j-1] + 1;
                    }
                }
            }
            edit = temp;
        }
        
        return edit[n];
    }
};
*/