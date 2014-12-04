class Solution {
public:
    int trap(int A[], int n) {
        /* https://oj.leetcode.com/problems/trapping-rain-water/
        */
        
        int result = 0;
        stack<int> st;  // bookkeeping indices, decreasing in height
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && A[st.top()] <= A[i]) {
                int j = st.top();
                st.pop();
                if (st.empty() || A[j] == A[i]) {  
                    // empty: no bar in the left;
                    // A[j] == A[i]: no need to record the same-height-bars
                    continue;
                }
                
                // A[j] as the bottom of the container, A[j] is the highest
                // between st.top() and i
                // A[st.top()] as the left bar, A[i] as the right bar
                int h = min(A[st.top()], A[i]) - A[j];
                int w = i - st.top() - 1;
                result += h * w;
            }
            st.push(i);
        }
        
        return result;
    }
};