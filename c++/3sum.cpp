class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        /* https://oj.leetcode.com/problems/3sum/
        Find all unique triplets in the array which gives the sum of zero.
        */
        
        vector<vector<int> > result;
        const int n = num.size();
        sort(num.begin(), num.end());
        
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && num[i] == num[i-1]) continue;
            
            for (int j = i + 1, k = n - 1; j < k; ) {
                if (j > i + 1 && num[j] == num[j-1]) {
                    j++;
                    continue;
                }
                if (k < n - 1 && num[k] == num[k+1]) {
                    k--;
                    continue;
                }
                
                int sum = num[i] + num[j] + num[k];
                if (sum == 0) {
                    vector<int> answer({num[i], num[j], num[k]});
                    result.push_back(answer);
                    j++;
                    k--;
                }
                else if (sum < 0) {
                    j++;
                }
                else {
                    k--;
                }
            } 
        }
        
        return result;
    }
};