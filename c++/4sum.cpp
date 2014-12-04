class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        /* https://oj.leetcode.com/problems/4sum/
        Find all unique quadruplets in the array which gives the sum of target.
        */
        
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        const int n = num.size();
        
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && num[i] == num[i-1]) continue;
            
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && num[j] == num[j-1]) continue;
                
                for (int k1 = j + 1, k2 = n - 1; k1 < k2; ) {
                    if (k1 > j + 1 && num[k1] == num[k1-1]) {
                        k1++;
                        continue;
                    }
                    if (k2 < n - 1 && num[k2] == num[k2+1]) {
                        k2--;
                        continue;
                    }
                    
                    int sum = num[i] + num[j] + num[k1] + num[k2];
                    if (sum == target) {
                        vector<int> answer({num[i], num[j], num[k1], num[k2]});
                        result.push_back(answer);
                        k1++;
                        k2--;
                    }
                    else if (sum < target) {
                        k1++;
                    }
                    else {
                        k2--;
                    }
                }
            }
        }
        
        return result;
    }
};