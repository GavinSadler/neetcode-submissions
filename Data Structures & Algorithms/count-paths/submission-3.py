class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        
        pr = [1 for _ in range(n)]

        for y in range(1, m):
            for x in range(1, n):
                pr[x] = pr[x] + pr[x - 1]
        
        return pr[-1]

        # 1 1 1 1  1 1 1
        # 1 2 3 4  5 6 7
        # 1 3 6 10