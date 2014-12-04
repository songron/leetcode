//https://oj.leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string table[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};  // 2 - 9 (0 - 7)
        vector<string> result;
        if (digits.empty()) {
            result.push_back("");
            return result;
        }
        
        string s;
        helper(table, digits, 0, s, result);
        return result;
    }
    
    void helper(string table[], string &digits, int start, string &s, vector<string> &result) {
        if (start == digits.size()) {
            result.push_back(s);
            return;
        }
        
        // assert(digits[start] >= '2' && digits[start] <= '9');
        int i = digits[start] -'2';
        if (i < 0 || i > 7) return ;
        
        for (int j = 0; j < table[i].size(); j++) {
            s.push_back(table[i][j]);
            helper(table, digits, start+1, s, result);
            s.pop_back();
        }
    }
};