class Solution {
private:
    void generateLadders(string &start, string &end, unordered_map<string, vector<string> > &parents, 
        vector<string> &answer, vector<vector<string> > &result) {
        
        if (end == start) {
            reverse(answer.begin(), answer.end());
            result.push_back(answer);
            reverse(answer.begin(), answer.end());
            return;
        }
        
        for (int i = 0; i < parents[end].size(); i++) {
            answer.push_back(parents[end][i]);
            generateLadders(start, parents[end][i], parents, answer, result);
            answer.pop_back();
        }
    }

public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // https://oj.leetcode.com/problems/word-ladder-ii/
        vector<vector<string> > result;
        if (start == end) {
            result.push_back(vector<string>(1, start));
            return result;
        }
        
        unordered_map<string, vector<string> > parents;
        queue<string> q;
        q.push(start);
        dict.erase(start);
        dict.insert(end);
        bool found = false;
        
        while (!q.empty() && !found) {
            int count = q.size();
            unordered_set<string> tempDict;
            
            for (int i = 0; i < count; i++) {
                string word = q.front();
                q.pop();
                
                for (int j = 0; j < word.size(); j++) {
                    string temp = word;
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == word[j]) continue;
                        temp[j] = c;
                        if (dict.find(temp) == dict.end()) continue;
                        
                        parents[temp].push_back(word);
                        if (temp == end) {
                            found = true;
                        }
                        else if (tempDict.find(temp) == tempDict.end()) {
                            q.push(temp);
                            tempDict.insert(temp);
                        }
                    }
                }
            }
            
            unordered_set<string>::iterator it = tempDict.begin();
            while (it != tempDict.end()) {
                dict.erase(*it);
                ++it;
            }
        }
        
        vector<string> answer;
        answer.push_back(end);
        generateLadders(start, end, parents, answer, result);
        return result;
    }
};