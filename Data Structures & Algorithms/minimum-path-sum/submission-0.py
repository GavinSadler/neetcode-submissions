class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        
        h, w = len(grid), len(grid[0])

        for y in range(h):
            for x in range(w):
                if y > 0 or x > 0:
                    grid[y][x] += min(
                        grid[y - 1][x] if y > 0 else float('inf'),
                        grid[y][x - 1] if x > 0 else float('inf'),
                    )

        return grid[h - 1][w - 1]

        # 3 by 3 -> 5
        # 1 3 1
        # 1 5 1
        # 4 2 1
        
        # 0, 0
        # 0, 1    1, 0
        # 2, 0    1, 1    0, 2
        # 2, 1    1, 2
        # 2, 2

        # 3 by 2 -> 4
        # 1 2 3
        # 4 5 6

        # 0, 0
        # 0, 1  1, 0
        # 0, 2  1, 1
        # 1, 2

        # 5 by 3 -> 7
        # 1 2 3 x x
        # 4 5 6 x x
        # x x x x x

        # 5 x 5 -> 9
        # 1 2 3 x x
        # 4 5 6 x x
        # x x x x x
        # x x x x x
        # x x x x x
        
        # 5 x 6 -> 10
        # 1 2 3 x x x
        # 4 5 6 x x x
        # x x x x x x
        # x x x x x x
        # x x x x x x
        
        # 6 x 6 -> 11
        # 1 2 3 x x x
        # 4 5 6 x x x
        # x x x x x x
        # x x x x x x
        # x x x x x x
        # x x x x x x