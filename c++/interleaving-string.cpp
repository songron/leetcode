class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        /* https://oj.leetcode.com/problems/interleaving-string/
        I[i][j] = (s1[i-1] == s3[i+j-1] && I[i-1][j]) || (s2[j-1] == s3[i+j-1] && I[i][j-1])
        */
        
        const int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if (n1 + n2 != n3) return false;
        
        bool I[n1+1][n2+1];
        I[0][0] = true;
        for (int i = 1; i <= n1; i++) I[i][0] = s1[i-1] == s3[i-1] && I[i-1][0];
        for (int j = 1; j <= n2; j++) I[0][j] = s2[j-1] == s3[j-1] && I[0][j-1];
        
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                I[i][j] = (s1[i-1] == s3[i+j-1] && I[i-1][j]) ||
                        (s2[j-1] == s3[i+j-1] && I[i][j-1]);
            }
        }
        
        return I[n1][n2];
    }
};

/*
// Cost less memory !

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // https://oj.leetcode.com/problems/interleaving-string/
        
        const int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if (n1 + n2 != n3) return false;
        
        bool I[n2+1];
        I[0] = true;
        for (int i = 1; i <= n2; i++) I[i] = I[i-1] && s2[i-1] == s3[i-1];
        
        bool flag = true, last = true;
        for (int i = 1; i <= n1; i++) {
            flag = flag && s1[i-1] == s3[i-1];
            last = flag;
            for (int j = 1; j <= n2; j++) {
                last = I[j] = (s1[i-1] == s3[i+j-1] && I[j]) || (s2[j-1] == s3[i+j-1] && last);
            }
        }
        
        return last;
    }
};
*/