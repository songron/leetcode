//https://oj.leetcode.com/problems/gray-code/

class Solution {
public:
    vector<int> grayCode(int n) {
        // think about what happens when we move from 2-bit to 3-bit,
        // one step more, what happens when we move from n-bit to (n+1)-bit !!
        // hints: the reversion of a gray-code-sequence if also a *gray-code-sequence* !!
        
        vector<int> result;
        result.push_back(0);
        if (n == 0) {
            return result;
        }
        
        result.push_back(1);
        int high_bit = 1;
        for (int i = 1; i < n; i++) {
            high_bit <<= 1;
            for (int j = result.size() - 1; j >= 0; j--) {
                result.push_back(result[j] | high_bit);
            }
        }
        
        return result;
    }
};
