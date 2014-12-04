class Solution {
private:
    void helper(int left, int right, string &s, vector<string> &result) {
        if (left == 0 && right == 0) {
            result.push_back(s);
            return;
        }
        if (left > 0) {
            s.push_back('(');
            helper(left-1, right, s, result);
            s.pop_back();
        }
        if (right > left) {
            s.push_back(')');
            helper(left, right-1, s, result);
            s.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        // https://oj.leetcode.com/problems/generate-parentheses/
        vector<string> result;
        string s;
        helper(n, n, s, result);
        return result;
    }
};