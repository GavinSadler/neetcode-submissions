class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        
        visited = []

        def dfs(x, y, currentWord):

            if currentWord == word:
                return True

            if y >= len(board) or y < 0:
                return
            
            if x >= len(board[y]) or x < 0:
                return

            if [x, y] in visited:
                return

            visited.append([x, y])

            if dfs(x + 1, y, currentWord + board[y][x]):
                return True
        
            if dfs(x - 1, y, currentWord + board[y][x]):
                return True
        
            if dfs(x, y + 1, currentWord + board[y][x]):
                return True
        
            if dfs(x, y - 1, currentWord + board[y][x]):
                return True
        
            visited.pop()

        for y in range(0, len(board)):
            for x in range(0, len(board[y])):
                
                if dfs(x, y, ""):
                    return True
        
        return False