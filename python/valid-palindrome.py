class Solution:
    # @param s, a string
    # @return a boolean
    def isPalindrome(self, s):
        i = 0
        j = len(s) - 1
        s = s.lower()

        while i < j:
            while i < j and not self._isAlphaNum(s[i]):
                i += 1
            while i < j and not self._isAlphaNum(s[j]):
                j -= 1

            if s[i] != s[j]:
                return False

            i += 1
            j -= 1

        return True


    def _isAlphaNum(self, c):
        return (c >= 'a' and c <= 'z') or (c >= '0' and c <= '9')
