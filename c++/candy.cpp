//https://oj.leetcode.com/problems/candy/

class Solution {
public:
    int candy(vector<int> &ratings) {
        const int n = ratings.size();
        if (n <= 1) return n;
        
        int C[n];
        
        C[0] = 1;
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1]) C[i] = C[i-1] + 1;
            else C[i] = 1;
        }
        
        int result = C[n-1];
        
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) {
                C[i] = max(C[i], C[i+1] + 1);
            }
            result += C[i];
        }
        
        return result;
    }
};