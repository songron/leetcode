class Solution:
    # @param num, a list of integer
    # @return an integer
    def findMin(self, num):
        start = 0
        end = len(num) - 1

        while start + 1 < end:
            if num[start] < num[end]:
                return num[start]

            mid = start + (end - start) / 2
            if num[mid] > num[start]:
                start = mid + 1
            else:
                end = mid

        return min(num[start], num[end])
