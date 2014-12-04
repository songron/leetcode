//https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

class Solution {
private:
    int findMinHelper(vector<int> &num, int start, int end) {
        if (start > end) {
            return INT_MAX;
        }
        if (start == end || num[start] < num[end]) {
            return num[start];
        }
        if (start + 1 == end) {
            return min(num[start], num[end]);
        }

        int mid = start + (end - start) / 2;

        if (num[mid] == num[start] && num[mid] == num[end]) {
            return min(findMinHelper(num, start, mid-1), findMinHelper(num, mid+1, end));
        }

        if (num[mid] > num[start] || num[mid] > num[end]) {  // num[mid] located in the left-part
            return findMinHelper(num, mid+1, end);
        }
        else {
            return findMinHelper(num, start, mid);
        }
    }

public:
    int findMin(vector<int> &num) {
        // the worst time complexity is O(n),
        // "worst" situations, e.g., [2,2,2,...,2,2,1,2,...,2,2,2]
        return findMinHelper(num, 0, num.size()-1);
    }
};
