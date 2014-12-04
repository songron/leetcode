class Solution {
private:
    void reverseSub(string &s, int start, int end) {
        while (start < end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }    
    }
    
public:
    void reverseWords(string &s) {
        /* A sequence of non-space characters constitutes a word.
        1. Delete leading and trailing spaces; Reduce multiple spaces to a single space.
        2. Reverse every single word when scanning. Then reverse the whole string.
        e.g., hello world -> olleh dlrow -> world hello
        */
        
        if (s.empty()) return;
        
        const int n = s.size();
        int k = 0, i = 0;
        while (i < n && s[i] == ' ') i++;
        
        while(i < n) {
            int start = k;
            while (i < n && s[i] != ' ') {
                s[k++] = s[i++];
            }
            
            if (k > start + 1) {
                reverseSub(s, start, k-1);
            }
            
            while (i < n && s[i] == ' ') i++;
            if (i < n) s[k++] = ' ';
        }
        
        if (k < n) {
            s.erase(s.begin()+k, s.end());
        }
        if (k > 1) {
            reverseSub(s, 0, k-1);
        }
    }
};