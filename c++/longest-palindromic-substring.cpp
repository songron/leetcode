class Solution {
public:
    string longestPalindrome(string s) {
        /* https://oj.leetcode.com/problems/longest-palindromic-substring/
        */

        if (s.empty()) return "";

        const int n = s.size();
        int start = 0, maxLen = 1;

        for (int i = 1; i < s.size(); i++) {
            int len = 1;
            // s[i] as the center
            for (int j = i-1, k = i+1; j >= 0 && k < s.size() && s[j] == s[k]; j--, k++) {
                len += 2;
            }
            if (len > maxLen) {
                maxLen = len;
                start = i - (len-1)/2;
            }

            if (s[i] != s[i-1]) continue;
            // s[i-1..i] as the center
            len = 2;
            for (int j = i-2, k = i+1; j >= 0 && k < s.size() && s[j] == s[k]; j--, k++) {
                len += 2;
            }
            if (len > maxLen) {
                maxLen = len;
                start = i - 1 - (len-2)/2;
            }
        }

        return s.substr(start, maxLen);
    }
};


// a better solution in O(n) time
/*
class Solution {
public:
    string longestPalindrome(string s) {
        // https://oj.leetcode.com/problems/longest-palindromic-substring/
        // Manacher algorithm: solve longest palindromic substring in O(n) time.

        const int n = s.size();
        if (n <= 1) return s;

        string s_sharp("#");
        for (int i = 0; i < n; i++) {
            s_sharp.push_back(s[i]);
            s_sharp.push_back('#');
        }
        int m = n * 2 + 1;

        int P[m];
        P[0] = 0;
        int ext = 0, k = 0;
        int center = 0;

        for (int i = 1; i < m; i++) {
            if (i >= ext) {
                int j = 1;
                for (; i + j < m && i - j >= 0 && s_sharp[i+j] == s_sharp[i-j]; j++) ;
                P[i] = j - 1;
            }
            else {
                int j = k * 2 - i;
                if (j - P[j] > k - P[k]) {
                    P[i] = P[j];
                }
                else {
                    int l = j - (k - P[k]);
                    for ( ; i + l < m && i - l >= 0 && s_sharp[i+l] == s_sharp[i-l]; l++) ;
                    P[i] = l - 1;
                }
            }

            if (i + P[i] > ext) {
                ext = i + P[i];
                k = i;
            }
            if (P[i] > P[center]) {
                center = i;
            }
        }

        string result;
        for (int i = center - P[center]; i <= center + P[center]; i++) {
            if (s_sharp[i] != '#') result.push_back(s_sharp[i]);
        }

        return result;
    }
};
*/
