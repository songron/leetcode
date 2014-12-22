class Solution:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
        bit_counts = [0] * 32
        neg_count = 0

        for x in A:
            if x < 0:
                neg_count += 1
                x = -x
            for i in xrange(32):
                if (x >> i) & 1:
                    bit_counts[i] += 1

        result = 0
        for i, bc in enumerate(bit_counts):
            if bc % 3:
                result |= 1 << i

        if neg_count % 3:
            result = -result

        return result
