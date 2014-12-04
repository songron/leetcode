//https://oj.leetcode.com/problems/substring-with-concatenation-of-all-words/

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        const int n = L.size();
        assert(n > 0);
        const int len = L[0].size();
        assert(len > 0);
        
        unordered_map<string, int> counter;
        for (int i = 0; i < n; i++) ++counter[L[i]];
        
        const int m = S.size();
        vector<int> result;
        unordered_map<string, int> appear;
        
        for (int i = 0; i < len; i++) {
            appear.clear();
            int start = i, count = 0;
            
            for (int j = i; j + len <= m; j += len) {
                string w = S.substr(j, len);
                if (counter.find(w) == counter.end()) {
                    appear.clear();
                    start = j + len;
                    count = 0;
                    continue;
                }
                if (++appear[w] <= counter[w]) {
                    ++count;
                    if (count == n) {
                        result.push_back(start);
                        --count;
                        --appear[S.substr(start, len)];
                        start += len;
                    }
                }
                else {
                    while (true) {
                        string _w = S.substr(start, len);
                        start += len;
                        if (_w == w) {
                            break;
                        }
                        --appear[_w];
                        --count;
                    }
                    --appear[w];
                }
            }
        }

        return result;
    }
};