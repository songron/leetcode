/* https://oj.leetcode.com/problems/maximum-subarray/
subarray containing at least one number
*/
class Solution {
public:
	int maxSubArray(int A[], int n) {
		if (n == 0) return 0;
		int rs = A[0];
		int dp = A[0];
		for (int i = 1; i<n; ++i) {
			dp = dp < 0 ? A[i] : dp + A[i];
			rs = max(dp, rs);
		}
		return rs;
	}
};
