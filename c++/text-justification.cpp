//https://oj.leetcode.com/problems/text-justification/

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> result;
        const int n = words.size();
        if (n == 0) return result;
        
        int start = 0, end = 0;
        while (start < n) {
            int len = 0;
            for (end = start; end < n && len + words[end].size() <= L; end++) {
                len += words[end].size() + 1;  // add a space
            }
            assert(end > start);
            len--;  // remove the last space
            string line = words[start++];
            
            if (start == end) {
                line.append(L - len, ' ');
            }
            else if (end == n) {
                while (start < end) {
                    line.push_back(' ');
                    line.append(words[start++]);
                }
                line.append(L - len, ' ');
            }
            else {
                int space = (L - len) / (end - start);
                int extra = start + (L - len) - (end - start) * space;
                while (start < extra) {
                    line.append(space+2, ' ');
                    line.append(words[start++]);
                }
                while (start < end) {
                    line.append(space+1, ' ');
                    line.append(words[start++]);
                }
            }
            
            result.push_back(line);
        }
        
        return result;
    }
};