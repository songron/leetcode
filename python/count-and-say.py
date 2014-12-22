class Solution:
    # @return a string
    def countAndSay(self, n):
        result = '1'

        for i in xrange(n-1):
            stat = self._count(result)
            result = self._say(stat)

        return result

    def _count(self, s):
        stat = []
        n = 0
        now = None
        for c in s:
            if now is None:
                now = c
                n = 1
            elif c == now:
                n += 1
            else:
                stat.append((now, n))
                now = c
                n = 1

        stat.append((now, n))
        return stat

    def _say(self, stat):
        return ''.join([str(n)+c for c, n in stat])

