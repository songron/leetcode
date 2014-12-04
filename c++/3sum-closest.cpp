class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        /* https://oj.leetcode.com/problems/3sum-closest/
        O(nlogn) + O(n^2) = O(n^2)
        */
        
        int result = 0, diff = INT_MAX;
        sort(num.begin(), num.end());
        const int n = num.size();
        
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1, k = n - 1; j < k; ) {
                int sum = num[i] + num[j] + num[k];
                int d = sum - target;
                if (d == 0) return target;
                if (d < 0) {
                    d = -d;
                    j++;
                }
                else {
                    k--;
                }
                if (d < diff) {
                    result = sum;
                    diff = d;
                }
            }
        }
        
        return result;
    }
};