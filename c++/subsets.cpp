class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        /* https://oj.leetcode.com/problems/subsets/
        no duplicates in S
        */
        
        vector<vector<int> > result;
        result.push_back(vector<int>());
        sort(S.begin(), S.end());
        
        for (int i = 0; i < S.size(); i++) {
            int count = result.size();
            for (int j = 0; j < count; j++) {
                result.push_back(result[j]);
                result[count+j].push_back(S[i]);
            }
        }
        
        return result;
    }
};