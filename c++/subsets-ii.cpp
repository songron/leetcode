class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        /* https://oj.leetcode.com/problems/subsets-ii/
        There are duplicates in S.
        */
        
        vector<vector<int> > result;
        result.push_back(vector<int>());
        if (S.empty()) return result;
        
        sort(S.begin(), S.end());
        result.push_back(vector<int>({S[0]}));
        int lastStart = 1;
        
        for (int i = 1; i < S.size(); i++) {
            int count = result.size();
            int j = S[i] == S[i-1] ? lastStart : 0;
            for ( ; j < count; j++) {
                result.push_back(result[j]);
                result.back().push_back(S[i]);
            }
            lastStart = count;
        }
        
        return result;
    }
};