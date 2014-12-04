class Solution {
public:
    int search(int A[], int n, int target) {
        /* https://oj.leetcode.com/problems/search-in-rotated-sorted-array/
        */
        
        int start = 0, end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (A[mid] == target) return mid;
            
            if (A[mid] >= A[start]) {  // A[mid] lie on the left part
                if (target >= A[start] && target < A[mid]) {
                    end = mid - 1;
                }
                else {
                    start = mid + 1;
                }
            }
            else {
                if (target > A[mid] && target <= A[end]) {
                    start = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }
        }
        
        return -1;
    }
};