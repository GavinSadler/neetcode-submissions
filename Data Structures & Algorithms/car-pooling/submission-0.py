class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        
        lastStop = max([t[2] for t in trips])

        diffArray = [0 for _ in range(lastStop + 1)]

        # trips = [(t[1], t[2], t[0]) for t in trips]

        for passengers, frm, to in trips:
            diffArray[frm] += passengers
            diffArray[to] -= passengers

        passengers = 0

        for c in diffArray:
            passengers += c

            if passengers > capacity:
                return False

        return True
