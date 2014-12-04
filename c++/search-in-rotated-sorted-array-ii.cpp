class Solution {
bool searchHelper(int A[], int start, int end, int target) {
    if (start > end) return false;
    
    int mid = start + (end - start) / 2;
    if (A[mid] == target) return true;
    
    if (A[mid] == A[start] && A[mid] == A[end]) {
        return searchHelper(A, start+1, mid-1, target) || searchHelper(A, mid+1, end-1, target);
    }
    
    if (A[mid] >= A[start]) {
        if (target >= A[start] && target < A[mid]) {
            return searchHelper(A, start, mid-1, target);
        }
        return searchHelper(A, mid+1, end, target);
    }
    else {
        if (target > A[mid] && target <= A[end]) {
            return searchHelper(A, mid+1, end, target);
        }
        return searchHelper(A, start, mid-1, target);
    }
}

public:
    bool search(int A[], int n, int target) {
        /* https://oj.leetcode.com/problems/search-in-rotated-sorted-array-ii/
        We cannot do better than linear search !
        */
        
        return searchHelper(A, 0, n-1, target);
    }
};