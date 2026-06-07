class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        
        count = [0] * 26
        
        for task in tasks:
            count[ord(task) - ord('A')] += 1
            
        count.sort()

        maxf = count[-1]
        maxgaps = maxf - 1
        idle = maxgaps * n

        for i in range(len(count) - 1):
            idle -= min(count[i], maxgaps)

        return max(0, idle) + len(tasks)