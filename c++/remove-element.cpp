//https://oj.leetcode.com/problems/remove-element/

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] != elem) A[k++] = A[i];
        }
        return k;
    }
};