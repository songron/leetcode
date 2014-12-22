class Solution:
    # @param    A       a list of integers
    # @param    elem    an integer, value need to be removed
    # @return an integer
    def removeElement(self, A, elem):
        i = 0
        for j in xrange(len(A)):
            if A[j] != elem:
                A[i] = A[j]
                i += 1

        return i
