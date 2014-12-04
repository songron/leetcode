//https://oj.leetcode.com/problems/permutation-sequence/

class Solution {
public:
    string getPermutation(int n, int k) {
        int fac = 1;
        for (int i = 2; i <= n; i++) {
            fac *= i;
        }
        vector<bool> used(n, false);
        string s;
        
        for (int i = 0; i < n && k > 1; i++) {
            fac /= (n - i);
            int skip = (k - 1) / fac;
            k -= skip * fac;
            
            for (int j = 0; j < n; j++) {
                if (!used[j]) {
                    if (skip == 0) {
                        s.push_back(j + '1');
                        used[j] = true;
                        break ;
                    }
                    else {
                        skip--;
                    }
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                s.push_back(i + '1');
            }
        }
        
        return s;
    }
};