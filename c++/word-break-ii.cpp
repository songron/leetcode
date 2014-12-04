class Solution {
private:
    void breakHelper(string &s, int index, vector<vector<int> > &Br, vector<string> &answer, vector<string> &result) {
        if (index < 0) {
            string r(answer[answer.size()-1]);
            for (int i = answer.size() - 2; i >= 0; i--) {
                r.push_back(' ');
                r.append(answer[i]);
            }
            result.push_back(r);
            return;
        }
        
        for (int i = 0; i < Br[index].size(); i++) {
            int start = Br[index][i];
            answer.push_back(s.substr(start, index-start+1));
            breakHelper(s, start-1, Br, answer, result);
            answer.pop_back();
        }
    }
    
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        /* https://oj.leetcode.com/problems/word-break-ii/
        */
        
        vector<string> result;
        if (s.empty()) {
            result.push_back("");
            return result;
        }
        
        const int n = s.size();
        vector<vector<int> > Br(n, vector<int>());
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if (dict.find(s.substr(j, i-j+1)) != dict.end() && (j == 0 || !Br[j-1].empty())) {
                    Br[i].push_back(j);
                }
            }
        }
        
        vector<string> answer;
        breakHelper(s, n-1, Br, answer, result);
        return result;
    }
};