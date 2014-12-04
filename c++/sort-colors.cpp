class Solution {
public:
    void sortColors(int A[], int n) {
        /* https://oj.leetcode.com/problems/sort-colors/
        Two pass sorting:
            1, divide 0s and (1,2)s
            2, divide 1s and 2s
        */
        assert(n > 0);
        
        int i = 0, j = n - 1;
        while (i < j) {
            while (i < j && A[i] == 0) i++;
            while (i < j && A[j] != 0) j--;
            if (i < j) {
                swap(A[i], A[j]);
                i++;
                j--;
            }
        }
        
        if (A[i] == 0) i++;
        j = n - 1;
        while (i < j) {
            while (i < j && A[i] == 1) i++;
            while (i < j && A[j] == 2) j--;
            if (i < j) {
                swap(A[i], A[j]);
                i++;
                j--;
            }
        }
    }
};