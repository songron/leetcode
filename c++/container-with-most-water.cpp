//https://oj.leetcode.com/problems/container-with-most-water/

class Solution {
public:
	int maxArea(vector<int> &height) {
		int rs = 0;
		int n = height.size();
		for (int i = 0, j = n - 1; i<j;) {
			rs = max(rs, min(height[i], height[j]) * (j - i));
			if (height[i] < height[j]) ++i;
			else --j;
		}
		return rs;
	}
};