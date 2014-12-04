class Solution {
public:
    int sqrt(int x) {
        /* https://oj.leetcode.com/problems/sqrtx/
        */
        
        assert(x >= 0);
        if (x == 0) return 0;
        if (x < 4) return 1;
        
        const int MAX = 46340;  // 46341 * 46341 > 2^31
        int start = 2, end = x / 2;
        if (end > MAX) end = MAX;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int m = mid * mid;
            
            if (m == x) return mid;
            if (m < x) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        
        return end;
    }
};