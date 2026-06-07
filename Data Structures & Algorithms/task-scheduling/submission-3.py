class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        
        freq = {}

        for t in tasks:
            freq[t] = freq.get(t, 0) + 1

        mh = list(freq.values())

        mh.sort()
        print(mh)

        # maxf = max(mh)
        maxf = mh[-1]

        gaps = maxf - 1
        idle = gaps * n

        for i in range(len(mh) - 1):
            idle -= min(gaps, mh[i])

        return max(0, idle) + len(tasks)

        # 2X 2Y
        # _ _ _ _
        #  t = 0, i = 4
        # X _ _ X
        #  t = 2, i = 2
        # X Y _ X Y
        #  t = 2, i = 2
