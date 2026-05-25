class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:

        for t in times:
            t[0] -= 1
            t[1] -= 1

        adjList = [[] for _ in range(n)]

        for t in times:
            adjList[t[0]].append((t[1], t[2]))
        
        visited = set()

        t = 0

        heap = [(0, k - 1)]

        while len(heap):
            
            distance, node = heapq.heappop(heap)

            if node in visited:
                continue
            
            visited.add(node)

            t = distance

            for neighbor, d in adjList[node]:
                heapq.heappush(heap, (distance + d, neighbor))

        if len(visited) != n:
            return -1

        return t
        