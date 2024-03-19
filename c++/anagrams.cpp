#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cctype>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        if (strs.empty() || strs.size() == 1) {
            return {};
        }

        unordered_map<string, vector<string>> dict;

        for (const string& str : strs) {
            string sorted_str = sortString(str);
            dict[sorted_str].push_back(str);
        }

        vector<string> result;
        for (const auto& pair : dict) {
            if (pair.second.size() > 1) {
                for (const string& s : pair.second) {
                    result.push_back(s);
                }
            }
        }

        return result;
    }

private:
    string sortString(const string& str) {
        string sorted_str;
        for (char c : str) {
            if (!isspace(c) && !ispunct(c)) {
                sorted_str += tolower(c);
            }
        }
        sort(sorted_str.begin(), sorted_str.end());
        return sorted_str;
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"Listen", "Silent", "The eyes", "They see", "abc", "cba", "xy", "yx", "ef"};
    vector<string> result = sol.anagrams(strs);
    
    cout << "Anagrams in the list are: ";
    for (const string& s : result) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
