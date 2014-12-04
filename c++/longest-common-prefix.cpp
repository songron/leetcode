//https://oj.leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string pre;
        const int n = strs.size();
        if (n == 0) return pre;

        for (int i = 0; i < (int)strs[0].size(); i++) {
            char c = strs[0][i];
            for (int j = 1; j < n; j++) {
                if (i == (int)strs[j].size() || strs[j][i] != c)
                    return pre;
            }
            pre.append(1, c);
        }

        return pre;
    }
};
