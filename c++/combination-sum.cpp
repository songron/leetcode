class Solution {
private:
    void combineHelper(vector<int> &candidates, int start, int sum, int target, vector<int> &answer, 
        vector<vector<int> > &result) {
        
        if (sum == target) {
            result.push_back(answer);
            return;
        }
        if (start == candidates.size() || candidates[start] + sum > target) {
            return;
        }
        
        answer.push_back(candidates[start]);
        combineHelper(candidates, start, sum+candidates[start], target, answer, result);
        answer.pop_back();
        
        combineHelper(candidates, start+1, sum, target, answer, result);
    }

public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        /* https://oj.leetcode.com/problems/combination-sum/
        * The same repeated number may be chosen from candidates unlimited number of times.
        * All numbers (including target) will be positive integers.
        * Elements in a combination (a1, a2, … , ak) must be in non-descending order. 
          (ie, a1 ≤ a2 ≤ … ≤ ak).
        */
        
        vector<vector<int> > result;
        vector<int> answer;
        sort(candidates.begin(), candidates.end());
        
        combineHelper(candidates, 0, 0, target, answer, result);
        
        return result;
    }
};