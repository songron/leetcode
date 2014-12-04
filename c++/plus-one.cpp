class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        /* https://oj.leetcode.com/problems/plus-one/
        [9, 9] -> [1, 0, 0]
        */
        
        vector<int> result(digits.size(), 0);
        int carry = 1;
        
        for (int i = digits.size() - 1; i >= 0; i--) {
            int x = digits[i] + carry;
            result[i] = x % 10;
            carry = x / 10;
        }
        
        if (carry > 0) {
            result.insert(result.begin(), carry);
        }
        
        return result;
    }
};