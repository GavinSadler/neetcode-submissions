"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        
        if not node:
            return None

        adjList = {}

        s = []

        s.append(node)

        while s:
            t = s.pop()

            if t.val in adjList:
                continue

            adjList[t.val] = []

            for n in t.neighbors:
                adjList[t.val].append(n.val)
                s.append(n)

        head = Node(node.val, [])

        nodesCreated = {node.val: head}

        s = [head]

        while s:
            t = s.pop()

            for v in adjList.pop(t.val):

                n = nodesCreated.get(v, None)

                if v in adjList and v not in nodesCreated:
                    n = Node(v, [])
                    s.append(n)
                    nodesCreated[v] = n

                t.neighbors.append(n)
        
        return head
