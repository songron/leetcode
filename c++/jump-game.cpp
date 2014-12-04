class Solution {
public:
    bool canJump(int A[], int n) {
        /* https://oj.leetcode.com/problems/jump-game/
        */
        
        if (n <= 1) return true;
        
        int start = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (i + A[i] >= start) start = i;
        }
        
        return start == 0;
    }
};