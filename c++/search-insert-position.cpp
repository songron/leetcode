class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        /* https://oj.leetcode.com/problems/search-insert-position/
        */
        
        int start = 0, end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (A[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        
        return start;
    }
};