class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        prev_row = [1] * n

        for r in range(m - 2, -1, -1):
            cur_row = [0] * n
            cur_row[-1] = 1
            for c in range(n - 2, -1, -1):
                cur_row[c] = cur_row[c + 1] + prev_row[c]
            prev_row = cur_row
        return prev_row[0]