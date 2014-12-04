class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        /* https://oj.leetcode.com/problems/longest-consecutive-sequence/
        */
        
        int result = 0;
        unordered_set<int> unused(num.begin(), num.end());
        for (int i = 0; i < num.size(); i++) {
            if (unused.find(num[i]) == unused.end()) continue;
            int len = 1;
            unused.erase(num[i]);
            
            int left = num[i] - 1;
            while (unused.find(left) != unused.end()) {
                len++;
                unused.erase(left--);
            }
            
            int right = num[i] + 1;
            while (unused.find(right) != unused.end()) {
                len++;
                unused.erase(right++);
            }
            
            if (len > result) result = len;
        }
        
        return result;
    }
};