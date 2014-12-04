class Solution {
private:
    void combineHelper2(vector<int> &num, int start, int sum, int target, vector<int> &answer, 
        vector<vector<int> > &result) {
        
        if (sum == target) {
            result.push_back(answer);
            return;
        }
        if (start == num.size() || num[start] + sum > target) {
            return;
        }
        
        answer.push_back(num[start]);
        combineHelper2(num, start+1, sum+num[start], target, answer, result);
        answer.pop_back();
        
        while (start + 1 < num.size() && num[start+1] == num[start]) {
            start++;
        }
        combineHelper2(num, start+1, sum, target, answer, result);
    }

public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        /* https://oj.leetcode.com/problems/combination-sum-ii/
        * Each number in num may only be used once in the combination.
        * All numbers (including target) will be positive integers.
        * Elements in a combination (a1, a2, … , ak) must be in non-descending order. 
          (ie, a1 ≤ a2 ≤ … ≤ ak).
        * num may contain duplicate numbers.
        */
        
        vector<vector<int> > result;
        vector<int> answer;
        sort(num.begin(), num.end());
        
        combineHelper2(num, 0, 0, target, answer, result);
        
        return result;
    }
};