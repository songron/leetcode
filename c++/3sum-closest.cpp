class Solution {
public:
	/* https://oj.leetcode.com/problems/3sum-closest/
	O(nlogn) + O(n^2) = O(n^2)
	*/
	int threeSumClosest(vector<int> &num, int target) {
		int mini = INT_MAX;
		int rs = 0;
		sort(num.begin(), num.end());

		int n = num.size();
		for (int i = 0; i < n - 2; ++i)
		{
			for (int j = i + 1, k = n - 1; j < k;)
			{
				int now = num[i] + num[j] + num[k];
				int gap = abs(now - target);

				rs = gap < mini ? now : rs;  //×¢ÒâË³Ðò
				mini = gap < mini ? gap : mini;

				if (now > target) --k;
				else ++j;
			}
		}
		return rs;
	}
};