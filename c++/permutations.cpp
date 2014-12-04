class Solution {
private:
    void permuteHelper(vector<int> &num, int start, vector<vector<int> > &result) {
        if (start == num.size()) {
            result.push_back(num);
            return;
        }
        
        for (int i = start; i < num.size(); i++) {
            swap(num[i], num[start]);
            permuteHelper(num, start+1, result);
            swap(num[i], num[start]);
        }
    }

public:
    vector<vector<int> > permute(vector<int> &num) {
        /* https://oj.leetcode.com/problems/permutations/
		* no duplicates
        */
        
        vector<vector<int> > result;
        permuteHelper(num, 0, result);
        return result;
    }
};