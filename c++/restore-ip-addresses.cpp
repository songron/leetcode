class Solution {
private:
    void restoreHelper(string &s, int start, vector<string> &addr, vector<string> &result) {
        if (addr.size() == 4) {
            if (start == s.size()) {
                string ipstr(addr[0]);
                for (int i = 1; i < 4; i++) {
                    ipstr.push_back('.');
                    ipstr.append(addr[i]);
                }
                result.push_back(ipstr);
            }
            return ;
        }
        if (start == s.size()) return;
        
        for (int i = 0, v = 0; i < 3 && start + i < s.size(); i++) {
            v = v * 10 + s[start+i] - '0';
            if (v < 256) {
                addr.push_back(s.substr(start, i+1));
                restoreHelper(s, start+i+1, addr, result);
                addr.pop_back();
            }
            if (v == 0 || v > 255) break;
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        /* https://oj.leetcode.com/problems/restore-ip-addresses/
        */
        
        vector<string> result;
        vector<string> addr;
        restoreHelper(s, 0, addr, result);
        return result;
    }
};