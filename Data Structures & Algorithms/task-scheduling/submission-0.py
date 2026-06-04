class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        
        freq = {}

        for t in tasks:
            freq[t] = freq.get(t, 0) + 1
        
        # print(freq)

        mh = [-freq[t] for t in freq]

        heapq.heapify(mh)

        q = []

        t = 0

        while mh or q:

            if mh:
                count = -heapq.heappop(mh)
                # print(count,  "taken out")

                count -= 1

                if count > 0:
                    q.append((count, t + n))
            
            if q:
                count, nt = q[0]
                if t >= nt:
                    q = q[1:]
                    # print(count, "putting back in")
                    heapq.heappush(mh, -count)

            t += 1
            
        
        return t

        # {'X': 2, 'Y': 2}
        # X -> Y -> idle -> X -> Y

        # {'A': 3, 'B': 1, 'C': 1}
        # A -> B -> C -> Idle -> A -> Idle -> Idle -> Idle -> A

