class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // https://oj.leetcode.com/problems/word-ladder/
        // like BFS
        
        queue<string> q;
        q.push(start);
        dict.erase(start);
        dict.insert(end);
        int level = 0;
        
        while (!q.empty()) {
            ++level;
            int count = q.size();
            for (int i = 0; i < count; i++) {
                string word = q.front();
                q.pop();
                if (word == end) return level;
                
                for (int j = 0; j < word.size(); j++) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == word[j]) continue;
                        char tmp = word[j];
                        word[j] = c;
                        if (dict.find(word) != dict.end()) {
                            dict.erase(word);
                            q.push(word);
                        }
                        word[j] = tmp;
                    }
                }
            }
        }
        
        return 0;
    }
};