class Solution {
public:
    int maxProduct(int A[], int n) {
        /* https://oj.leetcode.com/problems/maximum-product-subarray/
        Different from "Maximum sum subarray".
        
        Bookkeeping the maximum abs(value) of positive/negative values endswith the current element.
        */
        
        if (n == 1) return A[0];
        // otherwise, the result must be larger or equal to zero;
        // no need to compare with the negative values. 
        
        int result = INT_MIN, pos = 0, neg = 0;

        for (int i = 0; i < n; i++) {
            if (A[i] == 0) {
                pos = neg = 0;
                if (result < 0) result = 0;
            }
            else if (A[i] > 0) {
                pos = pos > 0 ? pos * A[i] : A[i];
                neg = neg < 0 ? neg * A[i] : 0;
                if (pos > result) result = pos;
            }
            else {
                int t_neg = neg;
                neg = pos > 0 ? pos * A[i] : A[i];
                pos = t_neg < 0 ? t_neg * A[i] : 0;
                if (pos > 0 && pos > result) result = pos;
            }
        }
        
        return result;
        
    }
};
class Solution {
private:
	int getmin(int a, int b, int c) {
		int rs = a < b ? a : b;
		return rs < c ? rs : c;
	}
	int getmax(int a, int b, int c) {
		int rs = a < b ? b : a;
		return rs < c ? c : rs;
	}
public:
	int maxProduct(int A[], int n) {//要求O(n)时间， O(1)空间

		if (n == 0) return 0;

		//因为最优解只和前一个子问题有关， 因此完全没有必要存一个数组。
		int DPmin = A[0], DPmax = A[0];
		int rs = A[0];
		for (int i = 1; i<n; ++i) {
			int DPmintmp = getmin(A[i], A[i] * DPmax, A[i] * DPmin);
			int DPmaxtmp = getmax(A[i], A[i] * DPmax, A[i] * DPmin);

			DPmax = DPmaxtmp; DPmin = DPmintmp;
			rs = max(rs, DPmax);
		}
		return rs;
	}
};