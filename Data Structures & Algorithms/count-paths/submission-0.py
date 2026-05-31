class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        
        g = [[1 for _ in range(n)] for _ in range(m)]

        for y in range(1, m):
            for x in range(1, n):
                g[y][x] = g[y - 1][x] + g[y][x - 1]
        
        return g[-1][-1]

        # 1 1 1 1  1 1 1
        # 1 2 3 4  5 6 7
        # 1 3 6 10