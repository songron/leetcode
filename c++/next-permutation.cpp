//https://oj.leetcode.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        const int n = num.size();
        if (n <= 1) return;
        
        int pivot = n - 1;
        for ( ; pivot > 0 && num[pivot] <= num[pivot-1]; pivot--) ;
        
        if (pivot == 0) {
            reverse(num, 0, n-1);
            return;
        }
        
        pivot--;
        int t = n - 1;
        for ( ; num[t] <= num[pivot]; t--) ;
        
        swap(num[pivot], num[t]);
        reverse(num, pivot+1, n-1);
    }
    
    void reverse(vector<int> &num, int start, int end) {
        while (start < end) {
            swap(num[start], num[end]);
            start++;
            end--;
        }
    }
};