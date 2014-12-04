//https://oj.leetcode.com/problems/simplify-path/

class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty()) return string();
        
        vector<string> splits;
        const int n = path.size();
        int i = 0;
        
        while (i < n) {
            while (i < n && path[i] == '/') i++;
            if (i == n) break;
            
            string s;
            while (i < n && path[i] != '/') s.push_back(path[i++]);
            
            if (s == ".") continue;
            if (s == "..") {
                if (!splits.empty()) splits.pop_back();
            }
            else {
                splits.push_back(s);
            }
        }
        
        string result;
        if (path[0] == '/') result.push_back('/');
        if (splits.empty()) return result;
        
        result.append(splits[0]);
        for (int i = 1; i < splits.size(); i++) {
            result.push_back('/');
            result.append(splits[i]);
        }
        
        return result;
    }
};