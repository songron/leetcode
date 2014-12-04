class Solution {
private:
    string intToStr(int n) {
        string s;
        while (n > 0) {
            s.push_back(n % 10 + '0');
            n /= 10;
        }
        reverse(s.begin(), s.end());
        return s;
    }

public:
    string countAndSay(int n) {
        /* https://oj.leetcode.com/problems/count-and-say/
        */
        
        if (n == 0) return "";
        
        string result = "1";
        for (int i = 1; i < n; i++) {
            string tmp;
            int j = 0;
            while (j < result.size()) {
                char c = result[j];
                int count = 0;
                while (j < result.size() && result[j] == c) {
                    count++;
                    j++;
                }
                tmp.append(intToStr(count));
                tmp.push_back(c);
            }
            result = tmp;
        }
        
        return result;
    }
};