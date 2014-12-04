//https://oj.leetcode.com/problems/zigzag-conversion/

class Solution {
public:
    string convert(string s, int nRows) {
        const int n = s.size();
        if (n <= nRows || nRows == 1) return s;

        string result;
        int gap = nRows + nRows - 2;

        for (int i = 0; i < nRows; i++) {
            for (int j = i; j < n; j += gap) {
                result.push_back(s[j]);
                if (i > 0 && i < nRows - 1 && gap-i+j-i < n) result.push_back(s[gap-i+j-i]);
            }
        }

        return result;
    }
};
