# Definition for a undirected graph node
# class UndirectedGraphNode:
#     def __init__(self, x):
#         self.label = x
#         self.neighbors = []

class Solution:
    # @param node, a undirected graph node
    # @return a undirected graph node
    def cloneGraph(self, node):
        if not node:
            return None

        queue = collections.deque([node])
        mapper = {id(node) : UndirectedGraphNode(node.label)}

        while queue:
            nd = queue.popleft()
            copy = mapper[id(nd)]
            for nei in nd.neighbors:
                if id(nei) not in mapper:
                    mapper[id(nei)] = UndirectedGraphNode(nei.label)
                    queue.append(nei)
                copy.neighbors.append(mapper[id(nei)])

        return mapper[id(node)]
