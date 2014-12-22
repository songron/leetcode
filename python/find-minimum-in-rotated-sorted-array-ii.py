class Solution:
    # @param num, a list of integer
    # @return an integer
    def findMin(self, num):
        return self._findMinHelper(num, 0, len(num)-1)

    def _findMinHelper(self, num, start, end):
        if start == end:
            return num[start]
        if start + 1 == end:
            return min(num[start], num[end])
        if num[start] < num[end]:
            return num[start]

        mid = start + (end - start) / 2
        if num[mid] > num[end]:
            return self._findMinHelper(num, mid+1, end)
        elif num[mid] < num[start]:
            return self._findMinHelper(num, start, mid)

        return min(self._findMinHelper(num, mid+1, end), self._findMinHelper(num, start, mid-1))
