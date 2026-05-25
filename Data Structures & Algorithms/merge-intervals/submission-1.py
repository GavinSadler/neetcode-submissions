class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:

        sorted_intervals = sorted(intervals, key=lambda x: x[0])

        out = []

        current_run = sorted_intervals[0]

        for i in range(1, len(sorted_intervals)):
            if current_run[1] >= sorted_intervals[i][0]:
                current_run[1] = max(sorted_intervals[i][1], current_run[1])
            else:
                out.append(current_run)
                current_run = sorted_intervals[i]

        out.append(current_run)

        return out

