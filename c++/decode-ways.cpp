class Solution {
public:
    int numDecodings(string s) {
        /* https://oj.leetcode.com/problems/decode-ways/
        'A' -> 1, 'B' -> 2, ..., 'Z' -> 26
        if (s[n] can be decoded and s[n-1..n] can be decoded):
            f(n) = f(n-1) + f(n-2);
        else if (s[n] can be decoded)
            f(n) = f(n-1);
        else if (s[n-1..n] can be decoded)
            f(n) = f(n-2)
        else
            f(n) = 0
        */
        
        const int n = s.size();
        if (n == 0 || s[0] == '0') return 0;
        
        int d1 = 1, d2 = 1;
        for (int i = 1; i < n; i++) {
            int d3 = 0;
            if (s[i] != '0') d3 += d2;
            int x = 10 * (s[i-1] - '0') + (s[i] - '0');
            if (x >= 10 && x <= 26) d3 += d1;
            
            if (d3 == 0) return 0;
            d1 = d2;
            d2 = d3;
        }
        
        return d2; 
    }
};