class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        /* https://oj.leetcode.com/problems/largest-rectangle-in-histogram/
        */
        
        // bookkeeping the indices, increasing in height
        // so we could know the left boundary of histogram
        stack<int> st;
        int result = 0;
        height.push_back(-1);
        
        for (int i = 0; i < height.size(); i++) {
            while (!st.empty() && height[st.top()] >= height[i]) {
                int j = st.top();
                st.pop();
                if (height[j] == height[i]) break;
                // index i is the right boundary of the histogram whose height is height[j]
                int w = st.empty() ? i : i - st.top() - 1;
                int hist = w * height[j];
                if (hist > result) result = hist;
            }
            st.push(i);
        }
        height.pop_back();
        
        return result;
    }
};