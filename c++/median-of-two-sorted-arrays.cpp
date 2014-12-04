class Solution {
private:
    int findKth(int A[], int m, int B[], int n, int k) {
        if (m == 0) return B[k-1];
        if (n == 0) return A[k-1];
        if (k == 1) return min(A[0], B[0]);
        
        int i = min(k/2, m), j = min(k/2, n);
        if (A[i-1] < B[j-1]) {
            return findKth(A+i, m-i, B, n, k-i);
        }
        return findKth(A, m, B+j, n-j, k-j);
    }

public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        /* https://oj.leetcode.com/problems/median-of-two-sorted-arrays/
        Find the kth smallest element of two sorted array.
        */
        
        assert(m + n > 0);
        if ((m + n) % 2 == 1) {
            return (double)findKth(A, m, B, n, (m+n+1)/2);
        }
        return ((double)findKth(A, m, B, n, (m+n)/2) + (double)findKth(A, m, B, n, 1+(m+n)/2)) / 2;
    }
};