class Solution {
private:
    void partitionHelper(string &s, vector<vector<bool> > &P, int start, vector<string> &answer, 
        vector<vector<string> > &result) {
        
        if (start == s.size()) {
            result.push_back(answer);
            return ;
        }
        
        for (int i = start; i < s.size(); i++) {
            if (P[start][i]) {
                answer.push_back(s.substr(start, i-start+1));
                partitionHelper(s, P, i+1, answer, result);
                answer.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        /* https://oj.leetcode.com/problems/palindrome-partitioning/
        two steps:
        1, bool P[n][n]: figure out witch substrings of s are palindrome
        2, generate palindrome partitions according to P[n][n]
        */
        
        const int n = s.size();
        vector<vector<string> > result;
        if (n == 0) {
            result.push_back(vector<string>(1, ""));
            return result;
        }
        
        // determine with substrs are palindrome
        vector<vector<bool> > P(n, vector<bool>(n)); // P[i][j] == true iff s[i..j] is palindrome
        for (int i = 0; i < n; i++) P[i][i] = true;
        for (int i = 0; i < n - 1; i++) P[i][i+1] = s[i] == s[i+1];
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                P[i][j] = P[i+1][j-1] && s[i] == s[j];
            }
        }
        
        // generate palindrome partitions
        vector<string> answer;
        partitionHelper(s, P, 0, answer, result);
        
        return result;
    }
};