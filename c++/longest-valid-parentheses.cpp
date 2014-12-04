class Solution {
public:
    int longestValidParentheses(string s) {
        /* https://oj.leetcode.com/problems/longest-valid-parentheses/
        (())()(()() : length is 6
        */
        
        stack<int> st; // bookkeeping the index of unmatched '('
        int result = 0, accu = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            else if (s[i] == ')') {
                if (st.empty()) {  // extra ')', start anew
                    accu = 0;
                }
                else {
                    int j = st.top();
                    st.pop();
                    if (st.empty()) { // no unmatched '(' in the left
                        accu += i - j + 1;
                        result = max(accu, result);
                    }
                    else {
                        // all the chars after st.top() have been matched
                        result = max(result, i - st.top());
                    }
                }
                
            }
            // else continue
        }
        
        return result;
    }
};