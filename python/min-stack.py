class MinStack:
    def __init__(self):
        self._stack = []
        self._min_stack = []

    # @param x, an integer
    # @return an integer
    def push(self, x):
        if not self._min_stack or self._min_stack[-1] >= x:
            self._min_stack.append(x)
        self._stack.append(x)

    # @return nothing
    def pop(self):
        if not self._stack:
            return None
        if self._stack[-1] == self._min_stack[-1]:
            self._min_stack.pop()
        self._stack.pop()

    # @return an integer
    def top(self):
        if not self._stack:
            return None
        return self._stack[-1]

    # @return an integer
    def getMin(self):
        if not self._min_stack:
            return None
        return self._min_stack[-1]
