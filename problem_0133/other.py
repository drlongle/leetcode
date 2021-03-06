"""
# Definition for a Node.
class Node(object):
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution(object):
    def cloneGraph(self, node):
        def dfs(node):
            if node in map: return map[node]
            clone = Node(node.val, [])
            map[node] = clone
            for nei in node.neighbors:
                clone.neighbors.append(dfs(nei))
            return clone
        
        if node == None: return None
        map = defaultdict(Node) # Map OLD node to NEW node
        return dfs(node)
