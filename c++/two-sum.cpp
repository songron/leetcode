class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // https://oj.leetcode.com/problems/two-sum/
        
        vector<int> result(2, 0);
        unordered_map<int, int> valToIndex;
        
        for (int i = 0; i < numbers.size(); i++) {
            int v = target - numbers[i];
            if (valToIndex.find(v) != valToIndex.end()) {
                result[0] = valToIndex[v] + 1;
                result[1] = i + 1;
                break;
            }
            valToIndex[numbers[i]] = i;
        }
        
        return result;
    }
};