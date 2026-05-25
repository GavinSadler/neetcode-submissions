class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums) - 1

        while l < r:

            m = l + (r - l) // 2
            nm = nums[m]

            if nm < target:
                l = m + 1
            elif nm > target:
                r = m - 1
            else:
                return m
        
        if nums[l] == target:
            return l
        
        return -1