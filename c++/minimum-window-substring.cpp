class Solution {
public:
    string minWindow(string S, string T) {
        /* https://oj.leetcode.com/problems/minimum-window-substring/
        */
        
        if (T.empty() || S.empty()) return "";
        
        const int m = S.size(), n = T.size();
        int index = -1, winLen = INT_MAX;
        
        vector<int> counter(256, 0);
        for (int i = 0; i < n; i++) counter[T[i]]++;
        int remain = n, start = 0;
        
        for (int i = 0; i < m; i++) {
            if (--counter[S[i]] >= 0) {  // an effective char
                if (--remain == 0) {  // found a window, index i as the right boundary
                    // find the left boundary of the window
                    while (++counter[S[start]] <= 0) start++;
                    int len = i - start + 1;
                    if (len < winLen) {
                        index = start;
                        winLen = len;
                    }
                    remain++;
                    start++;  // cannot use start again
                }
            }
        }
        
        return index != -1 ? S.substr(index, winLen) : "";
    }
};