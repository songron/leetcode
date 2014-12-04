class Solution {
private:
    void combineHelper(int n, int k, int start, vector<int> &answer, vector<vector<int> > &result) {
        if (answer.size() == k) {
            result.push_back(answer);
            return;
        }
        if (start > n) return;
        
        answer.push_back(start);
        combineHelper(n, k, start+1, answer, result);
        answer.pop_back();
        combineHelper(n, k, start+1, answer, result);
    }

public:
    vector<vector<int> > combine(int n, int k) {
        /* https://oj.leetcode.com/problems/combinations/
        */
        
        vector<vector<int> > result;
        vector<int> answer;
        combineHelper(n, k, 1, answer, result);
        return result;
    }
};