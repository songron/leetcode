/* https://oj.leetcode.com/problems/minimum-path-sum/
* Move either down or right.
T = O(row_length * col_length)
Space = O(row_length);
*/
class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) {
		int m = grid.size();
		if (m == 0) return 0;
		int n = grid[0].size();

		int *row = new int[n];
		row[0] = grid[0][0];
		for (int i = 1; i<n; ++i) row[i] = row[i - 1] + grid[0][i];
		for (int i = 1; i<m; ++i) {
			row[0] += grid[i][0];
			for (int j = 1; j<n; ++j) {
				row[j] = min(row[j - 1], row[j]) + grid[i][j];
			}
		}
		int rs = row[n - 1];
		delete[] row;
		return rs;
	}
};