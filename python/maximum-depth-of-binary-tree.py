# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return an integer
    def maxDepth(self, root):
        if not root:
            return 0

        max_depth = 0
        cur = root
        depth = 0
        stack = []

        while cur:
            stack.append(cur)
            depth += 1
            if cur.left:
                cur = cur.left
            elif cur.right:
                cur = cur.right
            else:
                # meet a leaf node
                if depth > max_depth:
                    max_depth = depth

                while stack:
                    if stack[-1].right == cur or stack[-1].right is None:
                        cur = stack.pop()
                        depth -= 1
                    else:
                        cur = stack[-1].right
                        break

                if not stack:
                    break

        return max_depth
