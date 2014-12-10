// https://oj.leetcode.com/problems/find-peak-element/

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        // time complexity: log(n)
        // a variant of binary search
        
        int start = 0, end = num.size() - 1;
        
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (num[mid] > num[mid-1] && num[mid] > num[mid+1]) {
                return mid;
            }
            if (num[mid] < num[mid-1]) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        
        return num[start] > num[end] ? start : end;
    }
};