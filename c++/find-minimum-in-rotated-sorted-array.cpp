//https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int> &num) {
        if (num.empty()) {
            return 0;
        }

        int start = 0, end = num.size() - 1;

        while (start + 1 < end) {
            if (num[start] < num[end]) {
                return num[start];
            }

            int mid = start + (end - start) / 2;
            if (num[mid] > num[start]) {  // num[mid] located in the left-part
                start = mid + 1;
            }
            else {
                end = mid;
            }
        }

        return min(num[start], num[end]);
    }
};
