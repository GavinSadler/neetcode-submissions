class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        
        height = len(grid)
        width = len(grid[0])

        out = 0

        def dfs(sy, sx):
            s = [(sy, sx)]

            while len(s):

                y, x = s.pop()

                if x < 0 or y < 0 or x >= width or y >= height:
                    continue
                
                if grid[y][x] == 'x':
                    continue
                
                if grid[y][x] == '0':
                    grid[y][x] = 'x'
                    continue
                
                grid[y][x] = 'x'
                
                s.append((y + 1, x))
                s.append((y - 1, x))
                s.append((y, x + 1))
                s.append((y, x - 1))

        for y in range(len(grid)):
            for x in range(len(grid[0])):

                if grid[y][x] == 'x':
                    continue
                
                if grid[y][x] == '1':
                    out += 1
                    dfs(y, x)
                
                if grid[y][x] == '0':
                    grid[y][x] = 'x'
        

        return out

