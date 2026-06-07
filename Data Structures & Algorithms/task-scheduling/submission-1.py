class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        
        freq = {}

        for t in tasks:
            freq[t] = freq.get(t, 0) + 1

        mh = [-v for v in freq.values()]

        heapq.heapify(mh)

        task = -heapq.heappop(mh)
        firstTask = task
        t = task
        idle = (task - 1) * n

        while mh:
            task = -heapq.heappop(mh)
            t += task
            idle -= task
            if task == firstTask:
                idle += 1
        
        t += max(0, idle)

        return t

        # A -> 3
        # B -> 3

        # A _ _ A _ _ A
        # t = 3, idle = 4
        # A B _ A B _ A B
        # t = 6, idle = 2

        # A _ _ _ A _ _ _ A
        # t = 3, idle = 6
        # A B _ _ A _ _ _ A
        # t = 4, 
        # A B C _ A _ _ _ A