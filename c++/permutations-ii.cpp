class Solution {
private:
    void permuteUniqueHelper(vector<int> &num, int start, vector<vector<int> > &result) {
        if (start == num.size()) {
            result.push_back(num);
            return;
        }
        
        unordered_set<int> visited;
        for (int i = start; i < num.size(); i++) {
            if (visited.find(num[i]) != visited.end()) continue;
            
            visited.insert(num[i]);
            swap(num[i], num[start]);
            permuteUniqueHelper(num, start+1, result);
            swap(num[i], num[start]);
        }
    }
    
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        /* https://oj.leetcode.com/problems/permutations-ii/
        * contain duplicates
        */
        
        vector<vector<int> > result;
        permuteUniqueHelper(num, 0, result);
        return result;
    }
};