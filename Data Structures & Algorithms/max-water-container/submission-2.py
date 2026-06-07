class Solution:
    def maxArea(self, heights: List[int]) -> int:
        
        i = 0
        j = len(heights) - 1
        
        maxArea = (j - i) * min(heights[i], heights[j])

        while i < j:

            maxArea = max(maxArea, (j - i) * min(heights[i], heights[j]))

            if heights[i] < heights[j]:
                i += 1
            else:
                j -= 1
        
        return maxArea
