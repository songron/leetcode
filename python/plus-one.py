class Solution:
    # @param digits, a list of integer digits
    # @return a list of integer digits
    def plusOne(self, digits):
        result = []

        carry = 1
        for d in digits[::-1]:
            x = d + carry
            result.append(x % 10)
            carry = x / 10

        if carry:
            result.append(carry)

        return result[::-1]
