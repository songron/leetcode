class Solution {
public:
    bool isValid(string s) {
        /* https://oj.leetcode.com/problems/valid-parentheses/
        Valid parentheses:
            * brackets closed in the correct order: ()[]{}
            * invalid: [(]), )(, ()(
        */
        
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
                case '(':
                case '[':
                case '{': {
                    st.push(s[i]);
                    break;
                }
                case ')': {
                    if (st.empty() || st.top() != '(') return false;
                    st.pop();
                    break;
                }
                case ']': {
                    if (st.empty() || st.top() != '[') return false;
                    st.pop();
                    break;
                }
                case '}': {
                    if (st.empty() || st.top() != '{') return false;
                    st.pop();
                    break;
                }
                default: break;
            }
        }
        
        return st.empty();  // there cannot be extra left parentheses
    }
};