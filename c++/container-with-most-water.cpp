//https://oj.leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int> &height) {
        int result = 0;
        const int n = height.size();
        
        for (int i = 0, j = n - 1; i < n; ) {
            int v = 0;
            if (height[i] <= height[j]) {
                v = (j - i) * height[i];
                i++;
            }
            else {
                v = (j - i) * height[j];
                j--;
            }
            
            if (v > result) {
                result = v;
            }
        }
        
        return result;
    }
};