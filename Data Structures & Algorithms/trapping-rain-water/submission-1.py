class Solution:
    def trap(self, height: List[int]) -> int:
        
        l, r = 0, len(height) - 1

        mh = min(height[l], height[r])

        w = 0

        while l < r:
            mh = max(mh, min(height[l], height[r]))

            if height[l] < height[r]:
                w += max(0, mh - height[l])
                l += 1
            else:
                w += max(0, mh - height[r])
                r -= 1

        return w